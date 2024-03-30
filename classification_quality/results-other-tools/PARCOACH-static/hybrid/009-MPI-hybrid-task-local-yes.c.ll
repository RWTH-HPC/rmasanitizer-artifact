; ModuleID = 'results-20240330-164421/PARCOACH-static/hybrid/009-MPI-hybrid-task-local-yes.c'
source_filename = "results-20240330-164421/PARCOACH-static/hybrid/009-MPI-hybrid-task-local-yes.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ident_t = type { i32, i32, i32, i32, ptr }
%struct.ompi_predefined_datatype_t = type opaque
%struct.anon = type { ptr, ptr, ptr }
%struct.kmp_task_t_with_privates = type { %struct.kmp_task_t }
%struct.kmp_task_t = type { ptr, ptr, i32, %union.kmp_cmplrdata_t, %union.kmp_cmplrdata_t }
%union.kmp_cmplrdata_t = type { ptr }

@.str = private unnamed_addr constant [35 x i8] c"MPI_THREAD_MULTIPLE not supported\0A\00", align 1, !dbg !0
@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str.1 = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !7
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@0 = private unnamed_addr constant [92 x i8] c";results-20240330-164421/PARCOACH-static/hybrid/009-MPI-hybrid-task-local-yes.c;main;84;1;;\00", align 1
@1 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 91, ptr @0 }, align 8
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@2 = private unnamed_addr constant [92 x i8] c";results-20240330-164421/PARCOACH-static/hybrid/009-MPI-hybrid-task-local-yes.c;main;86;1;;\00", align 1
@3 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 91, ptr @2 }, align 8
@.str.2 = private unnamed_addr constant [19 x i8] c"win_base[0] is %d\0A\00", align 1, !dbg !12
@4 = private unnamed_addr constant %struct.ident_t { i32 0, i32 322, i32 0, i32 91, ptr @0 }, align 8
@5 = private unnamed_addr constant [93 x i8] c";results-20240330-164421/PARCOACH-static/hybrid/009-MPI-hybrid-task-local-yes.c;main;82;22;;\00", align 1
@6 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 92, ptr @5 }, align 8
@7 = private unnamed_addr constant [92 x i8] c";results-20240330-164421/PARCOACH-static/hybrid/009-MPI-hybrid-task-local-yes.c;main;82;1;;\00", align 1
@8 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 91, ptr @7 }, align 8
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
  br i1 %49, label %50, label %52, !dbg !160

50:                                               ; preds = %46
  call void @llvm.dbg.declare(metadata ptr %16, metadata !161, metadata !DIExpression()), !dbg !163
  store i32 0, ptr %16, align 4, !dbg !163
  call void @__kmpc_push_num_threads(ptr @6, i32 %17, i32 2), !dbg !164
  call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @8, i32 3, ptr @.omp_outlined..3, ptr %16, ptr %8, ptr %9), !dbg !164
  %51 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !165
  br label %52, !dbg !166

52:                                               ; preds = %50, %46
  %53 = load i32, ptr %6, align 4, !dbg !167
  %54 = icmp eq i32 %53, 1, !dbg !169
  br i1 %54, label %55, label %61, !dbg !170

55:                                               ; preds = %52
  %56 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !171
  %57 = load ptr, ptr %9, align 8, !dbg !173
  %58 = getelementptr inbounds i32, ptr %57, i64 0, !dbg !173
  %59 = load i32, ptr %58, align 4, !dbg !173
  %60 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %59), !dbg !174
  br label %61, !dbg !175

61:                                               ; preds = %55, %52
  %62 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !176
  %63 = load i32, ptr %6, align 4, !dbg !177
  %64 = load i32, ptr %10, align 4, !dbg !178
  %65 = load i32, ptr %11, align 4, !dbg !179
  %66 = load ptr, ptr %9, align 8, !dbg !180
  %67 = getelementptr inbounds i32, ptr %66, i64 0, !dbg !180
  %68 = load i32, ptr %67, align 4, !dbg !180
  %69 = call i32 (ptr, ...) @printf(ptr noundef @.str.4, i32 noundef %63, i32 noundef %64, i32 noundef %65, i32 noundef %68), !dbg !181
  %70 = call i32 @MPI_Win_free(ptr noundef %8), !dbg !182
  %71 = call i32 @MPI_Finalize(), !dbg !183
  ret i32 0, !dbg !184
}

