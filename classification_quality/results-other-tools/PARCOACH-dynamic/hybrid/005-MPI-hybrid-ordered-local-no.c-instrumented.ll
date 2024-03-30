; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c.ll'
source_filename = "results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ident_t = type { i32, i32, i32, i32, ptr }
%struct.ompi_predefined_datatype_t = type opaque

@.str = private unnamed_addr constant [35 x i8] c"MPI_THREAD_MULTIPLE not supported\0A\00", align 1, !dbg !0
@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str.1 = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !7
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@0 = private unnamed_addr constant [95 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c;main;62;1;;\00", align 1
@1 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 94, ptr @0 }, align 8
@2 = private unnamed_addr constant [95 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c;main;64;1;;\00", align 1
@3 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 94, ptr @2 }, align 8
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@.str.2 = private unnamed_addr constant [19 x i8] c"win_base[0] is %d\0A\00", align 1, !dbg !12
@4 = private unnamed_addr constant %struct.ident_t { i32 0, i32 66, i32 0, i32 94, ptr @0 }, align 8
@5 = private unnamed_addr constant [96 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c;main;60;22;;\00", align 1
@6 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 95, ptr @5 }, align 8
@7 = private unnamed_addr constant [95 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c;main;60;1;;\00", align 1
@8 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 94, ptr @7 }, align 8
@.str.3 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !17
@9 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@10 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@11 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@12 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@13 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@14 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@15 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@16 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@17 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@18 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@19 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@20 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@21 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@22 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1
@23 = private unnamed_addr constant [82 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !53 {
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
  %16 = call i32 @__kmpc_global_thread_num(ptr @6)
  store i32 0, ptr %3, align 4
  store i32 %0, ptr %4, align 4
  call void @llvm.dbg.declare(metadata ptr %4, metadata !60, metadata !DIExpression()), !dbg !61
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !62, metadata !DIExpression()), !dbg !63
  call void @llvm.dbg.declare(metadata ptr %6, metadata !64, metadata !DIExpression()), !dbg !65
  call void @llvm.dbg.declare(metadata ptr %7, metadata !66, metadata !DIExpression()), !dbg !67
  call void @llvm.dbg.declare(metadata ptr %8, metadata !68, metadata !DIExpression()), !dbg !72
  call void @llvm.dbg.declare(metadata ptr %9, metadata !73, metadata !DIExpression()), !dbg !75
  call void @llvm.dbg.declare(metadata ptr %10, metadata !76, metadata !DIExpression()), !dbg !77
  store i32 1, ptr %10, align 4, !dbg !77
  call void @llvm.dbg.declare(metadata ptr %11, metadata !78, metadata !DIExpression()), !dbg !79
  store i32 2, ptr %11, align 4, !dbg !79
  call void @llvm.dbg.declare(metadata ptr %12, metadata !80, metadata !DIExpression()), !dbg !81
  call void @llvm.dbg.declare(metadata ptr %13, metadata !82, metadata !DIExpression()), !dbg !83
  store i32 42, ptr %13, align 4, !dbg !83
  call void @llvm.dbg.declare(metadata ptr %14, metadata !84, metadata !DIExpression()), !dbg !85
  %17 = call i32 @MPI_Init_thread(ptr noundef %4, ptr noundef %5, i32 noundef 3, ptr noundef %14), !dbg !86
  %18 = load i32, ptr %14, align 4, !dbg !87
  %19 = icmp slt i32 %18, 3, !dbg !89
  br i1 %19, label %20, label %23, !dbg !90

20:                                               ; preds = %2
  %21 = call i32 (ptr, ...) @printf(ptr noundef @.str), !dbg !91
  %22 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !93
  br label %23, !dbg !94

23:                                               ; preds = %20, %2
  %24 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !95
  %25 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !96
  %26 = load i32, ptr %7, align 4, !dbg !97
  %27 = icmp ne i32 %26, 2, !dbg !99
  br i1 %27, label %28, label %32, !dbg !100

28:                                               ; preds = %23
  %29 = load i32, ptr %7, align 4, !dbg !101
  %30 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %29, i32 noundef 2), !dbg !103
  %31 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !104
  br label %32, !dbg !105

