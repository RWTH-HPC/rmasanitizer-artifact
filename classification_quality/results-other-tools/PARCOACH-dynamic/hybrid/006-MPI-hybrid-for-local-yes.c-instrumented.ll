; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c.ll'
source_filename = "results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c"
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
@0 = private unnamed_addr constant [92 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c;main;66;1;;\00", align 1
@1 = private unnamed_addr constant %struct.ident_t { i32 0, i32 514, i32 0, i32 91, ptr @0 }, align 8
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@.str.2 = private unnamed_addr constant [19 x i8] c"win_base[0] is %d\0A\00", align 1, !dbg !12
@2 = private unnamed_addr constant [93 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c;main;66;36;;\00", align 1
@3 = private unnamed_addr constant %struct.ident_t { i32 0, i32 514, i32 0, i32 92, ptr @2 }, align 8
@4 = private unnamed_addr constant %struct.ident_t { i32 0, i32 66, i32 0, i32 91, ptr @0 }, align 8
@5 = private unnamed_addr constant [93 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c;main;64;22;;\00", align 1
@6 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 92, ptr @5 }, align 8
@7 = private unnamed_addr constant [92 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c;main;64;1;;\00", align 1
@8 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 91, ptr @7 }, align 8
@.str.3 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !17
@9 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@10 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@11 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@12 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@13 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@14 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@15 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@16 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@17 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@18 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@19 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@20 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@21 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@22 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1
@23 = private unnamed_addr constant [79 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c\00", align 1

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
  %33 = call i32 @parcoach_rma_MPI_Win_allocate(i64 40, i32 4, ptr @ompi_mpi_info_null, ptr @ompi_mpi_comm_world, ptr %9, ptr %8, i32 56, ptr @9), !dbg !106
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
  %46 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 61, ptr @10), !dbg !125
  %47 = load i32, ptr %6, align 4, !dbg !126
  %48 = icmp eq i32 %47, 0, !dbg !128
  br i1 %48, label %49, label %51, !dbg !129

49:                                               ; preds = %45
  call void @__kmpc_push_num_threads(ptr @6, i32 %16, i32 2), !dbg !130
  call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @8, i32 2, ptr @.omp_outlined., ptr %8, ptr %9), !dbg !130
  %50 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 79, ptr @11), !dbg !132
  br label %51, !dbg !133

51:                                               ; preds = %49, %45
  %52 = load i32, ptr %6, align 4, !dbg !134
  %53 = icmp eq i32 %52, 1, !dbg !136
  br i1 %53, label %54, label %60, !dbg !137

54:                                               ; preds = %51
  %55 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 83, ptr @12), !dbg !138
  %56 = load ptr, ptr %9, align 8, !dbg !140
  %57 = getelementptr inbounds i32, ptr %56, i64 0, !dbg !140
  %58 = load i32, ptr %57, align 4, !dbg !140
  %59 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %58), !dbg !141
  br label %60, !dbg !142

60:                                               ; preds = %54, %51
  %61 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 87, ptr @13), !dbg !143
  %62 = load i32, ptr %6, align 4, !dbg !144
  %63 = load i32, ptr %10, align 4, !dbg !145
  %64 = load i32, ptr %11, align 4, !dbg !146
  %65 = load ptr, ptr %9, align 8, !dbg !147
  %66 = getelementptr inbounds i32, ptr %65, i64 0, !dbg !147
  %67 = load i32, ptr %66, align 4, !dbg !147
  %68 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %62, i32 noundef %63, i32 noundef %64, i32 noundef %67), !dbg !148
  %69 = call i32 @parcoach_rma_MPI_Win_free(ptr %8, i32 95, ptr @14), !dbg !149
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
  call void @__kmpc_for_static_init_4(ptr @1, i32 %19, i32 33, ptr %14, ptr %11, ptr %12, ptr %13, i32 1, i32 1), !dbg !180
  br label %20, !dbg !179

20:                                               ; preds = %63, %4
  %21 = load i32, ptr %12, align 4, !dbg !174
  %22 = icmp sgt i32 %21, 1, !dbg !174
  br i1 %22, label %23, label %24, !dbg !174

23:                                               ; preds = %20
  br label %26, !dbg !174

24:                                               ; preds = %20
  %25 = load i32, ptr %12, align 4, !dbg !174
  br label %26, !dbg !174

26:                                               ; preds = %24, %23
  %27 = phi i32 [ 1, %23 ], [ %25, %24 ], !dbg !174
  store i32 %27, ptr %12, align 4, !dbg !174
  %28 = load i32, ptr %11, align 4, !dbg !174
  store i32 %28, ptr %9, align 4, !dbg !174
  %29 = load i32, ptr %9, align 4, !dbg !174
  %30 = load i32, ptr %12, align 4, !dbg !174
  %31 = icmp sle i32 %29, %30, !dbg !181
  br i1 %31, label %32, label %70, !dbg !179

