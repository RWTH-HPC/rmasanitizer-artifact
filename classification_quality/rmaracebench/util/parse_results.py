# Part of RMARaceBench, under BSD-3-Clause License
# See https://github.com/RWTH-HPC/RMARaceBench/LICENSE for license information.
# SPDX-License-Identifier: BSD-3-Clause

import pandas
import argparse

parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('results_file', metavar='results_file',
                    help='Results from test runs in CSV format')
parser.add_argument('-o', dest='output_file',
                    help='Results from test runs in CSV format')
parser.add_argument('--verbose', dest='verbose', action='store_true')
parser.add_argument('--total-only', dest='total_only', action='store_true')

def guarded_div(dividend, divisor):
    if divisor == 0:
        return 0
    else:
        return dividend / divisor

def get_tool_statistics(data, tool):
    if len(data) == 0:
        return
    results = data.value_counts().to_dict()
    #print(results)

    tp = results['TP'] if 'TP' in results else 0
    fp = results['FP'] if 'FP' in results else 0
    tn = results['TN'] if 'TN' in results else 0
    fn = results['FN'] if 'FN' in results else 0
    to = results['TO'] if 'TO' in results else 0

    total = tp + fp + tn + fn
    p = tp + fn
    n = fp + tn

    precision = guarded_div(tp, (tp + fp))
    recall = guarded_div(tp, (tp + fn))
    specificity = guarded_div(tn, n)
    accuracy = guarded_div((tp + tn), total)

    out = {
        (tool, 'TP'): tp,
        (tool, 'TN'): tn,
        (tool, 'FP'): fp,
        (tool, 'FN'): fn,
        (tool, 'TO'): to,
        (tool, 'P'): precision,
        (tool, 'R'): recall,
        (tool, 'A'): accuracy
    }

    return out

def get_derived_metrics(data, tool):
    if len(data) == 0:
        return
    results = data.value_counts().to_dict()
    #print(results)
    #print(results)
    #print(data)
    tp = results['TP'] if 'TP' in results else 0
    fp = results['FP'] if 'FP' in results else 0
    tn = results['TN'] if 'TN' in results else 0
    fn = results['FN'] if 'FN' in results else 0
    to = results['TO'] if 'TO' in results else 0

    total = tp + fp + tn + fn
    p = tp + fn
    n = fp + tn

    precision = guarded_div(tp, (tp + fp))
    recall = guarded_div(tp, (tp + fn))
    specificity = guarded_div(tn, n)
    accuracy = guarded_div((tp + tn), total)

    out = {
       'Precision': precision,
       'Recall': recall,
       'Accuracy': accuracy
    }

    return out

def get_tool_table(df, tool):
    return pandas.DataFrame.from_dict({
            'Conflict': get_tool_statistics(df.loc[df['discipline'] == "conflict"][tool], tool),
            'Sync': get_tool_statistics(df.loc[df['discipline'] == "sync"][tool], tool),
            'Atomic': get_tool_statistics(df.loc[df['discipline'] == "atomic"][tool], tool),
            'Hybrid': get_tool_statistics(df.loc[df['discipline'] == "hybrid"][tool], tool),
            'Total': get_tool_statistics(df[tool], tool),
            },
            orient='index')

def get_discipline_statistics(df):
    return pandas.concat([get_tool_table(df, tool) for tool in tools], axis=1)

def get_statistics(df):
    return pandas.DataFrame([get_tool_statistics(df[tool], tool) for tool in tools])


args = parser.parse_args()

df = pandas.read_csv(args.results_file, index_col=0)

# extract tools from columns (first column is discipline)
tools = df.columns.to_list()[1:]

if args.verbose:
    print(df.to_string())
    print(
        pandas.DataFrame.from_dict({tool : get_derived_metrics(df[tool], tool) for tool in tools} ,orient='index').to_string(float_format="%.3f")
    )

if not args.total_only:
    print(get_discipline_statistics(df).to_string(float_format="%.2f"))
else:
    # fixed order of tools
    tool_order = ['PARCOACH-static', 'PARCOACH-dynamic', 'MUST-RMA', 'RMASanitizer']
    print(pandas.concat(
        [get_tool_table(df, tool).loc[['Total']].droplevel(0, axis=1).rename(index={'Total': tool}) for tool in tool_order if tool in tools]).to_string(float_format="%.2f"))

# LaTeX tables
# with pandas.option_context("max_colwidth", 1000):
#     print(df.drop(columns=['discipline']).to_latex(index_names=False))
#     print(get_discipline_statistics(df).to_latex(float_format="%.2f"))