32:                                               ; preds = %28, %23
  %33 = call i32 @parcoach_rma_MPI_Win_allocate(i64 40, i32 4, ptr @ompi_mpi_info_null, ptr @ompi_mpi_comm_world, ptr %9, ptr %8, i32 52, ptr @9), !dbg !106
  call void @llvm.dbg.declare(metadata ptr %15, metadata !107, metadata !DIExpression()), !dbg !109
  store i32 0, ptr %15, align 4, !dbg !109
  br label %34, !dbg !110

34:                                               ; preds = %42, %32
  %35 = load i32, ptr %15, align 4, !dbg !111
  %36 = icmp slt i32 %35, 10, !dbg !113
  br i1 %36, label %37, label %45, !dbg !114

37:                                               ; preds = %34
  %38 = load ptr, ptr %9, align 8, !dbg !115
  %39 = load i32, ptr %15, align 4, !dbg !117
  %40 = sext i32 %39 to i64, !dbg !115
  %41 = getelementptr inbounds i32, ptr %38, i64 %40, !dbg !115
  store i32 0, ptr %41, align 4, !dbg !118
  br label %42, !dbg !119

42:                                               ; preds = %37
  %43 = load i32, ptr %15, align 4, !dbg !120
  %44 = add nsw i32 %43, 1, !dbg !120
  store i32 %44, ptr %15, align 4, !dbg !120
  br label %34, !dbg !121, !llvm.loop !122

45:                                               ; preds = %34
  %46 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 57, ptr @10), !dbg !125
  %47 = load i32, ptr %6, align 4, !dbg !126
  %48 = icmp eq i32 %47, 0, !dbg !128
  br i1 %48, label %49, label %51, !dbg !129

49:                                               ; preds = %45
  call void @__kmpc_push_num_threads(ptr @6, i32 %16, i32 2), !dbg !130
  call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @8, i32 2, ptr @.omp_outlined., ptr %8, ptr %9), !dbg !130
  %50 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 74, ptr @11), !dbg !132
  br label %51, !dbg !133

51:                                               ; preds = %49, %45
  %52 = load i32, ptr %6, align 4, !dbg !134
  %53 = icmp eq i32 %52, 1, !dbg !136
  br i1 %53, label %54, label %60, !dbg !137

54:                                               ; preds = %51
  %55 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 78, ptr @12), !dbg !138
  %56 = load ptr, ptr %9, align 8, !dbg !140
  %57 = getelementptr inbounds i32, ptr %56, i64 0, !dbg !140
  %58 = load i32, ptr %57, align 4, !dbg !140
  %59 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %58), !dbg !141
  br label %60, !dbg !142

60:                                               ; preds = %54, %51
  %61 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 82, ptr @13), !dbg !143
  %62 = load i32, ptr %6, align 4, !dbg !144
  %63 = load i32, ptr %10, align 4, !dbg !145
  %64 = load i32, ptr %11, align 4, !dbg !146
  %65 = load ptr, ptr %9, align 8, !dbg !147
  %66 = getelementptr inbounds i32, ptr %65, i64 0, !dbg !147
  %67 = load i32, ptr %66, align 4, !dbg !147
  %68 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %62, i32 noundef %63, i32 noundef %64, i32 noundef %67), !dbg !148
  %69 = call i32 @parcoach_rma_MPI_Win_free(ptr %8, i32 90, ptr @14), !dbg !149
  %70 = call i32 @MPI_Finalize(), !dbg !150
  ret i32 0, !dbg !151
}

; Function Attrs: nocallback nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @MPI_Init_thread(ptr noundef, ptr noundef, i32 noundef, ptr noundef) #2

declare i32 @printf(ptr noundef, ...) #2

declare i32 @MPI_Abort(ptr noundef, i32 noundef) #2