declare i32 @MPI_Init_thread(ptr noundef, ptr noundef, i32 noundef, ptr noundef) #2

declare i32 @printf(ptr noundef, ...) #2

declare i32 @MPI_Abort(ptr noundef, i32 noundef) #2

declare i32 @MPI_Comm_rank(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_size(ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_allocate(i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Barrier(ptr noundef) #2

; Function Attrs: noinline norecurse nounwind optnone uwtable
define internal void @.omp_outlined._debug__(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 4 dereferenceable(4) %2, ptr noundef nonnull align 8 dereferenceable(8) %3, ptr noundef nonnull align 8 dereferenceable(8) %4) #3 !dbg !185 {
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  %9 = alloca ptr, align 8
  %10 = alloca ptr, align 8
  %11 = alloca %struct.anon, align 8
  store ptr %0, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !195, metadata !DIExpression()), !dbg !196
  store ptr %1, ptr %7, align 8
  call void @llvm.dbg.declare(metadata ptr %7, metadata !197, metadata !DIExpression()), !dbg !196
  store ptr %2, ptr %8, align 8
  call void @llvm.dbg.declare(metadata ptr %8, metadata !198, metadata !DIExpression()), !dbg !199
  store ptr %3, ptr %9, align 8
  call void @llvm.dbg.declare(metadata ptr %9, metadata !200, metadata !DIExpression()), !dbg !201
  store ptr %4, ptr %10, align 8
  call void @llvm.dbg.declare(metadata ptr %10, metadata !202, metadata !DIExpression()), !dbg !203
  %12 = load ptr, ptr %8, align 8, !dbg !204
  %13 = load ptr, ptr %9, align 8, !dbg !204
  %14 = load ptr, ptr %10, align 8, !dbg !204
  %15 = load ptr, ptr %6, align 8, !dbg !205
  %16 = load i32, ptr %15, align 4, !dbg !205
  %17 = call i32 @__kmpc_single(ptr @1, i32 %16), !dbg !205
  %18 = icmp ne i32 %17, 0, !dbg !205
  br i1 %18, label %19, label %32, !dbg !205

19:                                               ; preds = %5
  %20 = getelementptr inbounds %struct.anon, ptr %11, i32 0, i32 0, !dbg !207
  store ptr %12, ptr %20, align 8, !dbg !207
  %21 = getelementptr inbounds %struct.anon, ptr %11, i32 0, i32 1, !dbg !207
  store ptr %13, ptr %21, align 8, !dbg !207
  %22 = getelementptr inbounds %struct.anon, ptr %11, i32 0, i32 2, !dbg !207
  store ptr %14, ptr %22, align 8, !dbg !207
  %23 = call ptr @__kmpc_omp_task_alloc(ptr @3, i32 %16, i32 1, i64 40, i64 24, ptr @.omp_task_entry.), !dbg !207
  %24 = getelementptr inbounds %struct.kmp_task_t_with_privates, ptr %23, i32 0, i32 0, !dbg !207
  %25 = getelementptr inbounds %struct.kmp_task_t, ptr %24, i32 0, i32 0, !dbg !207
  %26 = load ptr, ptr %25, align 8, !dbg !207
  call void @llvm.memcpy.p0.p0.i64(ptr align 8 %26, ptr align 8 %11, i64 24, i1 false), !dbg !207
  %27 = call i32 @__kmpc_omp_task(ptr @3, i32 %16, ptr %23), !dbg !207
  call void @my_wait(ptr noundef %12, i32 noundef 1), !dbg !210
  %28 = load ptr, ptr %14, align 8, !dbg !211
  %29 = getelementptr inbounds i32, ptr %28, i64 0, !dbg !211
  %30 = load i32, ptr %29, align 4, !dbg !211
  %31 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %30), !dbg !212
  call void @__kmpc_end_single(ptr @1, i32 %16), !dbg !213
  br label %32, !dbg !213

32:                                               ; preds = %19, %5
  call void @__kmpc_barrier(ptr @4, i32 %16), !dbg !214
  ret void, !dbg !215
}

; Function Attrs: convergent nounwind
declare i32 @__kmpc_single(ptr, i32) #4

; Function Attrs: convergent nounwind
declare void @__kmpc_end_single(ptr, i32) #4

declare i32 @MPI_Win_lock(i32 noundef, i32 noundef, i32 noundef, ptr noundef) #2

