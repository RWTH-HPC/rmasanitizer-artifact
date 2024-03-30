; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/hybrid/015-MPI-hybrid-task-remote-yes.c'
source_filename = "results-20240330-164421/PARCOACH-dynamic/hybrid/015-MPI-hybrid-task-remote-yes.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ompi_predefined_datatype_t = type opaque
%struct.ident_t = type { i32, i32, i32, i32, ptr }
%struct.anon = type { ptr }
%struct.kmp_task_t_with_privates = type { %struct.kmp_task_t }
%struct.kmp_task_t = type { ptr, ptr, i32, %union.kmp_cmplrdata_t, %union.kmp_cmplrdata_t }
%union.kmp_cmplrdata_t = type { ptr }

@.str = private unnamed_addr constant [35 x i8] c"MPI_THREAD_MULTIPLE not supported\0A\00", align 1, !dbg !0
@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str.1 = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !7
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@0 = private unnamed_addr constant [94 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/015-MPI-hybrid-task-remote-yes.c;main;93;1;;\00", align 1
@1 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 93, ptr @0 }, align 8
@2 = private unnamed_addr constant [94 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/015-MPI-hybrid-task-remote-yes.c;main;95;1;;\00", align 1
@3 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 93, ptr @2 }, align 8
@.str.2 = private unnamed_addr constant [19 x i8] c"win_base[0] is %d\0A\00", align 1, !dbg !12
@4 = private unnamed_addr constant %struct.ident_t { i32 0, i32 322, i32 0, i32 93, ptr @0 }, align 8
@5 = private unnamed_addr constant [95 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/015-MPI-hybrid-task-remote-yes.c;main;91;22;;\00", align 1
@6 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 94, ptr @5 }, align 8
@7 = private unnamed_addr constant [94 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/015-MPI-hybrid-task-remote-yes.c;main;91;1;;\00", align 1
@8 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 93, ptr @7 }, align 8
@.str.4 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !17

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @my_signal(ptr noundef %0) #0 !dbg !53 {
  %2 = alloca ptr, align 8
  store ptr %0, ptr %2, align 8
  call void @llvm.dbg.declare(metadata ptr %2, metadata !59, metadata !DIExpression()), !dbg !60
  %3 = load ptr, ptr %2, align 8, !dbg !61
  %4 = atomicrmw add ptr %3, i32 1 monotonic, align 4, !dbg !63
  ret void, !dbg !64
}

; Function Attrs: nocallback nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @my_wait(ptr noundef %0, i32 noundef %1) #0 !dbg !65 {
  %3 = alloca ptr, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store ptr %0, ptr %3, align 8
  call void @llvm.dbg.declare(metadata ptr %3, metadata !68, metadata !DIExpression()), !dbg !69
  store i32 %1, ptr %4, align 4
  call void @llvm.dbg.declare(metadata ptr %4, metadata !70, metadata !DIExpression()), !dbg !71
  call void @llvm.dbg.declare(metadata ptr %5, metadata !72, metadata !DIExpression()), !dbg !73
  store i32 0, ptr %5, align 4, !dbg !73
  br label %6, !dbg !74

6:                                                ; preds = %10, %2
  %7 = call i32 @usleep(i32 noundef 10), !dbg !75
  %8 = load ptr, ptr %3, align 8, !dbg !77
  %9 = load atomic i32, ptr %8 monotonic, align 4, !dbg !79
  store i32 %9, ptr %5, align 4, !dbg !79
  br label %10, !dbg !80

10:                                               ; preds = %6
  %11 = load i32, ptr %5, align 4, !dbg !81
  %12 = load i32, ptr %4, align 4, !dbg !82
  %13 = icmp slt i32 %11, %12, !dbg !83
  br i1 %13, label %6, label %14, !dbg !80, !llvm.loop !84

14:                                               ; preds = %10
  ret void, !dbg !87
}

declare i32 @usleep(i32 noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !88 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca ptr, align 8
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  %9 = alloca ptr, align 8
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  %16 = alloca i32, align 4
  %17 = call i32 @__kmpc_global_thread_num(ptr @6)
  store i32 0, ptr %3, align 4
  store i32 %0, ptr %4, align 4
  call void @llvm.dbg.declare(metadata ptr %4, metadata !93, metadata !DIExpression()), !dbg !94
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !95, metadata !DIExpression()), !dbg !96
  call void @llvm.dbg.declare(metadata ptr %6, metadata !97, metadata !DIExpression()), !dbg !98
  call void @llvm.dbg.declare(metadata ptr %7, metadata !99, metadata !DIExpression()), !dbg !100
  call void @llvm.dbg.declare(metadata ptr %8, metadata !101, metadata !DIExpression()), !dbg !105
  call void @llvm.dbg.declare(metadata ptr %9, metadata !106, metadata !DIExpression()), !dbg !107
  call void @llvm.dbg.declare(metadata ptr %10, metadata !108, metadata !DIExpression()), !dbg !109
  store i32 1, ptr %10, align 4, !dbg !109
  call void @llvm.dbg.declare(metadata ptr %11, metadata !110, metadata !DIExpression()), !dbg !111
  store i32 2, ptr %11, align 4, !dbg !111
  call void @llvm.dbg.declare(metadata ptr %12, metadata !112, metadata !DIExpression()), !dbg !113
  call void @llvm.dbg.declare(metadata ptr %13, metadata !114, metadata !DIExpression()), !dbg !115
  store i32 42, ptr %13, align 4, !dbg !115
  call void @llvm.dbg.declare(metadata ptr %14, metadata !116, metadata !DIExpression()), !dbg !117
  %18 = call i32 @MPI_Init_thread(ptr noundef %4, ptr noundef %5, i32 noundef 3, ptr noundef %14), !dbg !118
  %19 = load i32, ptr %14, align 4, !dbg !119
  %20 = icmp slt i32 %19, 3, !dbg !121
  br i1 %20, label %21, label %24, !dbg !122