declare i32 @MPI_Comm_rank(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_size(ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_allocate(i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Barrier(ptr noundef) #2

; Function Attrs: noinline norecurse nounwind optnone uwtable
define internal void @.omp_outlined._debug__(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 8 dereferenceable(8) %2, ptr noundef nonnull align 8 dereferenceable(8) %3) #3 !dbg !152 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  store ptr %0, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !161, metadata !DIExpression()), !dbg !162
  store ptr %1, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !163, metadata !DIExpression()), !dbg !162
  store ptr %2, ptr %7, align 8
  call void @llvm.dbg.declare(metadata ptr %7, metadata !164, metadata !DIExpression()), !dbg !165
  store ptr %3, ptr %8, align 8
  call void @llvm.dbg.declare(metadata ptr %8, metadata !166, metadata !DIExpression()), !dbg !167
  %16 = load ptr, ptr %7, align 8, !dbg !168
  %17 = load ptr, ptr %8, align 8, !dbg !168
  call void @llvm.dbg.declare(metadata ptr %9, metadata !169, metadata !DIExpression()), !dbg !172
  call void @llvm.dbg.declare(metadata ptr %11, metadata !173, metadata !DIExpression()), !dbg !172
  store i32 0, ptr %11, align 4, !dbg !174
  call void @llvm.dbg.declare(metadata ptr %12, metadata !175, metadata !DIExpression()), !dbg !172
  store i32 1, ptr %12, align 4, !dbg !174
  call void @llvm.dbg.declare(metadata ptr %13, metadata !176, metadata !DIExpression()), !dbg !172
  store i32 1, ptr %13, align 4, !dbg !174
  call void @llvm.dbg.declare(metadata ptr %14, metadata !177, metadata !DIExpression()), !dbg !172
  store i32 0, ptr %14, align 4, !dbg !174
  call void @llvm.dbg.declare(metadata ptr %15, metadata !178, metadata !DIExpression()), !dbg !172
  %18 = load ptr, ptr %5, align 8, !dbg !179
  %19 = load i32, ptr %18, align 4, !dbg !179
  call void @__kmpc_dispatch_init_4(ptr @1, i32 %19, i32 66, i32 0, i32 1, i32 1, i32 1), !dbg !179
  br label %20, !dbg !179

20:                                               ; preds = %55, %4
  %21 = call i32 @__kmpc_dispatch_next_4(ptr @1, i32 %19, ptr %14, ptr %11, ptr %12, ptr %13), !dbg !179
  %22 = icmp ne i32 %21, 0, !dbg !179
  br i1 %22, label %23, label %56, !dbg !179

23:                                               ; preds = %20
  %24 = load i32, ptr %11, align 4, !dbg !174
  store i32 %24, ptr %9, align 4, !dbg !174
  br label %25, !dbg !179

25:                                               ; preds = %51, %23
  %26 = load i32, ptr %9, align 4, !dbg !174
  %27 = load i32, ptr %12, align 4, !dbg !174
  %28 = icmp sle i32 %26, %27, !dbg !180
  br i1 %28, label %29, label %54, !dbg !179

29:                                               ; preds = %25
  %30 = load i32, ptr %9, align 4, !dbg !174
  %31 = mul nsw i32 %30, 1, !dbg !181
  %32 = add nsw i32 0, %31, !dbg !181
  store i32 %32, ptr %15, align 4, !dbg !181
  call void @__kmpc_ordered(ptr @3, i32 %19), !dbg !182
  %33 = load i32, ptr %15, align 4, !dbg !184
  %34 = icmp eq i32 %33, 0, !dbg !187
  br i1 %34, label %35, label %44, !dbg !188

35:                                               ; preds = %29
  %36 = load ptr, ptr %16, align 8, !dbg !189
  %37 = call i32 @parcoach_rma_MPI_Win_lock(i32 1, i32 1, i32 0, ptr %36, i32 66, ptr @15), !dbg !191
  call void @parcoach_rma_load(ptr %17, i64 64, i32 67, ptr @16), !dbg !192
  %38 = load ptr, ptr %17, align 8, !dbg !192
  %39 = getelementptr inbounds i32, ptr %38, i64 0, !dbg !192
  call void @parcoach_rma_load(ptr %16, i64 64, i32 67, ptr @17), !dbg !193
  %40 = load ptr, ptr %16, align 8, !dbg !193
  %41 = call i32 @parcoach_rma_MPI_Get(ptr %39, i32 1, ptr @ompi_mpi_int, i32 1, i64 0, i32 1, ptr @ompi_mpi_int, ptr %40, i32 67, ptr @18), !dbg !194
  %42 = load ptr, ptr %16, align 8, !dbg !195
  %43 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %42, i32 68, ptr @19), !dbg !196
  br label %49, !dbg !197

44:                                               ; preds = %29
  call void @parcoach_rma_load(ptr %17, i64 64, i32 70, ptr @20), !dbg !198
  %45 = load ptr, ptr %17, align 8, !dbg !198
  %46 = getelementptr inbounds i32, ptr %45, i64 0, !dbg !198
  call void @parcoach_rma_load(ptr %46, i64 32, i32 70, ptr @21), !dbg !198
  %47 = load i32, ptr %46, align 4, !dbg !198
  %48 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %47), !dbg !200
  br label %49