declare i32 @MPI_Get(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_unlock(i32 noundef, ptr noundef) #2

; Function Attrs: noinline norecurse nounwind uwtable
define internal i32 @.omp_task_entry.(i32 noundef %0, ptr noalias noundef %1) #5 !dbg !216 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  %9 = alloca i32, align 4
  %10 = alloca ptr, align 8
  store i32 %0, ptr %9, align 4
  call void @llvm.dbg.declare(metadata ptr %9, metadata !218, metadata !DIExpression()), !dbg !219
  store ptr %1, ptr %10, align 8
  call void @llvm.dbg.declare(metadata ptr %10, metadata !220, metadata !DIExpression()), !dbg !219
  %11 = load i32, ptr %9, align 4, !dbg !232
  %12 = load ptr, ptr %10, align 8, !dbg !232
  %13 = getelementptr inbounds %struct.kmp_task_t_with_privates, ptr %12, i32 0, i32 0, !dbg !232
  %14 = getelementptr inbounds %struct.kmp_task_t, ptr %13, i32 0, i32 2, !dbg !232
  %15 = getelementptr inbounds %struct.kmp_task_t, ptr %13, i32 0, i32 0, !dbg !232
  %16 = load ptr, ptr %15, align 8, !dbg !232
  call void @llvm.experimental.noalias.scope.decl(metadata !233), !dbg !232
  call void @llvm.experimental.noalias.scope.decl(metadata !236), !dbg !232
  call void @llvm.experimental.noalias.scope.decl(metadata !238), !dbg !232
  call void @llvm.experimental.noalias.scope.decl(metadata !240), !dbg !232
  store i32 %11, ptr %3, align 4, !noalias !242
  call void @llvm.dbg.declare(metadata ptr %3, metadata !243, metadata !DIExpression()), !dbg !259
  store ptr %14, ptr %4, align 8, !noalias !242
  call void @llvm.dbg.declare(metadata ptr %4, metadata !261, metadata !DIExpression()), !dbg !259
  store ptr null, ptr %5, align 8, !noalias !242
  call void @llvm.dbg.declare(metadata ptr %5, metadata !262, metadata !DIExpression()), !dbg !259
  store ptr null, ptr %6, align 8, !noalias !242
  call void @llvm.dbg.declare(metadata ptr %6, metadata !263, metadata !DIExpression()), !dbg !259
  store ptr %12, ptr %7, align 8, !noalias !242
  call void @llvm.dbg.declare(metadata ptr %7, metadata !264, metadata !DIExpression()), !dbg !259
  store ptr %16, ptr %8, align 8, !noalias !242
  call void @llvm.dbg.declare(metadata ptr %8, metadata !265, metadata !DIExpression()), !dbg !259
  %17 = load ptr, ptr %8, align 8, !dbg !266, !noalias !242
  call void @llvm.dbg.declare(metadata ptr %17, metadata !268, metadata !DIExpression(DW_OP_deref)), !dbg !269
  call void @llvm.dbg.declare(metadata ptr %17, metadata !270, metadata !DIExpression(DW_OP_plus_uconst, 8, DW_OP_deref)), !dbg !271
  call void @llvm.dbg.declare(metadata ptr %17, metadata !272, metadata !DIExpression(DW_OP_plus_uconst, 16, DW_OP_deref)), !dbg !273
  %18 = load ptr, ptr %17, align 8, !dbg !274
  call void @my_signal(ptr noundef %18), !dbg !276
  %19 = getelementptr inbounds %struct.anon, ptr %17, i32 0, i32 1, !dbg !277
  %20 = load ptr, ptr %19, align 8, !dbg !277
  %21 = load ptr, ptr %20, align 8, !dbg !277
  %22 = call i32 @MPI_Win_lock(i32 noundef 1, i32 noundef 1, i32 noundef 0, ptr noundef %21) #6, !dbg !278
  %23 = getelementptr inbounds %struct.anon, ptr %17, i32 0, i32 2, !dbg !279
  %24 = load ptr, ptr %23, align 8, !dbg !279
  %25 = load ptr, ptr %24, align 8, !dbg !279
  %26 = getelementptr inbounds %struct.anon, ptr %17, i32 0, i32 1, !dbg !280
  %27 = load ptr, ptr %26, align 8, !dbg !280
  %28 = load ptr, ptr %27, align 8, !dbg !280
  %29 = call i32 @MPI_Get(ptr noundef %25, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 1, i64 noundef 0, i32 noundef 1, ptr noundef @ompi_mpi_int, ptr noundef %28) #6, !dbg !281
  %30 = getelementptr inbounds %struct.anon, ptr %17, i32 0, i32 1, !dbg !282
  %31 = load ptr, ptr %30, align 8, !dbg !282
  %32 = load ptr, ptr %31, align 8, !dbg !282
  %33 = call i32 @MPI_Win_unlock(i32 noundef 1, ptr noundef %32) #6, !dbg !283
  ret i32 0, !dbg !232
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
define internal void @.omp_outlined..3(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 4 dereferenceable(4) %2, ptr noundef nonnull align 8 dereferenceable(8) %3, ptr noundef nonnull align 8 dereferenceable(8) %4) #3 !dbg !284 {
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  %9 = alloca ptr, align 8
  %10 = alloca ptr, align 8
  store ptr %0, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !285, metadata !DIExpression()), !dbg !286
  store ptr %1, ptr %7, align 8
  call void @llvm.dbg.declare(metadata ptr %7, metadata !287, metadata !DIExpression()), !dbg !286
  store ptr %2, ptr %8, align 8
  call void @llvm.dbg.declare(metadata ptr %8, metadata !288, metadata !DIExpression()), !dbg !286
  store ptr %3, ptr %9, align 8
  call void @llvm.dbg.declare(metadata ptr %9, metadata !289, metadata !DIExpression()), !dbg !286
  store ptr %4, ptr %10, align 8
  call void @llvm.dbg.declare(metadata ptr %10, metadata !290, metadata !DIExpression()), !dbg !286
  %11 = load ptr, ptr %8, align 8, !dbg !291
  %12 = load ptr, ptr %9, align 8, !dbg !291
  %13 = load ptr, ptr %10, align 8, !dbg !291
  %14 = load ptr, ptr %6, align 8, !dbg !291
  %15 = load ptr, ptr %7, align 8, !dbg !291
  %16 = load ptr, ptr %8, align 8, !dbg !291
  %17 = load ptr, ptr %9, align 8, !dbg !291
  %18 = load ptr, ptr %10, align 8, !dbg !291
  call void @.omp_outlined._debug__(ptr %14, ptr %15, ptr %16, ptr %17, ptr %18) #6, !dbg !291
  ret void, !dbg !291
}