21:                                               ; preds = %2
  %22 = call i32 (ptr, ...) @printf(ptr noundef @.str), !dbg !123
  %23 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !125
  br label %24, !dbg !126

24:                                               ; preds = %21, %2
  %25 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !127
  %26 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !128
  %27 = load i32, ptr %7, align 4, !dbg !129
  %28 = icmp ne i32 %27, 2, !dbg !131
  br i1 %28, label %29, label %33, !dbg !132

29:                                               ; preds = %24
  %30 = load i32, ptr %7, align 4, !dbg !133
  %31 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %30, i32 noundef 2), !dbg !135
  %32 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !136
  br label %33, !dbg !137

33:                                               ; preds = %29, %24
  %34 = call i32 @MPI_Win_allocate(i64 noundef 40, i32 noundef 4, ptr noundef @ompi_mpi_info_null, ptr noundef @ompi_mpi_comm_world, ptr noundef %9, ptr noundef %8), !dbg !138
  call void @llvm.dbg.declare(metadata ptr %15, metadata !139, metadata !DIExpression()), !dbg !141
  store i32 0, ptr %15, align 4, !dbg !141
  br label %35, !dbg !142

35:                                               ; preds = %43, %33
  %36 = load i32, ptr %15, align 4, !dbg !143
  %37 = icmp slt i32 %36, 10, !dbg !145
  br i1 %37, label %38, label %46, !dbg !146

38:                                               ; preds = %35
  %39 = load ptr, ptr %9, align 8, !dbg !147
  %40 = load i32, ptr %15, align 4, !dbg !149
  %41 = sext i32 %40 to i64, !dbg !147
  %42 = getelementptr inbounds i32, ptr %39, i64 %41, !dbg !147
  store i32 0, ptr %42, align 4, !dbg !150
  br label %43, !dbg !151

43:                                               ; preds = %38
  %44 = load i32, ptr %15, align 4, !dbg !152
  %45 = add nsw i32 %44, 1, !dbg !152
  store i32 %45, ptr %15, align 4, !dbg !152
  br label %35, !dbg !153, !llvm.loop !154

46:                                               ; preds = %35
  %47 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !156
  %48 = load i32, ptr %6, align 4, !dbg !157
  %49 = icmp eq i32 %48, 0, !dbg !159
  br i1 %49, label %50, label %58, !dbg !160

50:                                               ; preds = %46
  %51 = load ptr, ptr %8, align 8, !dbg !161
  %52 = call i32 @MPI_Win_lock(i32 noundef 1, i32 noundef 1, i32 noundef 0, ptr noundef %51), !dbg !163
  store i32 42, ptr %10, align 4, !dbg !164
  %53 = load ptr, ptr %8, align 8, !dbg !165
  %54 = call i32 @MPI_Put(ptr noundef %10, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 1, i64 noundef 0, i32 noundef 1, ptr noundef @ompi_mpi_int, ptr noundef %53), !dbg !166
  %55 = load ptr, ptr %8, align 8, !dbg !167
  %56 = call i32 @MPI_Win_unlock(i32 noundef 1, ptr noundef %55), !dbg !168
  %57 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !169
  br label %58, !dbg !170

58:                                               ; preds = %50, %46
  %59 = load i32, ptr %6, align 4, !dbg !171
  %60 = icmp eq i32 %59, 1, !dbg !173
  br i1 %60, label %61, label %62, !dbg !174

61:                                               ; preds = %58
  call void @llvm.dbg.declare(metadata ptr %16, metadata !175, metadata !DIExpression()), !dbg !177
  store i32 0, ptr %16, align 4, !dbg !177
  call void @__kmpc_push_num_threads(ptr @6, i32 %17, i32 2), !dbg !178
  call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @8, i32 2, ptr @.omp_outlined..3, ptr %16, ptr %9), !dbg !178
  br label %62, !dbg !179