32:                                               ; preds = %26
  br label %33, !dbg !179

33:                                               ; preds = %59, %32
  %34 = load i32, ptr %9, align 4, !dbg !174
  %35 = load i32, ptr %12, align 4, !dbg !174
  %36 = icmp sle i32 %34, %35, !dbg !181
  br i1 %36, label %37, label %62, !dbg !179

37:                                               ; preds = %33
  %38 = load i32, ptr %9, align 4, !dbg !174
  %39 = mul nsw i32 %38, 1, !dbg !182
  %40 = add nsw i32 0, %39, !dbg !182
  store i32 %40, ptr %15, align 4, !dbg !182
  %41 = load i32, ptr %15, align 4, !dbg !183
  %42 = icmp eq i32 %41, 0, !dbg !186
  br i1 %42, label %43, label %52, !dbg !187

43:                                               ; preds = %37
  %44 = load ptr, ptr %16, align 8, !dbg !188
  %45 = call i32 @parcoach_rma_MPI_Win_lock(i32 1, i32 1, i32 0, ptr %44, i32 69, ptr @15), !dbg !190
  call void @parcoach_rma_load(ptr %17, i64 64, i32 71, ptr @16), !dbg !191
  %46 = load ptr, ptr %17, align 8, !dbg !191
  %47 = getelementptr inbounds i32, ptr %46, i64 0, !dbg !191
  call void @parcoach_rma_load(ptr %16, i64 64, i32 71, ptr @17), !dbg !192
  %48 = load ptr, ptr %16, align 8, !dbg !192
  %49 = call i32 @parcoach_rma_MPI_Get(ptr %47, i32 1, ptr @ompi_mpi_int, i32 1, i64 0, i32 1, ptr @ompi_mpi_int, ptr %48, i32 71, ptr @18), !dbg !193
  %50 = load ptr, ptr %16, align 8, !dbg !194
  %51 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %50, i32 72, ptr @19), !dbg !195
  br label %57, !dbg !196

52:                                               ; preds = %37
  call void @parcoach_rma_load(ptr %17, i64 64, i32 75, ptr @20), !dbg !197
  %53 = load ptr, ptr %17, align 8, !dbg !197
  %54 = getelementptr inbounds i32, ptr %53, i64 0, !dbg !197
  call void @parcoach_rma_load(ptr %54, i64 32, i32 75, ptr @21), !dbg !197
  %55 = load i32, ptr %54, align 4, !dbg !197
  %56 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %55), !dbg !199
  br label %57

57:                                               ; preds = %52, %43
  br label %58, !dbg !200

58:                                               ; preds = %57
  br label %59, !dbg !180

59:                                               ; preds = %58
  call void @parcoach_rma_load(ptr %9, i64 32, i32 67, ptr @22), !dbg !174
  %60 = load i32, ptr %9, align 4, !dbg !174
  %61 = add nsw i32 %60, 1, !dbg !181
  call void @parcoach_rma_store(ptr %9, i64 32, i32 67, ptr @23), !dbg !181
  store i32 %61, ptr %9, align 4, !dbg !181
  br label %33, !dbg !180, !llvm.loop !201

62:                                               ; preds = %33
  br label %63, !dbg !180

63:                                               ; preds = %62
  %64 = load i32, ptr %11, align 4, !dbg !174
  %65 = load i32, ptr %13, align 4, !dbg !174
  %66 = add nsw i32 %64, %65, !dbg !181
  store i32 %66, ptr %11, align 4, !dbg !181
  %67 = load i32, ptr %12, align 4, !dbg !174
  %68 = load i32, ptr %13, align 4, !dbg !174
  %69 = add nsw i32 %67, %68, !dbg !181
  store i32 %69, ptr %12, align 4, !dbg !181
  br label %20, !dbg !180, !llvm.loop !203

70:                                               ; preds = %26
  call void @__kmpc_for_static_fini(ptr @3, i32 %19), !dbg !202
  call void @__kmpc_barrier(ptr @4, i32 %19), !dbg !202
  ret void, !dbg !204
}

declare void @__kmpc_for_static_init_4(ptr, i32, i32, ptr, ptr, ptr, ptr, i32, i32)

declare i32 @MPI_Win_lock(i32 noundef, i32 noundef, i32 noundef, ptr noundef) #2