49:                                               ; preds = %44, %35
  call void @__kmpc_end_ordered(ptr @3, i32 %19), !dbg !201
  br label %50, !dbg !202

50:                                               ; preds = %49
  br label %51, !dbg !203

51:                                               ; preds = %50
  call void @parcoach_rma_load(ptr %9, i64 32, i32 63, ptr @22), !dbg !174
  %52 = load i32, ptr %9, align 4, !dbg !174
  %53 = add nsw i32 %52, 1, !dbg !180
  call void @parcoach_rma_store(ptr %9, i64 32, i32 63, ptr @23), !dbg !180
  store i32 %53, ptr %9, align 4, !dbg !180
  call void @__kmpc_dispatch_fini_4(ptr @1, i32 %19), !dbg !203
  br label %25, !dbg !203, !llvm.loop !204

54:                                               ; preds = %25
  br label %55, !dbg !203

55:                                               ; preds = %54
  br label %20, !dbg !203, !llvm.loop !206

56:                                               ; preds = %20
  call void @__kmpc_barrier(ptr @4, i32 %19), !dbg !205
  ret void, !dbg !207
}

declare void @__kmpc_dispatch_init_4(ptr, i32, i32, i32, i32, i32, i32)

declare i32 @__kmpc_dispatch_next_4(ptr, i32, ptr, ptr, ptr, ptr)

; Function Attrs: convergent nounwind
declare void @__kmpc_ordered(ptr, i32) #4

; Function Attrs: convergent nounwind
declare void @__kmpc_end_ordered(ptr, i32) #4

declare i32 @MPI_Win_lock(i32 noundef, i32 noundef, i32 noundef, ptr noundef) #2

declare i32 @MPI_Get(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_unlock(i32 noundef, ptr noundef) #2

declare void @__kmpc_dispatch_fini_4(ptr, i32)

; Function Attrs: convergent nounwind
declare void @__kmpc_barrier(ptr, i32) #4

; Function Attrs: noinline norecurse nounwind optnone uwtable
define internal void @.omp_outlined.(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 8 dereferenceable(8) %2, ptr noundef nonnull align 8 dereferenceable(8) %3) #3 !dbg !208 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !209, metadata !DIExpression()), !dbg !210
  store ptr %1, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !211, metadata !DIExpression()), !dbg !210
  store ptr %2, ptr %7, align 8
  call void @llvm.dbg.declare(metadata ptr %7, metadata !212, metadata !DIExpression()), !dbg !210
  store ptr %3, ptr %8, align 8
  call void @llvm.dbg.declare(metadata ptr %8, metadata !213, metadata !DIExpression()), !dbg !210
  %9 = load ptr, ptr %7, align 8, !dbg !214
  %10 = load ptr, ptr %8, align 8, !dbg !214
  %11 = load ptr, ptr %5, align 8, !dbg !214
  %12 = load ptr, ptr %6, align 8, !dbg !214
  %13 = load ptr, ptr %7, align 8, !dbg !214
  %14 = load ptr, ptr %8, align 8, !dbg !214
  call void @.omp_outlined._debug__(ptr %11, ptr %12, ptr %13, ptr %14) #5, !dbg !214
  ret void, !dbg !214
}

; Function Attrs: nounwind
declare i32 @__kmpc_global_thread_num(ptr) #5

; Function Attrs: nounwind
declare void @__kmpc_push_num_threads(ptr, i32, i32) #5

; Function Attrs: nounwind
declare !callback !215 void @__kmpc_fork_call(ptr, i32, ptr, ...) #5

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