62:                                               ; preds = %61, %58
  %63 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !180
  %64 = load i32, ptr %6, align 4, !dbg !181
  %65 = load i32, ptr %10, align 4, !dbg !182
  %66 = load i32, ptr %11, align 4, !dbg !183
  %67 = load ptr, ptr %9, align 8, !dbg !184
  %68 = getelementptr inbounds i32, ptr %67, i64 0, !dbg !184
  %69 = load i32, ptr %68, align 4, !dbg !184
  %70 = call i32 (ptr, ...) @printf(ptr noundef @.str.4, i32 noundef %64, i32 noundef %65, i32 noundef %66, i32 noundef %69), !dbg !185
  %71 = call i32 @MPI_Win_free(ptr noundef %8), !dbg !186
  %72 = call i32 @MPI_Finalize(), !dbg !187
  ret i32 0, !dbg !188
}

declare i32 @MPI_Init_thread(ptr noundef, ptr noundef, i32 noundef, ptr noundef) #2

declare i32 @printf(ptr noundef, ...) #2

declare i32 @MPI_Abort(ptr noundef, i32 noundef) #2

declare i32 @MPI_Comm_rank(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_size(ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_allocate(i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Barrier(ptr noundef) #2

declare i32 @MPI_Win_lock(i32 noundef, i32 noundef, i32 noundef, ptr noundef) #2

declare i32 @MPI_Put(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_unlock(i32 noundef, ptr noundef) #2

; Function Attrs: noinline norecurse nounwind optnone uwtable
define internal void @.omp_outlined._debug__(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 4 dereferenceable(4) %2, ptr noundef nonnull align 8 dereferenceable(8) %3) #3 !dbg !189 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  %9 = alloca %struct.anon, align 8
  store ptr %0, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !198, metadata !DIExpression()), !dbg !199
  store ptr %1, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !200, metadata !DIExpression()), !dbg !199
  store ptr %2, ptr %7, align 8
  call void @llvm.dbg.declare(metadata ptr %7, metadata !201, metadata !DIExpression()), !dbg !202
  store ptr %3, ptr %8, align 8
  call void @llvm.dbg.declare(metadata ptr %8, metadata !203, metadata !DIExpression()), !dbg !204
  %10 = load ptr, ptr %7, align 8, !dbg !205
  %11 = load ptr, ptr %8, align 8, !dbg !205
  %12 = load ptr, ptr %5, align 8, !dbg !206
  %13 = load i32, ptr %12, align 4, !dbg !206
  %14 = call i32 @__kmpc_single(ptr @1, i32 %13), !dbg !206
  %15 = icmp ne i32 %14, 0, !dbg !206
  br i1 %15, label %16, label %27, !dbg !206

16:                                               ; preds = %4
  %17 = getelementptr inbounds %struct.anon, ptr %9, i32 0, i32 0, !dbg !208
  store ptr %10, ptr %17, align 8, !dbg !208
  %18 = call ptr @__kmpc_omp_task_alloc(ptr @3, i32 %13, i32 1, i64 40, i64 8, ptr @.omp_task_entry.), !dbg !208
  %19 = getelementptr inbounds %struct.kmp_task_t_with_privates, ptr %18, i32 0, i32 0, !dbg !208
  %20 = getelementptr inbounds %struct.kmp_task_t, ptr %19, i32 0, i32 0, !dbg !208
  %21 = load ptr, ptr %20, align 8, !dbg !208
  call void @llvm.memcpy.p0.p0.i64(ptr align 8 %21, ptr align 8 %9, i64 8, i1 false), !dbg !208
  %22 = call i32 @__kmpc_omp_task(ptr @3, i32 %13, ptr %18), !dbg !208
  call void @my_wait(ptr noundef %10, i32 noundef 1), !dbg !211
  %23 = load ptr, ptr %11, align 8, !dbg !212
  %24 = getelementptr inbounds i32, ptr %23, i64 0, !dbg !212
  %25 = load i32, ptr %24, align 4, !dbg !212
  %26 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %25), !dbg !213
  call void @__kmpc_end_single(ptr @1, i32 %13), !dbg !214
  br label %27, !dbg !214

27:                                               ; preds = %16, %4
  call void @__kmpc_barrier(ptr @4, i32 %13), !dbg !215
  ret void, !dbg !216
}

; Function Attrs: convergent nounwind
declare i32 @__kmpc_single(ptr, i32) #4

; Function Attrs: convergent nounwind
declare void @__kmpc_end_single(ptr, i32) #4