declare i32 @MPI_Get(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_unlock(i32 noundef, ptr noundef) #2

; Function Attrs: nounwind
declare void @__kmpc_for_static_fini(ptr, i32) #4

; Function Attrs: convergent nounwind
declare void @__kmpc_barrier(ptr, i32) #5

; Function Attrs: noinline norecurse nounwind optnone uwtable
define internal void @.omp_outlined.(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 8 dereferenceable(8) %2, ptr noundef nonnull align 8 dereferenceable(8) %3) #3 !dbg !205 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !206, metadata !DIExpression()), !dbg !207
  store ptr %1, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !208, metadata !DIExpression()), !dbg !207
  store ptr %2, ptr %7, align 8
  call void @llvm.dbg.declare(metadata ptr %7, metadata !209, metadata !DIExpression()), !dbg !207
  store ptr %3, ptr %8, align 8
  call void @llvm.dbg.declare(metadata ptr %8, metadata !210, metadata !DIExpression()), !dbg !207
  %9 = load ptr, ptr %7, align 8, !dbg !211
  %10 = load ptr, ptr %8, align 8, !dbg !211
  %11 = load ptr, ptr %5, align 8, !dbg !211
  %12 = load ptr, ptr %6, align 8, !dbg !211
  %13 = load ptr, ptr %7, align 8, !dbg !211
  %14 = load ptr, ptr %8, align 8, !dbg !211
  call void @.omp_outlined._debug__(ptr %11, ptr %12, ptr %13, ptr %14) #4, !dbg !211
  ret void, !dbg !211
}

; Function Attrs: nounwind
declare i32 @__kmpc_global_thread_num(ptr) #4

; Function Attrs: nounwind
declare void @__kmpc_push_num_threads(ptr, i32, i32) #4

; Function Attrs: nounwind
declare !callback !212 void @__kmpc_fork_call(ptr, i32, ptr, ...) #4

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
attributes #4 = { nounwind }
attributes #5 = { convergent nounwind }