declare i32 @parcoach_rma_MPI_Win_allocate(i64, i32, ptr, ptr, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Barrier(ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_free(ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_lock(i32, i32, i32, ptr, i32, ptr)

declare void @parcoach_rma_load(ptr, i64, i32, ptr)

declare i32 @parcoach_rma_MPI_Get(ptr, i32, ptr, i32, i64, i32, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_unlock(i32, ptr, i32, ptr)

declare void @parcoach_rma_store(ptr, i64, i32, ptr)

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { noinline norecurse nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { convergent nounwind }
attributes #5 = { nounwind }

!llvm.dbg.cu = !{!22}
!llvm.module.flags = !{!44, !45, !46, !47, !48, !49, !50, !51}
!llvm.ident = !{!52}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 41, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/hybrid/005-MPI-hybrid-ordered-local-no.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "0c71c94252d434609df23ea6fc13a606")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 280, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 35)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 48, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 49)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 70, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 152, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 19)
!17 = !DIGlobalVariableExpression(var: !18, expr: !DIExpression())
!18 = distinct !DIGlobalVariable(scope: null, file: !2, line: 84, type: !19, isLocal: true, isDefinition: true)
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
!53 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 29, type: !54, scopeLine: 30, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !22, retainedNodes: !59)
!54 = !DISubroutineType(types: !55)
!55 = !{!56, !56, !57}
!56 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!57 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !58, size: 64)
!58 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!59 = !{}
!60 = !DILocalVariable(name: "argc", arg: 1, scope: !53, file: !2, line: 29, type: !56)
!61 = !DILocation(line: 29, column: 14, scope: !53)
!62 = !DILocalVariable(name: "argv", arg: 2, scope: !53, file: !2, line: 29, type: !57)
!63 = !DILocation(line: 29, column: 27, scope: !53)
!64 = !DILocalVariable(name: "rank", scope: !53, file: !2, line: 31, type: !56)
!65 = !DILocation(line: 31, column: 9, scope: !53)
!66 = !DILocalVariable(name: "size", scope: !53, file: !2, line: 31, type: !56)
!67 = !DILocation(line: 31, column: 15, scope: !53)
!68 = !DILocalVariable(name: "win", scope: !53, file: !2, line: 32, type: !69)
!69 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !25, line: 429, baseType: !70)
!70 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !71, size: 64)
!71 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !25, line: 429, flags: DIFlagFwdDecl)
!72 = !DILocation(line: 32, column: 13, scope: !53)
!73 = !DILocalVariable(name: "win_base", scope: !53, file: !2, line: 33, type: !74)
!74 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !56, size: 64)
!75 = !DILocation(line: 33, column: 10, scope: !53)
!76 = !DILocalVariable(name: "value", scope: !53, file: !2, line: 34, type: !56)
!77 = !DILocation(line: 34, column: 9, scope: !53)
!78 = !DILocalVariable(name: "value2", scope: !53, file: !2, line: 34, type: !56)
!79 = !DILocation(line: 34, column: 20, scope: !53)
!80 = !DILocalVariable(name: "result", scope: !53, file: !2, line: 35, type: !56)
!81 = !DILocation(line: 35, column: 9, scope: !53)
!82 = !DILocalVariable(name: "token", scope: !53, file: !2, line: 36, type: !56)
!83 = !DILocation(line: 36, column: 9, scope: !53)
!84 = !DILocalVariable(name: "provided", scope: !53, file: !2, line: 38, type: !56)
!85 = !DILocation(line: 38, column: 9, scope: !53)
!86 = !DILocation(line: 39, column: 5, scope: !53)
!87 = !DILocation(line: 40, column: 9, scope: !88)
!88 = distinct !DILexicalBlock(scope: !53, file: !2, line: 40, column: 9)
!89 = !DILocation(line: 40, column: 18, scope: !88)
!90 = !DILocation(line: 40, column: 9, scope: !53)
!91 = !DILocation(line: 41, column: 9, scope: !92)
!92 = distinct !DILexicalBlock(scope: !88, file: !2, line: 40, column: 41)
!93 = !DILocation(line: 42, column: 9, scope: !92)
!94 = !DILocation(line: 43, column: 5, scope: !92)
!95 = !DILocation(line: 44, column: 5, scope: !53)
!96 = !DILocation(line: 45, column: 5, scope: !53)
!97 = !DILocation(line: 47, column: 9, scope: !98)
!98 = distinct !DILexicalBlock(scope: !53, file: !2, line: 47, column: 9)
!99 = !DILocation(line: 47, column: 14, scope: !98)
!100 = !DILocation(line: 47, column: 9, scope: !53)
!101 = !DILocation(line: 48, column: 69, scope: !102)
!102 = distinct !DILexicalBlock(scope: !98, file: !2, line: 47, column: 27)
!103 = !DILocation(line: 48, column: 9, scope: !102)
!104 = !DILocation(line: 49, column: 9, scope: !102)
!105 = !DILocation(line: 50, column: 5, scope: !102)
!106 = !DILocation(line: 52, column: 5, scope: !53)
!107 = !DILocalVariable(name: "i", scope: !108, file: !2, line: 53, type: !56)
!108 = distinct !DILexicalBlock(scope: !53, file: !2, line: 53, column: 5)
!109 = !DILocation(line: 53, column: 14, scope: !108)
!110 = !DILocation(line: 53, column: 10, scope: !108)
!111 = !DILocation(line: 53, column: 21, scope: !112)
!112 = distinct !DILexicalBlock(scope: !108, file: !2, line: 53, column: 5)
!113 = !DILocation(line: 53, column: 23, scope: !112)
!114 = !DILocation(line: 53, column: 5, scope: !108)
!115 = !DILocation(line: 54, column: 9, scope: !116)
!116 = distinct !DILexicalBlock(scope: !112, file: !2, line: 53, column: 40)
!117 = !DILocation(line: 54, column: 18, scope: !116)
!118 = !DILocation(line: 54, column: 21, scope: !116)
!119 = !DILocation(line: 55, column: 5, scope: !116)
!120 = !DILocation(line: 53, column: 36, scope: !112)
!121 = !DILocation(line: 53, column: 5, scope: !112)
!122 = distinct !{!122, !114, !123, !124}
!123 = !DILocation(line: 55, column: 5, scope: !108)
!124 = !{!"llvm.loop.mustprogress"}
!125 = !DILocation(line: 57, column: 5, scope: !53)
!126 = !DILocation(line: 59, column: 9, scope: !127)
!127 = distinct !DILexicalBlock(scope: !53, file: !2, line: 59, column: 9)
!128 = !DILocation(line: 59, column: 14, scope: !127)
!129 = !DILocation(line: 59, column: 9, scope: !53)
!130 = !DILocation(line: 60, column: 1, scope: !131)
!131 = distinct !DILexicalBlock(scope: !127, file: !2, line: 59, column: 20)
!132 = !DILocation(line: 74, column: 9, scope: !131)
!133 = !DILocation(line: 75, column: 5, scope: !131)
!134 = !DILocation(line: 77, column: 9, scope: !135)
!135 = distinct !DILexicalBlock(scope: !53, file: !2, line: 77, column: 9)
!136 = !DILocation(line: 77, column: 14, scope: !135)
!137 = !DILocation(line: 77, column: 9, scope: !53)
!138 = !DILocation(line: 78, column: 9, scope: !139)
!139 = distinct !DILexicalBlock(scope: !135, file: !2, line: 77, column: 20)
!140 = !DILocation(line: 79, column: 39, scope: !139)
!141 = !DILocation(line: 79, column: 9, scope: !139)
!142 = !DILocation(line: 80, column: 5, scope: !139)
!143 = !DILocation(line: 82, column: 5, scope: !53)
!144 = !DILocation(line: 85, column: 9, scope: !53)
!145 = !DILocation(line: 86, column: 9, scope: !53)
!146 = !DILocation(line: 87, column: 9, scope: !53)
!147 = !DILocation(line: 88, column: 9, scope: !53)
!148 = !DILocation(line: 83, column: 5, scope: !53)
!149 = !DILocation(line: 90, column: 5, scope: !53)
!150 = !DILocation(line: 91, column: 5, scope: !53)
!151 = !DILocation(line: 93, column: 5, scope: !53)
!152 = distinct !DISubprogram(name: ".omp_outlined._debug__", scope: !2, file: !2, line: 61, type: !153, scopeLine: 61, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !59)
!153 = !DISubroutineType(types: !154)
!154 = !{null, !155, !155, !159, !160}
!155 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !156)
!156 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !157)
!157 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !158, size: 64)
!158 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !56)
!159 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !69, size: 64)
!160 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !74, size: 64)
!161 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !152, type: !155, flags: DIFlagArtificial)
!162 = !DILocation(line: 0, scope: !152)
!163 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !152, type: !155, flags: DIFlagArtificial)
!164 = !DILocalVariable(name: "win", arg: 3, scope: !152, file: !2, line: 32, type: !159)
!165 = !DILocation(line: 32, column: 13, scope: !152)
!166 = !DILocalVariable(name: "win_base", arg: 4, scope: !152, file: !2, line: 33, type: !160)
!167 = !DILocation(line: 33, column: 10, scope: !152)
!168 = !DILocation(line: 61, column: 9, scope: !152)
!169 = !DILocalVariable(name: ".omp.iv", scope: !170, type: !56, flags: DIFlagArtificial)
!170 = distinct !DILexicalBlock(scope: !171, file: !2, line: 62, column: 1)
!171 = distinct !DILexicalBlock(scope: !152, file: !2, line: 61, column: 9)
!172 = !DILocation(line: 0, scope: !170)
!173 = !DILocalVariable(name: ".omp.lb", scope: !170, type: !56, flags: DIFlagArtificial)
!174 = !DILocation(line: 63, column: 18, scope: !170)
!175 = !DILocalVariable(name: ".omp.ub", scope: !170, type: !56, flags: DIFlagArtificial)
!176 = !DILocalVariable(name: ".omp.stride", scope: !170, type: !56, flags: DIFlagArtificial)
!177 = !DILocalVariable(name: ".omp.is_last", scope: !170, type: !56, flags: DIFlagArtificial)
!178 = !DILocalVariable(name: "i", scope: !170, type: !56, flags: DIFlagArtificial)
!179 = !DILocation(line: 62, column: 1, scope: !171)
!180 = !DILocation(line: 63, column: 13, scope: !170)
!181 = !DILocation(line: 63, column: 36, scope: !170)
!182 = !DILocation(line: 64, column: 1, scope: !183)
!183 = distinct !DILexicalBlock(scope: !170, file: !2, line: 63, column: 41)
!184 = !DILocation(line: 65, column: 21, scope: !185)
!185 = distinct !DILexicalBlock(scope: !186, file: !2, line: 65, column: 21)
!186 = distinct !DILexicalBlock(scope: !183, file: !2, line: 64, column: 1)
!187 = !DILocation(line: 65, column: 23, scope: !185)
!188 = !DILocation(line: 65, column: 21, scope: !186)
!189 = !DILocation(line: 66, column: 60, scope: !190)
!190 = distinct !DILexicalBlock(scope: !185, file: !2, line: 65, column: 29)
!191 = !DILocation(line: 66, column: 21, scope: !190)
!192 = !DILocation(line: 67, column: 30, scope: !190)
!193 = !DILocation(line: 67, column: 73, scope: !190)
!194 = !DILocation(line: 67, column: 21, scope: !190)
!195 = !DILocation(line: 68, column: 39, scope: !190)
!196 = !DILocation(line: 68, column: 21, scope: !190)
!197 = !DILocation(line: 69, column: 17, scope: !190)
!198 = !DILocation(line: 70, column: 51, scope: !199)
!199 = distinct !DILexicalBlock(scope: !185, file: !2, line: 69, column: 24)
!200 = !DILocation(line: 70, column: 21, scope: !199)
!201 = !DILocation(line: 65, column: 26, scope: !185)
!202 = !DILocation(line: 72, column: 13, scope: !183)
!203 = !DILocation(line: 62, column: 1, scope: !170)
!204 = distinct !{!204, !203, !205}
!205 = !DILocation(line: 62, column: 24, scope: !170)
!206 = distinct !{!206, !203, !205}
!207 = !DILocation(line: 73, column: 9, scope: !152)
!208 = distinct !DISubprogram(name: ".omp_outlined.", scope: !2, file: !2, line: 60, type: !153, scopeLine: 60, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !59)
!209 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !208, type: !155, flags: DIFlagArtificial)
!210 = !DILocation(line: 0, scope: !208)
!211 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !208, type: !155, flags: DIFlagArtificial)
!212 = !DILocalVariable(name: "win", arg: 3, scope: !208, type: !159, flags: DIFlagArtificial)
!213 = !DILocalVariable(name: "win_base", arg: 4, scope: !208, type: !160, flags: DIFlagArtificial)
!214 = !DILocation(line: 60, column: 1, scope: !208)
!215 = !{!216}
!216 = !{i64 2, i64 -1, i64 -1, i1 true}