; Function Attrs: noinline norecurse nounwind uwtable
define internal i32 @.omp_task_entry.(i32 noundef %0, ptr noalias noundef %1) #5 !dbg !217 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  %9 = alloca i32, align 4
  %10 = alloca ptr, align 8
  store i32 %0, ptr %9, align 4
  call void @llvm.dbg.declare(metadata ptr %9, metadata !219, metadata !DIExpression()), !dbg !220
  store ptr %1, ptr %10, align 8
  call void @llvm.dbg.declare(metadata ptr %10, metadata !221, metadata !DIExpression()), !dbg !220
  %11 = load i32, ptr %9, align 4, !dbg !233
  %12 = load ptr, ptr %10, align 8, !dbg !233
  %13 = getelementptr inbounds %struct.kmp_task_t_with_privates, ptr %12, i32 0, i32 0, !dbg !233
  %14 = getelementptr inbounds %struct.kmp_task_t, ptr %13, i32 0, i32 2, !dbg !233
  %15 = getelementptr inbounds %struct.kmp_task_t, ptr %13, i32 0, i32 0, !dbg !233
  %16 = load ptr, ptr %15, align 8, !dbg !233
  call void @llvm.experimental.noalias.scope.decl(metadata !234), !dbg !233
  call void @llvm.experimental.noalias.scope.decl(metadata !237), !dbg !233
  call void @llvm.experimental.noalias.scope.decl(metadata !239), !dbg !233
  call void @llvm.experimental.noalias.scope.decl(metadata !241), !dbg !233
  store i32 %11, ptr %3, align 4, !noalias !243
  call void @llvm.dbg.declare(metadata ptr %3, metadata !244, metadata !DIExpression()), !dbg !260
  store ptr %14, ptr %4, align 8, !noalias !243
  call void @llvm.dbg.declare(metadata ptr %4, metadata !262, metadata !DIExpression()), !dbg !260
  store ptr null, ptr %5, align 8, !noalias !243
  call void @llvm.dbg.declare(metadata ptr %5, metadata !263, metadata !DIExpression()), !dbg !260
  store ptr null, ptr %6, align 8, !noalias !243
  call void @llvm.dbg.declare(metadata ptr %6, metadata !264, metadata !DIExpression()), !dbg !260
  store ptr %12, ptr %7, align 8, !noalias !243
  call void @llvm.dbg.declare(metadata ptr %7, metadata !265, metadata !DIExpression()), !dbg !260
  store ptr %16, ptr %8, align 8, !noalias !243
  call void @llvm.dbg.declare(metadata ptr %8, metadata !266, metadata !DIExpression()), !dbg !260
  %17 = load ptr, ptr %8, align 8, !dbg !267, !noalias !243
  call void @llvm.dbg.declare(metadata ptr %17, metadata !269, metadata !DIExpression(DW_OP_deref)), !dbg !270
  %18 = load ptr, ptr %17, align 8, !dbg !271
  call void @my_signal(ptr noundef %18), !dbg !273
  %19 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world) #6, !dbg !274
  ret i32 0, !dbg !233
}

; Function Attrs: nounwind
declare ptr @__kmpc_omp_task_alloc(ptr, i32, i32, i64, i64, ptr) #6

; Function Attrs: argmemonly nocallback nofree nounwind willreturn
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #7

; Function Attrs: nounwind
declare i32 @__kmpc_omp_task(ptr, i32, ptr) #6

; Function Attrs: convergent nounwind
declare void @__kmpc_barrier(ptr, i32) #4

; Function Attrs: noinline norecurse nounwind optnone uwtable
define internal void @.omp_outlined..3(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 4 dereferenceable(4) %2, ptr noundef nonnull align 8 dereferenceable(8) %3) #3 !dbg !275 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !276, metadata !DIExpression()), !dbg !277
  store ptr %1, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !278, metadata !DIExpression()), !dbg !277
  store ptr %2, ptr %7, align 8
  call void @llvm.dbg.declare(metadata ptr %7, metadata !279, metadata !DIExpression()), !dbg !277
  store ptr %3, ptr %8, align 8
  call void @llvm.dbg.declare(metadata ptr %8, metadata !280, metadata !DIExpression()), !dbg !277
  %9 = load ptr, ptr %7, align 8, !dbg !281
  %10 = load ptr, ptr %8, align 8, !dbg !281
  %11 = load ptr, ptr %5, align 8, !dbg !281
  %12 = load ptr, ptr %6, align 8, !dbg !281
  %13 = load ptr, ptr %7, align 8, !dbg !281
  %14 = load ptr, ptr %8, align 8, !dbg !281
  call void @.omp_outlined._debug__(ptr %11, ptr %12, ptr %13, ptr %14) #6, !dbg !281
  ret void, !dbg !281
}

; Function Attrs: nounwind
declare i32 @__kmpc_global_thread_num(ptr) #6

; Function Attrs: nounwind
declare void @__kmpc_push_num_threads(ptr, i32, i32) #6

; Function Attrs: nounwind
declare !callback !282 void @__kmpc_fork_call(ptr, i32, ptr, ...) #6

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

