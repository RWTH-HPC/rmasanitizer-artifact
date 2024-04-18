from datetime import datetime
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import matplotlib.patches as mpatches
import matplotlib.lines as mlines

benchmark_name_map = {
    "PRK_stencil": "PRK Stencil -- weak (MPI RMA)\n{1000 iters, $48 \cdot 10^6$ elems per proc }",
    "BT-RMA": "NPB BT -- strong (MPI RMA)\n{Class D} (162 x 162 x 162)",
    "lulesh": "LULESH -- weak (MPI RMA)\n{$20^3$ problem size, 8000 elems per proc}",
    "miniMD": "miniMD -- weak (MPI RMA)\n{400 timesteps, LJ, 260000 atoms per proc}",
    "PRK_stencil_shmem": "PRK Stencil -- weak (SHMEM)\n{1000 iters, $48 \cdot 10^6$ elements per proc }",
    "BT-SHMEM": "NPB BT -- strong (SHMEM)\n{Class D (162 x 162 x 162)}",
    "CFD-Proxy": "CFD-Proxy - strong (GASPI)\n{4000 iters, F6 airplane mesh}"
}

benchmark_task_selector = {
    # "PRK_stencil": [48,192,768],
    "BT-RMA": [49,100,225,361,729],
    "BT-SHMEM": [49,100,225,361,729],
    "lulesh": [64,125,216,343,729],
    # "miniMD": [48,192,768],
    #"BT-SHMEM": [49,225,361]
}

benchmark_paths = {
    "PRK_stencil": "../evaluation_results/PRK_stencil/result/result_csv.dat",
    "BT-RMA": "../evaluation_results/BT-RMA/result/result_csv.dat",
    "lulesh": "../evaluation_results/lulesh/result/result_csv.dat",
    "miniMD": "../evaluation_results/miniMD/result/result_csv.dat",
    "PRK_stencil_shmem": "../evaluation_results/PRK_stencil_shmem/result/result_csv.dat",
    "BT-SHMEM": "../evaluation_results/BT-SHMEM/result/result_csv.dat",
    "CFD-Proxy": "../evaluation_results/CFD-Proxy/result/result_csv.dat",
}

plt.rc('pdf', fonttype=42)
plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif"
})

plt.rc('text.latex', preamble=r'\usepackage[italic]{mathastext}')

def read_csv(benchmark_name, csv_file) -> None:
    # Read csv
    df = pd.read_csv(csv_file, sep=";")
    # Drop columns which have no values
    df = df.dropna(axis=1, how='all')
    # Fill empty cells with empty string
    df = df.fillna('None')

    print(df)

    # Drop all columns except tasks, compile, measurement time_avg, time_std must_compile_opt
    df = df[['tasks', 'compile', 'measurement',
             'time_avg', 'time_std']]
    df['benchmark'] = benchmark_name

    # Calculate tool slowdown
    target_column = "time_avg"
    df["tool slowdown"] = [row[target_column]/df.loc[(df['compile'] == "base")
                                                     & (df['measurement'] == "base")
                                                     & (df['tasks'] == row['tasks'])][target_column].iloc[0] for index, row in df.iterrows()]
    
    df["time_std_rel"] = df["time_std"] / df["time_avg"]
    target_column = "time_std_rel"
    df["tool slowdown std rel"] = [row[target_column] + df.loc[(df['compile'] == "base")
                                                     & (df['measurement'] == "base")
                                                     & (df['tasks'] == row['tasks'])][target_column].iloc[0] for index, row in df.iterrows()]
    df["tool slowdown std"] = df["tool slowdown"] * df["tool slowdown std rel"]

    df_base = df[df['measurement'] == "base"].rename(columns={"time_avg": "base_avg", "time_std": "base_std", "time_std_rel": "base_std_rel"}).reset_index()
    df_rmasanitize = df[df['measurement'] == "must"].rename(columns={"time_avg": "rmasan_avg", "time_std": "rmasan_std", "time_std_rel": "rmasan_std_rel"}).reset_index()
    df = pd.concat([df_rmasanitize, df_base["base_avg"], df_base["base_std"], df_base["base_std_rel"]], axis=1)
    df = df[["benchmark", "tasks", "base_avg", "rmasan_avg", "tool slowdown", "base_std", "rmasan_std", "tool slowdown std", "base_std_rel",  "rmasan_std_rel", "tool slowdown std rel"]]
    print(df)

    return df