!llvm.dbg.cu = !{!22}
!llvm.module.flags = !{!44, !45, !46, !47, !48, !49, !50, !51}
!llvm.ident = !{!52}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 45, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/hybrid/006-MPI-hybrid-for-local-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "d8a3d5b54af241f741362635841230b0")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 280, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 35)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 52, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 49)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 75, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 152, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 19)
!17 = !DIGlobalVariableExpression(var: !18, expr: !DIExpression())
!18 = distinct !DIGlobalVariable(scope: null, file: !2, line: 89, type: !19, isLocal: true, isDefinition: true)
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
!53 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 33, type: !54, scopeLine: 34, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !22, retainedNodes: !59)
!54 = !DISubroutineType(types: !55)
!55 = !{!56, !56, !57}
!56 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!57 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !58, size: 64)
!58 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!59 = !{}
!60 = !DILocalVariable(name: "argc", arg: 1, scope: !53, file: !2, line: 33, type: !56)
!61 = !DILocation(line: 33, column: 14, scope: !53)
!62 = !DILocalVariable(name: "argv", arg: 2, scope: !53, file: !2, line: 33, type: !57)
!63 = !DILocation(line: 33, column: 27, scope: !53)
!64 = !DILocalVariable(name: "rank", scope: !53, file: !2, line: 35, type: !56)
!65 = !DILocation(line: 35, column: 9, scope: !53)
!66 = !DILocalVariable(name: "size", scope: !53, file: !2, line: 35, type: !56)
!67 = !DILocation(line: 35, column: 15, scope: !53)
!68 = !DILocalVariable(name: "win", scope: !53, file: !2, line: 36, type: !69)
!69 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !25, line: 429, baseType: !70)
!70 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !71, size: 64)
!71 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !25, line: 429, flags: DIFlagFwdDecl)
!72 = !DILocation(line: 36, column: 13, scope: !53)
!73 = !DILocalVariable(name: "win_base", scope: !53, file: !2, line: 37, type: !74)
!74 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !56, size: 64)
!75 = !DILocation(line: 37, column: 10, scope: !53)
!76 = !DILocalVariable(name: "value", scope: !53, file: !2, line: 38, type: !56)
!77 = !DILocation(line: 38, column: 9, scope: !53)
!78 = !DILocalVariable(name: "value2", scope: !53, file: !2, line: 38, type: !56)
!79 = !DILocation(line: 38, column: 20, scope: !53)
!80 = !DILocalVariable(name: "result", scope: !53, file: !2, line: 39, type: !56)
!81 = !DILocation(line: 39, column: 9, scope: !53)
!82 = !DILocalVariable(name: "token", scope: !53, file: !2, line: 40, type: !56)
!83 = !DILocation(line: 40, column: 9, scope: !53)
!84 = !DILocalVariable(name: "provided", scope: !53, file: !2, line: 42, type: !56)
!85 = !DILocation(line: 42, column: 9, scope: !53)
!86 = !DILocation(line: 43, column: 5, scope: !53)
!87 = !DILocation(line: 44, column: 9, scope: !88)
!88 = distinct !DILexicalBlock(scope: !53, file: !2, line: 44, column: 9)
!89 = !DILocation(line: 44, column: 18, scope: !88)
!90 = !DILocation(line: 44, column: 9, scope: !53)
!91 = !DILocation(line: 45, column: 9, scope: !92)
!92 = distinct !DILexicalBlock(scope: !88, file: !2, line: 44, column: 41)
!93 = !DILocation(line: 46, column: 9, scope: !92)
!94 = !DILocation(line: 47, column: 5, scope: !92)
!95 = !DILocation(line: 48, column: 5, scope: !53)
!96 = !DILocation(line: 49, column: 5, scope: !53)
!97 = !DILocation(line: 51, column: 9, scope: !98)
!98 = distinct !DILexicalBlock(scope: !53, file: !2, line: 51, column: 9)
!99 = !DILocation(line: 51, column: 14, scope: !98)
!100 = !DILocation(line: 51, column: 9, scope: !53)
!101 = !DILocation(line: 52, column: 69, scope: !102)
!102 = distinct !DILexicalBlock(scope: !98, file: !2, line: 51, column: 27)
!103 = !DILocation(line: 52, column: 9, scope: !102)
!104 = !DILocation(line: 53, column: 9, scope: !102)
!105 = !DILocation(line: 54, column: 5, scope: !102)
!106 = !DILocation(line: 56, column: 5, scope: !53)
!107 = !DILocalVariable(name: "i", scope: !108, file: !2, line: 57, type: !56)
!108 = distinct !DILexicalBlock(scope: !53, file: !2, line: 57, column: 5)
!109 = !DILocation(line: 57, column: 14, scope: !108)
!110 = !DILocation(line: 57, column: 10, scope: !108)
!111 = !DILocation(line: 57, column: 21, scope: !112)
!112 = distinct !DILexicalBlock(scope: !108, file: !2, line: 57, column: 5)
!113 = !DILocation(line: 57, column: 23, scope: !112)
!114 = !DILocation(line: 57, column: 5, scope: !108)
!115 = !DILocation(line: 58, column: 9, scope: !116)
!116 = distinct !DILexicalBlock(scope: !112, file: !2, line: 57, column: 40)
!117 = !DILocation(line: 58, column: 18, scope: !116)
!118 = !DILocation(line: 58, column: 21, scope: !116)
!119 = !DILocation(line: 59, column: 5, scope: !116)
!120 = !DILocation(line: 57, column: 36, scope: !112)
!121 = !DILocation(line: 57, column: 5, scope: !112)
!122 = distinct !{!122, !114, !123, !124}
!123 = !DILocation(line: 59, column: 5, scope: !108)
!124 = !{!"llvm.loop.mustprogress"}
!125 = !DILocation(line: 61, column: 5, scope: !53)
!126 = !DILocation(line: 63, column: 9, scope: !127)
!127 = distinct !DILexicalBlock(scope: !53, file: !2, line: 63, column: 9)
!128 = !DILocation(line: 63, column: 14, scope: !127)
!129 = !DILocation(line: 63, column: 9, scope: !53)
!130 = !DILocation(line: 64, column: 1, scope: !131)
!131 = distinct !DILexicalBlock(scope: !127, file: !2, line: 63, column: 20)
!132 = !DILocation(line: 79, column: 9, scope: !131)
!133 = !DILocation(line: 80, column: 5, scope: !131)
!134 = !DILocation(line: 82, column: 9, scope: !135)
!135 = distinct !DILexicalBlock(scope: !53, file: !2, line: 82, column: 9)
!136 = !DILocation(line: 82, column: 14, scope: !135)
!137 = !DILocation(line: 82, column: 9, scope: !53)
!138 = !DILocation(line: 83, column: 9, scope: !139)
!139 = distinct !DILexicalBlock(scope: !135, file: !2, line: 82, column: 20)
!140 = !DILocation(line: 84, column: 39, scope: !139)
!141 = !DILocation(line: 84, column: 9, scope: !139)
!142 = !DILocation(line: 85, column: 5, scope: !139)
!143 = !DILocation(line: 87, column: 5, scope: !53)
!144 = !DILocation(line: 90, column: 9, scope: !53)
!145 = !DILocation(line: 91, column: 9, scope: !53)
!146 = !DILocation(line: 92, column: 9, scope: !53)
!147 = !DILocation(line: 93, column: 9, scope: !53)
!148 = !DILocation(line: 88, column: 5, scope: !53)
!149 = !DILocation(line: 95, column: 5, scope: !53)
!150 = !DILocation(line: 96, column: 5, scope: !53)
!151 = !DILocation(line: 98, column: 5, scope: !53)
!152 = distinct !DISubprogram(name: ".omp_outlined._debug__", scope: !2, file: !2, line: 65, type: !153, scopeLine: 65, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !59)
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
!164 = !DILocalVariable(name: "win", arg: 3, scope: !152, file: !2, line: 36, type: !159)
!165 = !DILocation(line: 36, column: 13, scope: !152)
!166 = !DILocalVariable(name: "win_base", arg: 4, scope: !152, file: !2, line: 37, type: !160)
!167 = !DILocation(line: 37, column: 10, scope: !152)
!168 = !DILocation(line: 65, column: 9, scope: !152)
!169 = !DILocalVariable(name: ".omp.iv", scope: !170, type: !56, flags: DIFlagArtificial)
!170 = distinct !DILexicalBlock(scope: !171, file: !2, line: 66, column: 1)
!171 = distinct !DILexicalBlock(scope: !152, file: !2, line: 65, column: 9)
!172 = !DILocation(line: 0, scope: !170)
!173 = !DILocalVariable(name: ".omp.lb", scope: !170, type: !56, flags: DIFlagArtificial)
!174 = !DILocation(line: 67, column: 18, scope: !170)
!175 = !DILocalVariable(name: ".omp.ub", scope: !170, type: !56, flags: DIFlagArtificial)
!176 = !DILocalVariable(name: ".omp.stride", scope: !170, type: !56, flags: DIFlagArtificial)
!177 = !DILocalVariable(name: ".omp.is_last", scope: !170, type: !56, flags: DIFlagArtificial)
!178 = !DILocalVariable(name: "i", scope: !170, type: !56, flags: DIFlagArtificial)
!179 = !DILocation(line: 66, column: 1, scope: !171)
!180 = !DILocation(line: 66, column: 1, scope: !170)
!181 = !DILocation(line: 67, column: 13, scope: !170)
!182 = !DILocation(line: 67, column: 36, scope: !170)
!183 = !DILocation(line: 68, column: 21, scope: !184)
!184 = distinct !DILexicalBlock(scope: !185, file: !2, line: 68, column: 21)
!185 = distinct !DILexicalBlock(scope: !170, file: !2, line: 67, column: 41)
!186 = !DILocation(line: 68, column: 23, scope: !184)
!187 = !DILocation(line: 68, column: 21, scope: !185)
!188 = !DILocation(line: 69, column: 60, scope: !189)
!189 = distinct !DILexicalBlock(scope: !184, file: !2, line: 68, column: 29)
!190 = !DILocation(line: 69, column: 21, scope: !189)
!191 = !DILocation(line: 71, column: 30, scope: !189)
!192 = !DILocation(line: 71, column: 73, scope: !189)
!193 = !DILocation(line: 71, column: 21, scope: !189)
!194 = !DILocation(line: 72, column: 39, scope: !189)
!195 = !DILocation(line: 72, column: 21, scope: !189)
!196 = !DILocation(line: 73, column: 17, scope: !189)
!197 = !DILocation(line: 75, column: 51, scope: !198)
!198 = distinct !DILexicalBlock(scope: !184, file: !2, line: 73, column: 24)
!199 = !DILocation(line: 75, column: 21, scope: !198)
!200 = !DILocation(line: 77, column: 13, scope: !185)
!201 = distinct !{!201, !180, !202}
!202 = !DILocation(line: 66, column: 36, scope: !170)
!203 = distinct !{!203, !180, !202}
!204 = !DILocation(line: 78, column: 9, scope: !152)
!205 = distinct !DISubprogram(name: ".omp_outlined.", scope: !2, file: !2, line: 64, type: !153, scopeLine: 64, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !59)
!206 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !205, type: !155, flags: DIFlagArtificial)
!207 = !DILocation(line: 0, scope: !205)
!208 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !205, type: !155, flags: DIFlagArtificial)
!209 = !DILocalVariable(name: "win", arg: 3, scope: !205, type: !159, flags: DIFlagArtificial)
!210 = !DILocalVariable(name: "win_base", arg: 4, scope: !205, type: !160, flags: DIFlagArtificial)
!211 = !DILocation(line: 64, column: 1, scope: !205)
!212 = !{!213}
!213 = !{i64 2, i64 -1, i64 -1, i1 true}