; Function Attrs: inaccessiblememonly nocallback nofree nosync nounwind willreturn
declare void @llvm.experimental.noalias.scope.decl(metadata) #8

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { noinline norecurse nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { convergent nounwind }
attributes #5 = { noinline norecurse nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #6 = { nounwind }
attributes #7 = { argmemonly nocallback nofree nounwind willreturn }
attributes #8 = { inaccessiblememonly nocallback nofree nosync nounwind willreturn }

!llvm.dbg.cu = !{!22}
!llvm.module.flags = !{!44, !45, !46, !47, !48, !49, !50, !51}
!llvm.ident = !{!52}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 62, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/hybrid/015-MPI-hybrid-task-remote-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "b70ed4228a2aa7fee00520a0db00a6f4")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 280, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 35)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 69, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 49)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 104, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 152, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 19)
!17 = !DIGlobalVariableExpression(var: !18, expr: !DIExpression())
!18 = distinct !DIGlobalVariable(scope: null, file: !2, line: 111, type: !19, isLocal: true, isDefinition: true)
!19 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !20)
!20 = !{!21}
!21 = !DISubrange(count: 94)
!22 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !23, retainedTypes: !32, globals: !43, splitDebugInlining: false, nameTableKind: None)
!23 = !{!24}
!24 = !DICompositeType(tag: DW_TAG_enumeration_type, file: !25, line: 708, baseType: !26, size: 32, elements: !27)
!25 = !DIFile(filename: "/usr/lib/x86_64-linux-gnu/openmpi/include/mpi.h", directory: "", checksumkind: CSK_MD5, checksum: "c3ca5be6f2c6a6e16d01846df47c0b49")
!26 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!27 = !{!28, !29, !30, !31}
!28 = !DIEnumerator(name: "MPI_THREAD_SINGLE", value: 0)
!29 = !DIEnumerator(name: "MPI_THREAD_FUNNELED", value: 1)
!30 = !DIEnumerator(name: "MPI_THREAD_SERIALIZED", value: 2)
!31 = !DIEnumerator(name: "MPI_THREAD_MULTIPLE", value: 3)
!32 = !{!33, !36, !37, !40}
!33 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Comm", file: !25, line: 419, baseType: !34)
!34 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !35, size: 64)
!35 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_communicator_t", file: !25, line: 419, flags: DIFlagFwdDecl)
!36 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!37 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Info", file: !25, line: 424, baseType: !38)
!38 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !39, size: 64)
!39 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_info_t", file: !25, line: 424, flags: DIFlagFwdDecl)
!40 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Datatype", file: !25, line: 420, baseType: !41)
!41 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !42, size: 64)
!42 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_datatype_t", file: !25, line: 420, flags: DIFlagFwdDecl)
!43 = !{!0, !7, !12, !17}
!44 = !{i32 7, !"Dwarf Version", i32 5}
!45 = !{i32 2, !"Debug Info Version", i32 3}
!46 = !{i32 1, !"wchar_size", i32 4}
!47 = !{i32 7, !"openmp", i32 50}
!48 = !{i32 7, !"PIC Level", i32 2}
!49 = !{i32 7, !"PIE Level", i32 2}
!50 = !{i32 7, !"uwtable", i32 2}
!51 = !{i32 7, !"frame-pointer", i32 2}
!52 = !{!"Debian clang version 15.0.6"}
!53 = distinct !DISubprogram(name: "my_signal", scope: !2, file: !2, line: 31, type: !54, scopeLine: 32, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !22, retainedNodes: !58)
!54 = !DISubroutineType(types: !55)
!55 = !{null, !56}
!56 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !57, size: 64)
!57 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!58 = !{}
!59 = !DILocalVariable(name: "s", arg: 1, scope: !53, file: !2, line: 31, type: !56)
!60 = !DILocation(line: 31, column: 21, scope: !53)
!61 = !DILocation(line: 34, column: 7, scope: !62)
!62 = distinct !DILexicalBlock(scope: !53, file: !2, line: 33, column: 1)
!63 = !DILocation(line: 34, column: 5, scope: !62)
!64 = !DILocation(line: 35, column: 1, scope: !53)
!65 = distinct !DISubprogram(name: "my_wait", scope: !2, file: !2, line: 37, type: !66, scopeLine: 38, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !22, retainedNodes: !58)
!66 = !DISubroutineType(types: !67)
!67 = !{null, !56, !57}
!68 = !DILocalVariable(name: "s", arg: 1, scope: !65, file: !2, line: 37, type: !56)
!69 = !DILocation(line: 37, column: 19, scope: !65)
!70 = !DILocalVariable(name: "v", arg: 2, scope: !65, file: !2, line: 37, type: !57)
!71 = !DILocation(line: 37, column: 26, scope: !65)
!72 = !DILocalVariable(name: "wait", scope: !65, file: !2, line: 39, type: !57)
!73 = !DILocation(line: 39, column: 9, scope: !65)
!74 = !DILocation(line: 40, column: 5, scope: !65)
!75 = !DILocation(line: 41, column: 9, scope: !76)
!76 = distinct !DILexicalBlock(scope: !65, file: !2, line: 40, column: 8)
!77 = !DILocation(line: 43, column: 18, scope: !78)
!78 = distinct !DILexicalBlock(scope: !76, file: !2, line: 42, column: 1)
!79 = !DILocation(line: 43, column: 9, scope: !78)
!80 = !DILocation(line: 44, column: 5, scope: !76)
!81 = !DILocation(line: 44, column: 14, scope: !65)
!82 = !DILocation(line: 44, column: 21, scope: !65)
!83 = !DILocation(line: 44, column: 19, scope: !65)
!84 = distinct !{!84, !74, !85, !86}
!85 = !DILocation(line: 44, column: 22, scope: !65)
!86 = !{!"llvm.loop.mustprogress"}
!87 = !DILocation(line: 45, column: 1, scope: !65)
!88 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 50, type: !89, scopeLine: 51, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !22, retainedNodes: !58)
!89 = !DISubroutineType(types: !90)
!90 = !{!57, !57, !91}
!91 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !92, size: 64)
!92 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!93 = !DILocalVariable(name: "argc", arg: 1, scope: !88, file: !2, line: 50, type: !57)
!94 = !DILocation(line: 50, column: 14, scope: !88)
!95 = !DILocalVariable(name: "argv", arg: 2, scope: !88, file: !2, line: 50, type: !91)
!96 = !DILocation(line: 50, column: 27, scope: !88)
!97 = !DILocalVariable(name: "rank", scope: !88, file: !2, line: 52, type: !57)
!98 = !DILocation(line: 52, column: 9, scope: !88)
!99 = !DILocalVariable(name: "size", scope: !88, file: !2, line: 52, type: !57)
!100 = !DILocation(line: 52, column: 15, scope: !88)
!101 = !DILocalVariable(name: "win", scope: !88, file: !2, line: 53, type: !102)
!102 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !25, line: 429, baseType: !103)
!103 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !104, size: 64)
!104 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !25, line: 429, flags: DIFlagFwdDecl)
!105 = !DILocation(line: 53, column: 13, scope: !88)
!106 = !DILocalVariable(name: "win_base", scope: !88, file: !2, line: 54, type: !56)
!107 = !DILocation(line: 54, column: 10, scope: !88)
!108 = !DILocalVariable(name: "value", scope: !88, file: !2, line: 55, type: !57)
!109 = !DILocation(line: 55, column: 9, scope: !88)
!110 = !DILocalVariable(name: "value2", scope: !88, file: !2, line: 55, type: !57)
!111 = !DILocation(line: 55, column: 20, scope: !88)
!112 = !DILocalVariable(name: "result", scope: !88, file: !2, line: 56, type: !57)
!113 = !DILocation(line: 56, column: 9, scope: !88)
!114 = !DILocalVariable(name: "token", scope: !88, file: !2, line: 57, type: !57)
!115 = !DILocation(line: 57, column: 9, scope: !88)
!116 = !DILocalVariable(name: "provided", scope: !88, file: !2, line: 59, type: !57)
!117 = !DILocation(line: 59, column: 9, scope: !88)
!118 = !DILocation(line: 60, column: 5, scope: !88)
!119 = !DILocation(line: 61, column: 9, scope: !120)
!120 = distinct !DILexicalBlock(scope: !88, file: !2, line: 61, column: 9)
!121 = !DILocation(line: 61, column: 18, scope: !120)
!122 = !DILocation(line: 61, column: 9, scope: !88)
!123 = !DILocation(line: 62, column: 9, scope: !124)
!124 = distinct !DILexicalBlock(scope: !120, file: !2, line: 61, column: 41)
!125 = !DILocation(line: 63, column: 9, scope: !124)
!126 = !DILocation(line: 64, column: 5, scope: !124)
!127 = !DILocation(line: 65, column: 5, scope: !88)
!128 = !DILocation(line: 66, column: 5, scope: !88)
!129 = !DILocation(line: 68, column: 9, scope: !130)
!130 = distinct !DILexicalBlock(scope: !88, file: !2, line: 68, column: 9)
!131 = !DILocation(line: 68, column: 14, scope: !130)
!132 = !DILocation(line: 68, column: 9, scope: !88)
!133 = !DILocation(line: 69, column: 69, scope: !134)
!134 = distinct !DILexicalBlock(scope: !130, file: !2, line: 68, column: 27)
!135 = !DILocation(line: 69, column: 9, scope: !134)
!136 = !DILocation(line: 70, column: 9, scope: !134)
!137 = !DILocation(line: 71, column: 5, scope: !134)
!138 = !DILocation(line: 73, column: 5, scope: !88)
!139 = !DILocalVariable(name: "i", scope: !140, file: !2, line: 74, type: !57)
!140 = distinct !DILexicalBlock(scope: !88, file: !2, line: 74, column: 5)
!141 = !DILocation(line: 74, column: 14, scope: !140)
!142 = !DILocation(line: 74, column: 10, scope: !140)
!143 = !DILocation(line: 74, column: 21, scope: !144)
!144 = distinct !DILexicalBlock(scope: !140, file: !2, line: 74, column: 5)
!145 = !DILocation(line: 74, column: 23, scope: !144)
!146 = !DILocation(line: 74, column: 5, scope: !140)
!147 = !DILocation(line: 75, column: 9, scope: !148)
!148 = distinct !DILexicalBlock(scope: !144, file: !2, line: 74, column: 40)
!149 = !DILocation(line: 75, column: 18, scope: !148)
!150 = !DILocation(line: 75, column: 21, scope: !148)
!151 = !DILocation(line: 76, column: 5, scope: !148)
!152 = !DILocation(line: 74, column: 36, scope: !144)
!153 = !DILocation(line: 74, column: 5, scope: !144)
!154 = distinct !{!154, !146, !155, !86}
!155 = !DILocation(line: 76, column: 5, scope: !140)
!156 = !DILocation(line: 78, column: 5, scope: !88)
!157 = !DILocation(line: 80, column: 9, scope: !158)
!158 = distinct !DILexicalBlock(scope: !88, file: !2, line: 80, column: 9)
!159 = !DILocation(line: 80, column: 14, scope: !158)
!160 = !DILocation(line: 80, column: 9, scope: !88)
!161 = !DILocation(line: 81, column: 48, scope: !162)
!162 = distinct !DILexicalBlock(scope: !158, file: !2, line: 80, column: 20)
!163 = !DILocation(line: 81, column: 9, scope: !162)
!164 = !DILocation(line: 82, column: 15, scope: !162)
!165 = !DILocation(line: 84, column: 55, scope: !162)
!166 = !DILocation(line: 84, column: 9, scope: !162)
!167 = !DILocation(line: 85, column: 27, scope: !162)
!168 = !DILocation(line: 85, column: 9, scope: !162)
!169 = !DILocation(line: 86, column: 9, scope: !162)
!170 = !DILocation(line: 87, column: 5, scope: !162)
!171 = !DILocation(line: 89, column: 9, scope: !172)
!172 = distinct !DILexicalBlock(scope: !88, file: !2, line: 89, column: 9)
!173 = !DILocation(line: 89, column: 14, scope: !172)
!174 = !DILocation(line: 89, column: 9, scope: !88)
!175 = !DILocalVariable(name: "flag", scope: !176, file: !2, line: 90, type: !57)
!176 = distinct !DILexicalBlock(scope: !172, file: !2, line: 89, column: 20)
!177 = !DILocation(line: 90, column: 13, scope: !176)
!178 = !DILocation(line: 91, column: 1, scope: !176)
!179 = !DILocation(line: 107, column: 5, scope: !176)
!180 = !DILocation(line: 109, column: 5, scope: !88)
!181 = !DILocation(line: 112, column: 9, scope: !88)
!182 = !DILocation(line: 113, column: 9, scope: !88)
!183 = !DILocation(line: 114, column: 9, scope: !88)
!184 = !DILocation(line: 115, column: 9, scope: !88)
!185 = !DILocation(line: 110, column: 5, scope: !88)
!186 = !DILocation(line: 117, column: 5, scope: !88)
!187 = !DILocation(line: 118, column: 5, scope: !88)
!188 = !DILocation(line: 120, column: 5, scope: !88)
!189 = distinct !DISubprogram(name: ".omp_outlined._debug__", scope: !2, file: !2, line: 92, type: !190, scopeLine: 92, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !58)
!190 = !DISubroutineType(types: !191)
!191 = !{null, !192, !192, !196, !197}
!192 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !193)
!193 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !194)
!194 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !195, size: 64)
!195 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !57)
!196 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !57, size: 64)
!197 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !56, size: 64)
!198 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !189, type: !192, flags: DIFlagArtificial)
!199 = !DILocation(line: 0, scope: !189)
!200 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !189, type: !192, flags: DIFlagArtificial)
!201 = !DILocalVariable(name: "flag", arg: 3, scope: !189, file: !2, line: 90, type: !196)
!202 = !DILocation(line: 90, column: 13, scope: !189)
!203 = !DILocalVariable(name: "win_base", arg: 4, scope: !189, file: !2, line: 54, type: !197)
!204 = !DILocation(line: 54, column: 10, scope: !189)
!205 = !DILocation(line: 92, column: 9, scope: !189)
!206 = !DILocation(line: 93, column: 1, scope: !207)
!207 = distinct !DILexicalBlock(scope: !189, file: !2, line: 92, column: 9)
!208 = !DILocation(line: 95, column: 1, scope: !209)
!209 = distinct !DILexicalBlock(scope: !210, file: !2, line: 94, column: 13)
!210 = distinct !DILexicalBlock(scope: !207, file: !2, line: 93, column: 1)
!211 = !DILocation(line: 102, column: 17, scope: !209)
!212 = !DILocation(line: 104, column: 47, scope: !209)
!213 = !DILocation(line: 104, column: 17, scope: !209)
!214 = !DILocation(line: 105, column: 13, scope: !209)
!215 = !DILocation(line: 93, column: 19, scope: !210)
!216 = !DILocation(line: 106, column: 9, scope: !189)
!217 = distinct !DISubprogram(linkageName: ".omp_task_entry.", scope: !2, file: !2, line: 95, type: !218, scopeLine: 95, flags: DIFlagArtificial, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !58)
!218 = !DISubroutineType(types: !58)
!219 = !DILocalVariable(arg: 1, scope: !217, type: !57, flags: DIFlagArtificial)
!220 = !DILocation(line: 0, scope: !217)
!221 = !DILocalVariable(arg: 2, scope: !217, type: !222, flags: DIFlagArtificial)
!222 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !223)
!223 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !224, size: 64)
!224 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "kmp_task_t_with_privates", size: 320, elements: !225)
!225 = !{!226}
!226 = !DIDerivedType(tag: DW_TAG_member, scope: !224, file: !227, baseType: !228, size: 320)
!227 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/hybrid/015-MPI-hybrid-task-remote-yes.c", directory: "/rmaracebench")
!228 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "kmp_task_t", size: 320, elements: !229)
!229 = !{!230, !232}
!230 = !DIDerivedType(tag: DW_TAG_member, scope: !228, file: !227, baseType: !231, size: 64, offset: 192)
!231 = distinct !DICompositeType(tag: DW_TAG_union_type, name: "kmp_cmplrdata_t", size: 64, elements: !58)
!232 = !DIDerivedType(tag: DW_TAG_member, scope: !228, file: !227, baseType: !231, size: 64, offset: 256)
!233 = !DILocation(line: 95, column: 1, scope: !217)
!234 = !{!235}
!235 = distinct !{!235, !236, !".omp_outlined.: argument 0"}
!236 = distinct !{!236, !".omp_outlined."}
!237 = !{!238}
!238 = distinct !{!238, !236, !".omp_outlined.: argument 1"}
!239 = !{!240}
!240 = distinct !{!240, !236, !".omp_outlined.: argument 2"}
!241 = !{!242}
!242 = distinct !{!242, !236, !".omp_outlined.: argument 3"}
!243 = !{!235, !238, !240, !242}
!244 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !245, type: !195, flags: DIFlagArtificial)
!245 = distinct !DISubprogram(name: ".omp_outlined.", scope: !227, file: !227, line: 97, type: !246, scopeLine: 96, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !58)
!246 = !DISubroutineType(types: !247)
!247 = !{null, !195, !192, !248, !250, !255, !256}
!248 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !249)
!249 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !36)
!250 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !251)
!251 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !252)
!252 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !253, size: 64)
!253 = !DISubroutineType(types: !254)
!254 = !{null, !248, null}
!255 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !36)
!256 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !257)
!257 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !258)
!258 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !259, size: 64)
!259 = distinct !DICompositeType(tag: DW_TAG_structure_type, file: !2, line: 95, size: 64, elements: !58)
!260 = !DILocation(line: 0, scope: !245, inlinedAt: !261)
!261 = distinct !DILocation(line: 95, column: 1, scope: !217)
!262 = !DILocalVariable(name: ".part_id.", arg: 2, scope: !245, type: !192, flags: DIFlagArtificial)
!263 = !DILocalVariable(name: ".privates.", arg: 3, scope: !245, type: !248, flags: DIFlagArtificial)
!264 = !DILocalVariable(name: ".copy_fn.", arg: 4, scope: !245, type: !250, flags: DIFlagArtificial)
!265 = !DILocalVariable(name: ".task_t.", arg: 5, scope: !245, type: !255, flags: DIFlagArtificial)
!266 = !DILocalVariable(name: "__context", arg: 6, scope: !245, type: !256, flags: DIFlagArtificial)
!267 = !DILocation(line: 96, column: 17, scope: !268, inlinedAt: !261)
!268 = !DILexicalBlockFile(scope: !245, file: !2, discriminator: 0)
!269 = !DILocalVariable(name: "flag", scope: !268, file: !2, line: 90, type: !57)
!270 = !DILocation(line: 90, column: 13, scope: !268, inlinedAt: !261)
!271 = !DILocation(line: 97, column: 32, scope: !272, inlinedAt: !261)
!272 = distinct !DILexicalBlock(scope: !268, file: !2, line: 96, column: 17)
!273 = !DILocation(line: 97, column: 21, scope: !272, inlinedAt: !261)
!274 = !DILocation(line: 98, column: 21, scope: !272, inlinedAt: !261)
!275 = distinct !DISubprogram(name: ".omp_outlined..3", scope: !2, file: !2, line: 91, type: !190, scopeLine: 91, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !58)
!276 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !275, type: !192, flags: DIFlagArtificial)
!277 = !DILocation(line: 0, scope: !275)
!278 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !275, type: !192, flags: DIFlagArtificial)
!279 = !DILocalVariable(name: "flag", arg: 3, scope: !275, type: !196, flags: DIFlagArtificial)
!280 = !DILocalVariable(name: "win_base", arg: 4, scope: !275, type: !197, flags: DIFlagArtificial)
!281 = !DILocation(line: 91, column: 1, scope: !275)
!282 = !{!283}
!283 = !{i64 2, i64 -1, i64 -1, i1 true}