def create_plots(dfs) -> None:
    palette = ["#f0f0f0"]

    # sns.set_style("whitegrid", rc={
    #     "grid.linestyle": "solid", "grid.color": "white"})
    sns.set_theme(rc={"lines.linewidth": 0.8})
    plt.rc('axes', axisbelow=True)
    fig, axs = plt.subplots(ncols=4, nrows=2, figsize=(12, 3), constrained_layout=True)

    for ax, df in zip(axs.flat, dfs):
        benchmark = df["benchmark"][0]

        # Only take those rows with task numbers that we are interested in
        if benchmark in benchmark_task_selector:
            df = df[df['tasks'].isin(benchmark_task_selector[benchmark])]

        df['tasks'] = df['tasks'].astype(str)

        df.plot.bar(x='tasks', y='tool slowdown', color=palette, edgecolor="black", width=0.8, rot=0, ax=ax)
        ax2 = ax.twinx()

        ax.get_legend().remove()
        
        ax.set_title(benchmark_name_map[benchmark], fontsize=8)
        ax.set_xlabel("\# Processes", fontsize=8)
        ax.set_ylabel("Tool Slowdown", fontsize=8)
        ax.tick_params(axis='x', labelsize=7, pad=0)
        ax.tick_params(axis='y', labelsize=7, pad=0)
        ax.set_ymargin(0.35)
        ax.grid(False)
 
        # axis on the right side
        ax.spines["right"].set_visible(True)
        ax.yaxis.set_label_position('right')
        ax.yaxis.set_ticks_position('right')
        if benchmark != "CFD-Proxy":
            ax.set_ylim(0, 15)

        # Show values
        # for i in ax.containers:
        #      texts = ax.bar_label(i, fmt='%.2f', rotation=0, fontsize=7)
        #      for text in texts:
        #          text.set(y=2, zorder=1000)

        # ax2.set_zorder(10)
        ax2.set_ylabel("Runtime [s]", fontsize=8)
        df.plot(kind='line', x='tasks', y='rmasan_avg', color='blue', ax=ax2, style='.-')
        df.plot(kind='line', x='tasks', y='base_avg', color='red', ax=ax2, style='.-')

        
        # ================================
        # Prevent marker cutoff
        # =================================
        # get markersize in pixel
        markersize = ax2.get_children()[0].get_markersize()
        # transform pixel markersize to markersize based on the axis
        markersize_data = (ax2.transData.inverted().transform((1, 1)) - ax2.transData.inverted().transform((0, 0)))[1]*markersize
        # calculate ymargin at the bottom such that the marker are not cutoff
        ymargin_bottom = min(0, df['rmasan_avg'].min() - markersize_data, df['base_avg'].min() - markersize_data)
        ax2.set_ylim(bottom=0 + ymargin_bottom, top=df['rmasan_avg'].max()*1.1)
        ax2.get_legend().remove()

        # axis on the left side
        ax2.spines["left"].set_visible(True)
        ax2.yaxis.set_label_position('left')
        ax2.yaxis.set_ticks_position('left')
        ax2.set_axisbelow(True)
        ax2.tick_params(axis='x', labelsize=7, pad=0)
        ax2.tick_params(axis='y', labelsize=7, pad=0)
        
        # ================================
        # Background Grid
        # =================================
        # Z-order only works inside of an axis, but not across different axis 
        # Instead we create a new axis axBG, and use it as an empty axis for the background grid
        axBG=ax2.twinx()
        axBG.set_zorder(-10)  
        # remove the ticks and labels of the background axis
        axBG.tick_params(left=False, labelleft = False, right=False, labelright=False) 
        # Remove background of ax and ax2
        ax.patch.set_visible(False)
        ax2.patch.set_visible(False)
        # Turn on the background of axBG
        axBG.patch.set_visible(True)
        #Remove grids of ax and ax2
        ax.grid(False)
        ax2.grid(False)
        
        #Set ticks and limits of the background axis to the respective values of axis ax2  
        axBG.set_ylim(ax2.get_ylim())   
        # only show ticks that are in the limits and are larger than 0
        axBG.set_yticks([i for i in ax2.get_yticks().tolist() if i >= 0 and i <= axBG.get_ylim()[1]])
        ax2.set_yticks(axBG.get_yticks())
        
        #Use Locators to set the ticks of axBG and ax2 such that they are the same and the grid of axBG aligns with ax2
        nticks = 3
        axBG.yaxis.set_major_locator(mticker.MaxNLocator(nbins=nticks, min_n_ticks=3, steps=[1, 2.5, 5, 10]))
        ax2.yaxis.set_major_locator(mticker.MaxNLocator(nbins=nticks, min_n_ticks=3, steps=[1, 2.5, 5, 10])) 
        
        # ================================
        # Bar labels
        # =================================
        # Create a new axis for bar labels
        ax_text = ax.twinx()
        ax_text.set_zorder(9000000)  
        # Remove background of ax_text
        ax_text.patch.set_visible(False)
        #Remove grids of ax_text
        ax_text.grid(False)        
        # remove the ticks and labels of ax_text
        ax_text.tick_params(left=False, labelleft = False, right=False, labelright=False) 
        # Set the limits of the twin axis to be the same as the original axis
        ax_text.set_ylim(ax.get_ylim())
        # Plot text on the twin axis
        for bar in ax.containers[0]:
            height = bar.get_height()
            ax_text.text(bar.get_x() + bar.get_width() / 2., height + 1, '%.2f' % height, ha='center', fontsize=7)

        # Set axis ax back on the right side
        ax.spines["right"].set_visible(True)
        ax.yaxis.set_label_position('right')
        ax.yaxis.set_ticks_position('right')
        
        # avoid rendering issues of ytick labels
        ax.yaxis.get_major_formatter()._usetex = False
        ax2.yaxis.get_major_formatter()._usetex = False

    # deactivate the last plot
    axs[1,3].axis('off')

    # legend
    blue_line = mlines.Line2D([], [], color='red', marker='.', markersize=8, label="Runtime without tool (baseline)")
    red_line = mlines.Line2D([], [], color='blue', marker='.', markersize=8, label="Runtime with RMASanitizer")
    gray_patch = mpatches.Patch(color='#f0f0f0', label='Tool Slowdown')
    legend = fig.legend(handles=[blue_line, red_line, gray_patch], title="Legend", loc=(0.79,0.15), fontsize=9)
    legend.get_title().set_fontsize(11)

    plt.yticks(fontname="Helvetica")

    fig.savefig(f"performance_results.png", bbox_inches='tight')
    fig.savefig(f"performance_results.pdf", bbox_inches='tight')

if __name__ == "__main__":
    dfs = []
    for (benchmark, path) in benchmark_paths.items():
        dfs.append(read_csv(benchmark, path))
    create_plots(dfs)