; Function Attrs: nounwind
declare i32 @__kmpc_global_thread_num(ptr) #6

; Function Attrs: nounwind
declare void @__kmpc_push_num_threads(ptr, i32, i32) #6

; Function Attrs: nounwind
declare !callback !292 void @__kmpc_fork_call(ptr, i32, ptr, ...) #6

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
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-static/hybrid/009-MPI-hybrid-task-local-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "1ac4d2c798033fde4777f99166964f74")
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
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 98, type: !14, isLocal: true, isDefinition: true)
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
!161 = !DILocalVariable(name: "flag", scope: !162, file: !2, line: 81, type: !57)
!162 = distinct !DILexicalBlock(scope: !158, file: !2, line: 80, column: 20)
!163 = !DILocation(line: 81, column: 13, scope: !162)
!164 = !DILocation(line: 82, column: 1, scope: !162)
!165 = !DILocation(line: 101, column: 9, scope: !162)
!166 = !DILocation(line: 102, column: 5, scope: !162)
!167 = !DILocation(line: 104, column: 9, scope: !168)
!168 = distinct !DILexicalBlock(scope: !88, file: !2, line: 104, column: 9)
!169 = !DILocation(line: 104, column: 14, scope: !168)
!170 = !DILocation(line: 104, column: 9, scope: !88)
!171 = !DILocation(line: 105, column: 9, scope: !172)
!172 = distinct !DILexicalBlock(scope: !168, file: !2, line: 104, column: 20)
!173 = !DILocation(line: 106, column: 39, scope: !172)
!174 = !DILocation(line: 106, column: 9, scope: !172)
!175 = !DILocation(line: 107, column: 5, scope: !172)
!176 = !DILocation(line: 109, column: 5, scope: !88)
!177 = !DILocation(line: 112, column: 9, scope: !88)
!178 = !DILocation(line: 113, column: 9, scope: !88)
!179 = !DILocation(line: 114, column: 9, scope: !88)
!180 = !DILocation(line: 115, column: 9, scope: !88)
!181 = !DILocation(line: 110, column: 5, scope: !88)
!182 = !DILocation(line: 117, column: 5, scope: !88)
!183 = !DILocation(line: 118, column: 5, scope: !88)
!184 = !DILocation(line: 120, column: 5, scope: !88)
!185 = distinct !DISubprogram(name: ".omp_outlined._debug__", scope: !2, file: !2, line: 83, type: !186, scopeLine: 83, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !58)
!186 = !DISubroutineType(types: !187)
!187 = !{null, !188, !188, !192, !193, !194}
!188 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !189)
!189 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !190)
!190 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !191, size: 64)
!191 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !57)
!192 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !57, size: 64)
!193 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !102, size: 64)
!194 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !56, size: 64)
!195 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !185, type: !188, flags: DIFlagArtificial)
!196 = !DILocation(line: 0, scope: !185)
!197 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !185, type: !188, flags: DIFlagArtificial)
!198 = !DILocalVariable(name: "flag", arg: 3, scope: !185, file: !2, line: 81, type: !192)
!199 = !DILocation(line: 81, column: 13, scope: !185)
!200 = !DILocalVariable(name: "win", arg: 4, scope: !185, file: !2, line: 53, type: !193)
!201 = !DILocation(line: 53, column: 13, scope: !185)
!202 = !DILocalVariable(name: "win_base", arg: 5, scope: !185, file: !2, line: 54, type: !194)
!203 = !DILocation(line: 54, column: 10, scope: !185)
!204 = !DILocation(line: 83, column: 9, scope: !185)
!205 = !DILocation(line: 84, column: 1, scope: !206)
!206 = distinct !DILexicalBlock(scope: !185, file: !2, line: 83, column: 9)
!207 = !DILocation(line: 86, column: 1, scope: !208)
!208 = distinct !DILexicalBlock(scope: !209, file: !2, line: 85, column: 13)
!209 = distinct !DILexicalBlock(scope: !206, file: !2, line: 84, column: 1)
!210 = !DILocation(line: 96, column: 17, scope: !208)
!211 = !DILocation(line: 98, column: 47, scope: !208)
!212 = !DILocation(line: 98, column: 17, scope: !208)
!213 = !DILocation(line: 99, column: 13, scope: !208)
!214 = !DILocation(line: 84, column: 19, scope: !209)
!215 = !DILocation(line: 100, column: 9, scope: !185)
!216 = distinct !DISubprogram(linkageName: ".omp_task_entry.", scope: !2, file: !2, line: 86, type: !217, scopeLine: 86, flags: DIFlagArtificial, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !58)
!217 = !DISubroutineType(types: !58)
!218 = !DILocalVariable(arg: 1, scope: !216, type: !57, flags: DIFlagArtificial)
!219 = !DILocation(line: 0, scope: !216)
!220 = !DILocalVariable(arg: 2, scope: !216, type: !221, flags: DIFlagArtificial)
!221 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !222)
!222 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !223, size: 64)
!223 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "kmp_task_t_with_privates", size: 320, elements: !224)
!224 = !{!225}
!225 = !DIDerivedType(tag: DW_TAG_member, scope: !223, file: !226, baseType: !227, size: 320)
!226 = !DIFile(filename: "results-20240330-164421/PARCOACH-static/hybrid/009-MPI-hybrid-task-local-yes.c", directory: "/rmaracebench")
!227 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "kmp_task_t", size: 320, elements: !228)
!228 = !{!229, !231}
!229 = !DIDerivedType(tag: DW_TAG_member, scope: !227, file: !226, baseType: !230, size: 64, offset: 192)
!230 = distinct !DICompositeType(tag: DW_TAG_union_type, name: "kmp_cmplrdata_t", size: 64, elements: !58)
!231 = !DIDerivedType(tag: DW_TAG_member, scope: !227, file: !226, baseType: !230, size: 64, offset: 256)
!232 = !DILocation(line: 86, column: 1, scope: !216)
!233 = !{!234}
!234 = distinct !{!234, !235, !".omp_outlined.: argument 0"}
!235 = distinct !{!235, !".omp_outlined."}
!236 = !{!237}
!237 = distinct !{!237, !235, !".omp_outlined.: argument 1"}
!238 = !{!239}
!239 = distinct !{!239, !235, !".omp_outlined.: argument 2"}
!240 = !{!241}
!241 = distinct !{!241, !235, !".omp_outlined.: argument 3"}
!242 = !{!234, !237, !239, !241}
!243 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !244, type: !191, flags: DIFlagArtificial)
!244 = distinct !DISubprogram(name: ".omp_outlined.", scope: !226, file: !226, line: 91, type: !245, scopeLine: 87, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !58)
!245 = !DISubroutineType(types: !246)
!246 = !{null, !191, !188, !247, !249, !254, !255}
!247 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !248)
!248 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !36)
!249 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !250)
!250 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !251)
!251 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !252, size: 64)
!252 = !DISubroutineType(types: !253)
!253 = !{null, !247, null}
!254 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !36)
!255 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !256)
!256 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !257)
!257 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !258, size: 64)
!258 = distinct !DICompositeType(tag: DW_TAG_structure_type, file: !2, line: 86, size: 192, elements: !58)
!259 = !DILocation(line: 0, scope: !244, inlinedAt: !260)
!260 = distinct !DILocation(line: 86, column: 1, scope: !216)
!261 = !DILocalVariable(name: ".part_id.", arg: 2, scope: !244, type: !188, flags: DIFlagArtificial)
!262 = !DILocalVariable(name: ".privates.", arg: 3, scope: !244, type: !247, flags: DIFlagArtificial)
!263 = !DILocalVariable(name: ".copy_fn.", arg: 4, scope: !244, type: !249, flags: DIFlagArtificial)
!264 = !DILocalVariable(name: ".task_t.", arg: 5, scope: !244, type: !254, flags: DIFlagArtificial)
!265 = !DILocalVariable(name: "__context", arg: 6, scope: !244, type: !255, flags: DIFlagArtificial)
!266 = !DILocation(line: 87, column: 17, scope: !267, inlinedAt: !260)
!267 = !DILexicalBlockFile(scope: !244, file: !2, discriminator: 0)
!268 = !DILocalVariable(name: "flag", scope: !267, file: !2, line: 81, type: !57)
!269 = !DILocation(line: 81, column: 13, scope: !267, inlinedAt: !260)
!270 = !DILocalVariable(name: "win", scope: !267, file: !2, line: 53, type: !102)
!271 = !DILocation(line: 53, column: 13, scope: !267, inlinedAt: !260)
!272 = !DILocalVariable(name: "win_base", scope: !267, file: !2, line: 54, type: !56)
!273 = !DILocation(line: 54, column: 10, scope: !267, inlinedAt: !260)
!274 = !DILocation(line: 88, column: 32, scope: !275, inlinedAt: !260)
!275 = distinct !DILexicalBlock(scope: !267, file: !2, line: 87, column: 17)
!276 = !DILocation(line: 88, column: 21, scope: !275, inlinedAt: !260)
!277 = !DILocation(line: 89, column: 60, scope: !275, inlinedAt: !260)
!278 = !DILocation(line: 89, column: 21, scope: !275, inlinedAt: !260)
!279 = !DILocation(line: 91, column: 30, scope: !275, inlinedAt: !260)
!280 = !DILocation(line: 91, column: 73, scope: !275, inlinedAt: !260)
!281 = !DILocation(line: 91, column: 21, scope: !275, inlinedAt: !260)
!282 = !DILocation(line: 92, column: 39, scope: !275, inlinedAt: !260)
!283 = !DILocation(line: 92, column: 21, scope: !275, inlinedAt: !260)
!284 = distinct !DISubprogram(name: ".omp_outlined..3", scope: !2, file: !2, line: 82, type: !186, scopeLine: 82, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !58)
!285 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !284, type: !188, flags: DIFlagArtificial)
!286 = !DILocation(line: 0, scope: !284)
!287 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !284, type: !188, flags: DIFlagArtificial)
!288 = !DILocalVariable(name: "flag", arg: 3, scope: !284, type: !192, flags: DIFlagArtificial)
!289 = !DILocalVariable(name: "win", arg: 4, scope: !284, type: !193, flags: DIFlagArtificial)
!290 = !DILocalVariable(name: "win_base", arg: 5, scope: !284, type: !194, flags: DIFlagArtificial)
!291 = !DILocation(line: 82, column: 1, scope: !284)
!292 = !{!293}
!293 = !{i64 2, i64 -1, i64 -1, i1 true}
