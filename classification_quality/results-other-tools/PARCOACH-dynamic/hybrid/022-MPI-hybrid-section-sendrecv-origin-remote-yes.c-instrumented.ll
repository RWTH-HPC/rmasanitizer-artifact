; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c.ll'
source_filename = "results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c"
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
@0 = private unnamed_addr constant [113 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c;main;66;1;;\00", align 1
@1 = private unnamed_addr constant %struct.ident_t { i32 0, i32 1026, i32 0, i32 112, ptr @0 }, align 8
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@2 = private unnamed_addr constant [114 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c;main;66;21;;\00", align 1
@3 = private unnamed_addr constant %struct.ident_t { i32 0, i32 1026, i32 0, i32 113, ptr @2 }, align 8
@4 = private unnamed_addr constant %struct.ident_t { i32 0, i32 194, i32 0, i32 112, ptr @0 }, align 8
@5 = private unnamed_addr constant [114 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c;main;64;22;;\00", align 1
@6 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 113, ptr @5 }, align 8
@7 = private unnamed_addr constant [113 x i8] c";results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c;main;64;1;;\00", align 1
@8 = private unnamed_addr constant %struct.ident_t { i32 0, i32 2, i32 0, i32 112, ptr @7 }, align 8
@.str.2 = private unnamed_addr constant [19 x i8] c"win_base[0] is %d\0A\00", align 1, !dbg !12
@.str.3 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !17
@9 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@10 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@11 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@12 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@13 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@14 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@15 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@16 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@17 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@18 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1
@19 = private unnamed_addr constant [100 x i8] c"results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !66 {
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
  call void @llvm.dbg.declare(metadata ptr %4, metadata !72, metadata !DIExpression()), !dbg !73
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !74, metadata !DIExpression()), !dbg !75
  call void @llvm.dbg.declare(metadata ptr %6, metadata !76, metadata !DIExpression()), !dbg !77
  call void @llvm.dbg.declare(metadata ptr %7, metadata !78, metadata !DIExpression()), !dbg !79
  call void @llvm.dbg.declare(metadata ptr %8, metadata !80, metadata !DIExpression()), !dbg !84
  call void @llvm.dbg.declare(metadata ptr %9, metadata !85, metadata !DIExpression()), !dbg !87
  call void @llvm.dbg.declare(metadata ptr %10, metadata !88, metadata !DIExpression()), !dbg !89
  store i32 1, ptr %10, align 4, !dbg !89
  call void @llvm.dbg.declare(metadata ptr %11, metadata !90, metadata !DIExpression()), !dbg !91
  store i32 2, ptr %11, align 4, !dbg !91
  call void @llvm.dbg.declare(metadata ptr %12, metadata !92, metadata !DIExpression()), !dbg !93
  call void @llvm.dbg.declare(metadata ptr %13, metadata !94, metadata !DIExpression()), !dbg !95
  store i32 42, ptr %13, align 4, !dbg !95
  call void @llvm.dbg.declare(metadata ptr %14, metadata !96, metadata !DIExpression()), !dbg !97
  %18 = call i32 @MPI_Init_thread(ptr noundef %4, ptr noundef %5, i32 noundef 3, ptr noundef %14), !dbg !98
  %19 = load i32, ptr %14, align 4, !dbg !99
  %20 = icmp slt i32 %19, 3, !dbg !101
  br i1 %20, label %21, label %24, !dbg !102

21:                                               ; preds = %2
  %22 = call i32 (ptr, ...) @printf(ptr noundef @.str), !dbg !103
  %23 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !105
  br label %24, !dbg !106

24:                                               ; preds = %21, %2
  %25 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !107
  %26 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !108
  %27 = load i32, ptr %7, align 4, !dbg !109
  %28 = icmp ne i32 %27, 2, !dbg !111
  br i1 %28, label %29, label %33, !dbg !112

29:                                               ; preds = %24
  %30 = load i32, ptr %7, align 4, !dbg !113
  %31 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %30, i32 noundef 2), !dbg !115
  %32 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !116
  br label %33, !dbg !117

33:                                               ; preds = %29, %24
  %34 = call i32 @parcoach_rma_MPI_Win_allocate(i64 40, i32 4, ptr @ompi_mpi_info_null, ptr @ompi_mpi_comm_world, ptr %9, ptr %8, i32 57, ptr @9), !dbg !118
  call void @llvm.dbg.declare(metadata ptr %15, metadata !119, metadata !DIExpression()), !dbg !121
  store i32 0, ptr %15, align 4, !dbg !121
  br label %35, !dbg !122

35:                                               ; preds = %43, %33
  %36 = load i32, ptr %15, align 4, !dbg !123
  %37 = icmp slt i32 %36, 10, !dbg !125
  br i1 %37, label %38, label %46, !dbg !126

38:                                               ; preds = %35
  %39 = load ptr, ptr %9, align 8, !dbg !127
  %40 = load i32, ptr %15, align 4, !dbg !129
  %41 = sext i32 %40 to i64, !dbg !127
  %42 = getelementptr inbounds i32, ptr %39, i64 %41, !dbg !127
  store i32 0, ptr %42, align 4, !dbg !130
  br label %43, !dbg !131

43:                                               ; preds = %38
  %44 = load i32, ptr %15, align 4, !dbg !132
  %45 = add nsw i32 %44, 1, !dbg !132
  store i32 %45, ptr %15, align 4, !dbg !132
  br label %35, !dbg !133, !llvm.loop !134

46:                                               ; preds = %35
  %47 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 61, ptr @10), !dbg !137
  %48 = load i32, ptr %6, align 4, !dbg !138
  %49 = icmp eq i32 %48, 0, !dbg !140
  br i1 %49, label %50, label %51, !dbg !141

50:                                               ; preds = %46
  call void @__kmpc_push_num_threads(ptr @6, i32 %17, i32 2), !dbg !142
  call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @8, i32 1, ptr @.omp_outlined., ptr %8), !dbg !142
  br label %51, !dbg !144

51:                                               ; preds = %50, %46
  %52 = load i32, ptr %6, align 4, !dbg !145
  %53 = icmp eq i32 %52, 1, !dbg !147
  br i1 %53, label %54, label %60, !dbg !148

54:                                               ; preds = %51
  call void @llvm.dbg.declare(metadata ptr %16, metadata !149, metadata !DIExpression()), !dbg !152
  %55 = call i32 @MPI_Recv(ptr noundef %16, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 0, i32 noundef 1, ptr noundef @ompi_mpi_comm_world, ptr noundef null), !dbg !153
  %56 = load ptr, ptr %9, align 8, !dbg !154
  %57 = getelementptr inbounds i32, ptr %56, i64 0, !dbg !154
  %58 = load i32, ptr %57, align 4, !dbg !154
  %59 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %58), !dbg !155
  br label %60, !dbg !156

60:                                               ; preds = %54, %51
  %61 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 96, ptr @11), !dbg !157
  %62 = load i32, ptr %6, align 4, !dbg !158
  %63 = load i32, ptr %10, align 4, !dbg !159
  %64 = load i32, ptr %11, align 4, !dbg !160
  %65 = load ptr, ptr %9, align 8, !dbg !161
  %66 = getelementptr inbounds i32, ptr %65, i64 0, !dbg !161
  %67 = load i32, ptr %66, align 4, !dbg !161
  %68 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %62, i32 noundef %63, i32 noundef %64, i32 noundef %67), !dbg !162
  %69 = call i32 @parcoach_rma_MPI_Win_free(ptr %8, i32 104, ptr @12), !dbg !163
  %70 = call i32 @MPI_Finalize(), !dbg !164
  ret i32 0, !dbg !165
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
define internal void @.omp_outlined._debug__(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 8 dereferenceable(8) %2) #3 !dbg !166 {
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  store ptr %0, ptr %4, align 8
  call void @llvm.dbg.declare(metadata ptr %4, metadata !174, metadata !DIExpression()), !dbg !175
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !176, metadata !DIExpression()), !dbg !175
  store ptr %2, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !177, metadata !DIExpression()), !dbg !178
  %14 = load ptr, ptr %6, align 8, !dbg !179
  store i32 0, ptr %7, align 4, !dbg !180
  store i32 1, ptr %8, align 4, !dbg !180
  store i32 1, ptr %9, align 4, !dbg !180
  store i32 0, ptr %10, align 4, !dbg !180
  %15 = load ptr, ptr %4, align 8, !dbg !180
  %16 = load i32, ptr %15, align 4, !dbg !180
  call void @__kmpc_for_static_init_4(ptr @1, i32 %16, i32 34, ptr %10, ptr %7, ptr %8, ptr %9, i32 1, i32 1), !dbg !182
  %17 = load i32, ptr %8, align 4, !dbg !180
  %18 = icmp slt i32 %17, 1, !dbg !180
  %19 = select i1 %18, i32 %17, i32 1, !dbg !180
  store i32 %19, ptr %8, align 4, !dbg !180
  %20 = load i32, ptr %7, align 4, !dbg !180
  store i32 %20, ptr %11, align 4, !dbg !180
  br label %21, !dbg !180

21:                                               ; preds = %38, %3
  %22 = load i32, ptr %11, align 4, !dbg !182
  %23 = load i32, ptr %8, align 4, !dbg !182
  %24 = icmp sle i32 %22, %23, !dbg !182
  br i1 %24, label %25, label %41, !dbg !180

25:                                               ; preds = %21
  %26 = load i32, ptr %11, align 4, !dbg !180
  switch i32 %26, label %37 [
    i32 0, label %27
    i32 1, label %34
  ], !dbg !180

27:                                               ; preds = %25
  call void @llvm.dbg.declare(metadata ptr %12, metadata !184, metadata !DIExpression()), !dbg !187
  store i32 42, ptr %12, align 4, !dbg !187
  %28 = load ptr, ptr %14, align 8, !dbg !188
  %29 = call i32 @parcoach_rma_MPI_Win_lock(i32 1, i32 1, i32 0, ptr %28, i32 71, ptr @13), !dbg !189
  call void @parcoach_rma_load(ptr %14, i64 64, i32 73, ptr @14), !dbg !190
  %30 = load ptr, ptr %14, align 8, !dbg !190
  %31 = call i32 @parcoach_rma_MPI_Put(ptr %12, i32 1, ptr @ompi_mpi_int, i32 1, i64 0, i32 1, ptr @ompi_mpi_int, ptr %30, i32 73, ptr @15), !dbg !191
  %32 = load ptr, ptr %14, align 8, !dbg !192
  %33 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %32, i32 74, ptr @16), !dbg !193
  br label %37, !dbg !194

34:                                               ; preds = %25
  %35 = call i32 @sleep(i32 noundef 1), !dbg !195
  call void @llvm.dbg.declare(metadata ptr %13, metadata !198, metadata !DIExpression()), !dbg !199
  call void @parcoach_rma_store(ptr %13, i64 32, i32 80, ptr @17), !dbg !199
  store i32 1, ptr %13, align 4, !dbg !199
  %36 = call i32 @MPI_Send(ptr noundef %13, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 1, i32 noundef 1, ptr noundef @ompi_mpi_comm_world), !dbg !200
  br label %37, !dbg !201

37:                                               ; preds = %34, %27, %25
  br label %38, !dbg !201

38:                                               ; preds = %37
  call void @parcoach_rma_load(ptr %11, i64 32, i32 66, ptr @18), !dbg !182
  %39 = load i32, ptr %11, align 4, !dbg !182
  %40 = add nsw i32 %39, 1, !dbg !182
  call void @parcoach_rma_store(ptr %11, i64 32, i32 66, ptr @19), !dbg !182
  store i32 %40, ptr %11, align 4, !dbg !182
  br label %21, !dbg !201, !llvm.loop !202

41:                                               ; preds = %21
  call void @__kmpc_for_static_fini(ptr @3, i32 %16), !dbg !203
  call void @__kmpc_barrier(ptr @4, i32 %16), !dbg !203
  ret void, !dbg !204
}

declare void @__kmpc_for_static_init_4(ptr, i32, i32, ptr, ptr, ptr, ptr, i32, i32)

declare i32 @MPI_Win_lock(i32 noundef, i32 noundef, i32 noundef, ptr noundef) #2

declare i32 @MPI_Put(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_unlock(i32 noundef, ptr noundef) #2

declare i32 @sleep(i32 noundef) #2

declare i32 @MPI_Send(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i32 noundef, ptr noundef) #2

; Function Attrs: nounwind
declare void @__kmpc_for_static_fini(ptr, i32) #4

; Function Attrs: convergent nounwind
declare void @__kmpc_barrier(ptr, i32) #5

; Function Attrs: noinline norecurse nounwind optnone uwtable
define internal void @.omp_outlined.(ptr noalias noundef %0, ptr noalias noundef %1, ptr noundef nonnull align 8 dereferenceable(8) %2) #3 !dbg !205 {
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  store ptr %0, ptr %4, align 8
  call void @llvm.dbg.declare(metadata ptr %4, metadata !206, metadata !DIExpression()), !dbg !207
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !208, metadata !DIExpression()), !dbg !207
  store ptr %2, ptr %6, align 8
  call void @llvm.dbg.declare(metadata ptr %6, metadata !209, metadata !DIExpression()), !dbg !207
  %7 = load ptr, ptr %6, align 8, !dbg !210
  %8 = load ptr, ptr %4, align 8, !dbg !210
  %9 = load ptr, ptr %5, align 8, !dbg !210
  %10 = load ptr, ptr %6, align 8, !dbg !210
  call void @.omp_outlined._debug__(ptr %8, ptr %9, ptr %10) #4, !dbg !210
  ret void, !dbg !210
}

; Function Attrs: nounwind
declare i32 @__kmpc_global_thread_num(ptr) #4

; Function Attrs: nounwind
declare void @__kmpc_push_num_threads(ptr, i32, i32) #4

; Function Attrs: nounwind
declare !callback !211 void @__kmpc_fork_call(ptr, i32, ptr, ...) #4

declare i32 @MPI_Recv(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

declare i32 @parcoach_rma_MPI_Win_allocate(i64, i32, ptr, ptr, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Barrier(ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_free(ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_lock(i32, i32, i32, ptr, i32, ptr)

declare void @parcoach_rma_load(ptr, i64, i32, ptr)

declare i32 @parcoach_rma_MPI_Put(ptr, i32, ptr, i32, i64, i32, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_unlock(i32, ptr, i32, ptr)

declare void @parcoach_rma_store(ptr, i64, i32, ptr)

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { noinline norecurse nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }
attributes #5 = { convergent nounwind }

!llvm.dbg.cu = !{!22}
!llvm.module.flags = !{!57, !58, !59, !60, !61, !62, !63, !64}
!llvm.ident = !{!65}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 46, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/hybrid/022-MPI-hybrid-section-sendrecv-origin-remote-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "6de78362fb6ae1ed92e0bd55ecc9a19c")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 280, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 35)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 53, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 49)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 93, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 152, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 19)
!17 = !DIGlobalVariableExpression(var: !18, expr: !DIExpression())
!18 = distinct !DIGlobalVariable(scope: null, file: !2, line: 98, type: !19, isLocal: true, isDefinition: true)
!19 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !20)
!20 = !{!21}
!21 = !DISubrange(count: 94)
!22 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !23, retainedTypes: !32, globals: !56, splitDebugInlining: false, nameTableKind: None)
!23 = !{!24}
!24 = !DICompositeType(tag: DW_TAG_enumeration_type, file: !25, line: 708, baseType: !26, size: 32, elements: !27)
!25 = !DIFile(filename: "/usr/lib/x86_64-linux-gnu/openmpi/include/mpi.h", directory: "", checksumkind: CSK_MD5, checksum: "c3ca5be6f2c6a6e16d01846df47c0b49")
!26 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!27 = !{!28, !29, !30, !31}
!28 = !DIEnumerator(name: "MPI_THREAD_SINGLE", value: 0)
!29 = !DIEnumerator(name: "MPI_THREAD_FUNNELED", value: 1)
!30 = !DIEnumerator(name: "MPI_THREAD_SERIALIZED", value: 2)
!31 = !DIEnumerator(name: "MPI_THREAD_MULTIPLE", value: 3)
!32 = !{!33, !36, !37, !40, !43}
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
!43 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !44, size: 64)
!44 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Status", file: !25, line: 428, baseType: !45)
!45 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_status_public_t", file: !25, line: 438, size: 192, elements: !46)
!46 = !{!47, !49, !50, !51, !52}
!47 = !DIDerivedType(tag: DW_TAG_member, name: "MPI_SOURCE", scope: !45, file: !25, line: 441, baseType: !48, size: 32)
!48 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!49 = !DIDerivedType(tag: DW_TAG_member, name: "MPI_TAG", scope: !45, file: !25, line: 442, baseType: !48, size: 32, offset: 32)
!50 = !DIDerivedType(tag: DW_TAG_member, name: "MPI_ERROR", scope: !45, file: !25, line: 443, baseType: !48, size: 32, offset: 64)
!51 = !DIDerivedType(tag: DW_TAG_member, name: "_cancelled", scope: !45, file: !25, line: 448, baseType: !48, size: 32, offset: 96)
!52 = !DIDerivedType(tag: DW_TAG_member, name: "_ucount", scope: !45, file: !25, line: 449, baseType: !53, size: 64, offset: 128)
!53 = !DIDerivedType(tag: DW_TAG_typedef, name: "size_t", file: !54, line: 46, baseType: !55)
!54 = !DIFile(filename: "/usr/lib/llvm-15/lib/clang/15.0.6/include/stddef.h", directory: "", checksumkind: CSK_MD5, checksum: "b76978376d35d5cd171876ac58ac1256")
!55 = !DIBasicType(name: "unsigned long", size: 64, encoding: DW_ATE_unsigned)
!56 = !{!0, !7, !12, !17}
!57 = !{i32 7, !"Dwarf Version", i32 5}
!58 = !{i32 2, !"Debug Info Version", i32 3}
!59 = !{i32 1, !"wchar_size", i32 4}
!60 = !{i32 7, !"openmp", i32 50}
!61 = !{i32 7, !"PIC Level", i32 2}
!62 = !{i32 7, !"PIE Level", i32 2}
!63 = !{i32 7, !"uwtable", i32 2}
!64 = !{i32 7, !"frame-pointer", i32 2}
!65 = !{!"Debian clang version 15.0.6"}
!66 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 34, type: !67, scopeLine: 35, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !22, retainedNodes: !71)
!67 = !DISubroutineType(types: !68)
!68 = !{!48, !48, !69}
!69 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !70, size: 64)
!70 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!71 = !{}
!72 = !DILocalVariable(name: "argc", arg: 1, scope: !66, file: !2, line: 34, type: !48)
!73 = !DILocation(line: 34, column: 14, scope: !66)
!74 = !DILocalVariable(name: "argv", arg: 2, scope: !66, file: !2, line: 34, type: !69)
!75 = !DILocation(line: 34, column: 27, scope: !66)
!76 = !DILocalVariable(name: "rank", scope: !66, file: !2, line: 36, type: !48)
!77 = !DILocation(line: 36, column: 9, scope: !66)
!78 = !DILocalVariable(name: "size", scope: !66, file: !2, line: 36, type: !48)
!79 = !DILocation(line: 36, column: 15, scope: !66)
!80 = !DILocalVariable(name: "win", scope: !66, file: !2, line: 37, type: !81)
!81 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !25, line: 429, baseType: !82)
!82 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !83, size: 64)
!83 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !25, line: 429, flags: DIFlagFwdDecl)
!84 = !DILocation(line: 37, column: 13, scope: !66)
!85 = !DILocalVariable(name: "win_base", scope: !66, file: !2, line: 38, type: !86)
!86 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !48, size: 64)
!87 = !DILocation(line: 38, column: 10, scope: !66)
!88 = !DILocalVariable(name: "value", scope: !66, file: !2, line: 39, type: !48)
!89 = !DILocation(line: 39, column: 9, scope: !66)
!90 = !DILocalVariable(name: "value2", scope: !66, file: !2, line: 39, type: !48)
!91 = !DILocation(line: 39, column: 20, scope: !66)
!92 = !DILocalVariable(name: "result", scope: !66, file: !2, line: 40, type: !48)
!93 = !DILocation(line: 40, column: 9, scope: !66)
!94 = !DILocalVariable(name: "token", scope: !66, file: !2, line: 41, type: !48)
!95 = !DILocation(line: 41, column: 9, scope: !66)
!96 = !DILocalVariable(name: "provided", scope: !66, file: !2, line: 43, type: !48)
!97 = !DILocation(line: 43, column: 9, scope: !66)
!98 = !DILocation(line: 44, column: 5, scope: !66)
!99 = !DILocation(line: 45, column: 9, scope: !100)
!100 = distinct !DILexicalBlock(scope: !66, file: !2, line: 45, column: 9)
!101 = !DILocation(line: 45, column: 18, scope: !100)
!102 = !DILocation(line: 45, column: 9, scope: !66)
!103 = !DILocation(line: 46, column: 9, scope: !104)
!104 = distinct !DILexicalBlock(scope: !100, file: !2, line: 45, column: 41)
!105 = !DILocation(line: 47, column: 9, scope: !104)
!106 = !DILocation(line: 48, column: 5, scope: !104)
!107 = !DILocation(line: 49, column: 5, scope: !66)
!108 = !DILocation(line: 50, column: 5, scope: !66)
!109 = !DILocation(line: 52, column: 9, scope: !110)
!110 = distinct !DILexicalBlock(scope: !66, file: !2, line: 52, column: 9)
!111 = !DILocation(line: 52, column: 14, scope: !110)
!112 = !DILocation(line: 52, column: 9, scope: !66)
!113 = !DILocation(line: 53, column: 69, scope: !114)
!114 = distinct !DILexicalBlock(scope: !110, file: !2, line: 52, column: 27)
!115 = !DILocation(line: 53, column: 9, scope: !114)
!116 = !DILocation(line: 54, column: 9, scope: !114)
!117 = !DILocation(line: 55, column: 5, scope: !114)
!118 = !DILocation(line: 57, column: 5, scope: !66)
!119 = !DILocalVariable(name: "i", scope: !120, file: !2, line: 58, type: !48)
!120 = distinct !DILexicalBlock(scope: !66, file: !2, line: 58, column: 5)
!121 = !DILocation(line: 58, column: 14, scope: !120)
!122 = !DILocation(line: 58, column: 10, scope: !120)
!123 = !DILocation(line: 58, column: 21, scope: !124)
!124 = distinct !DILexicalBlock(scope: !120, file: !2, line: 58, column: 5)
!125 = !DILocation(line: 58, column: 23, scope: !124)
!126 = !DILocation(line: 58, column: 5, scope: !120)
!127 = !DILocation(line: 59, column: 9, scope: !128)
!128 = distinct !DILexicalBlock(scope: !124, file: !2, line: 58, column: 40)
!129 = !DILocation(line: 59, column: 18, scope: !128)
!130 = !DILocation(line: 59, column: 21, scope: !128)
!131 = !DILocation(line: 60, column: 5, scope: !128)
!132 = !DILocation(line: 58, column: 36, scope: !124)
!133 = !DILocation(line: 58, column: 5, scope: !124)
!134 = distinct !{!134, !126, !135, !136}
!135 = !DILocation(line: 60, column: 5, scope: !120)
!136 = !{!"llvm.loop.mustprogress"}
!137 = !DILocation(line: 61, column: 5, scope: !66)
!138 = !DILocation(line: 63, column: 9, scope: !139)
!139 = distinct !DILexicalBlock(scope: !66, file: !2, line: 63, column: 9)
!140 = !DILocation(line: 63, column: 14, scope: !139)
!141 = !DILocation(line: 63, column: 9, scope: !66)
!142 = !DILocation(line: 64, column: 1, scope: !143)
!143 = distinct !DILexicalBlock(scope: !139, file: !2, line: 63, column: 20)
!144 = !DILocation(line: 85, column: 5, scope: !143)
!145 = !DILocation(line: 87, column: 9, scope: !146)
!146 = distinct !DILexicalBlock(scope: !66, file: !2, line: 87, column: 9)
!147 = !DILocation(line: 87, column: 14, scope: !146)
!148 = !DILocation(line: 87, column: 9, scope: !66)
!149 = !DILocalVariable(name: "dummy", scope: !150, file: !2, line: 89, type: !48)
!150 = distinct !DILexicalBlock(scope: !151, file: !2, line: 88, column: 9)
!151 = distinct !DILexicalBlock(scope: !146, file: !2, line: 87, column: 20)
!152 = !DILocation(line: 89, column: 17, scope: !150)
!153 = !DILocation(line: 90, column: 13, scope: !150)
!154 = !DILocation(line: 93, column: 39, scope: !151)
!155 = !DILocation(line: 93, column: 9, scope: !151)
!156 = !DILocation(line: 94, column: 5, scope: !151)
!157 = !DILocation(line: 96, column: 5, scope: !66)
!158 = !DILocation(line: 99, column: 9, scope: !66)
!159 = !DILocation(line: 100, column: 9, scope: !66)
!160 = !DILocation(line: 101, column: 9, scope: !66)
!161 = !DILocation(line: 102, column: 9, scope: !66)
!162 = !DILocation(line: 97, column: 5, scope: !66)
!163 = !DILocation(line: 104, column: 5, scope: !66)
!164 = !DILocation(line: 105, column: 5, scope: !66)
!165 = !DILocation(line: 107, column: 5, scope: !66)
!166 = distinct !DISubprogram(name: ".omp_outlined._debug__", scope: !2, file: !2, line: 65, type: !167, scopeLine: 65, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !71)
!167 = !DISubroutineType(types: !168)
!168 = !{null, !169, !169, !173}
!169 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !170)
!170 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !171)
!171 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !172, size: 64)
!172 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !48)
!173 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !81, size: 64)
!174 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !166, type: !169, flags: DIFlagArtificial)
!175 = !DILocation(line: 0, scope: !166)
!176 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !166, type: !169, flags: DIFlagArtificial)
!177 = !DILocalVariable(name: "win", arg: 3, scope: !166, file: !2, line: 37, type: !173)
!178 = !DILocation(line: 37, column: 13, scope: !166)
!179 = !DILocation(line: 65, column: 9, scope: !166)
!180 = !DILocation(line: 66, column: 1, scope: !181)
!181 = distinct !DILexicalBlock(scope: !166, file: !2, line: 65, column: 9)
!182 = !DILocation(line: 66, column: 1, scope: !183)
!183 = distinct !DILexicalBlock(scope: !181, file: !2, line: 66, column: 1)
!184 = !DILocalVariable(name: "value", scope: !185, file: !2, line: 70, type: !48)
!185 = distinct !DILexicalBlock(scope: !186, file: !2, line: 69, column: 17)
!186 = distinct !DILexicalBlock(scope: !183, file: !2, line: 68, column: 1)
!187 = !DILocation(line: 70, column: 25, scope: !185)
!188 = !DILocation(line: 71, column: 60, scope: !185)
!189 = !DILocation(line: 71, column: 21, scope: !185)
!190 = !DILocation(line: 73, column: 67, scope: !185)
!191 = !DILocation(line: 73, column: 21, scope: !185)
!192 = !DILocation(line: 74, column: 39, scope: !185)
!193 = !DILocation(line: 74, column: 21, scope: !185)
!194 = !DILocation(line: 68, column: 20, scope: !186)
!195 = !DILocation(line: 79, column: 21, scope: !196)
!196 = distinct !DILexicalBlock(scope: !197, file: !2, line: 78, column: 17)
!197 = distinct !DILexicalBlock(scope: !183, file: !2, line: 77, column: 1)
!198 = !DILocalVariable(name: "dummy", scope: !196, file: !2, line: 80, type: !48)
!199 = !DILocation(line: 80, column: 25, scope: !196)
!200 = !DILocation(line: 81, column: 21, scope: !196)
!201 = !DILocation(line: 77, column: 20, scope: !197)
!202 = distinct !{!202, !182, !203}
!203 = !DILocation(line: 66, column: 21, scope: !183)
!204 = !DILocation(line: 84, column: 9, scope: !166)
!205 = distinct !DISubprogram(name: ".omp_outlined.", scope: !2, file: !2, line: 64, type: !167, scopeLine: 64, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !22, retainedNodes: !71)
!206 = !DILocalVariable(name: ".global_tid.", arg: 1, scope: !205, type: !169, flags: DIFlagArtificial)
!207 = !DILocation(line: 0, scope: !205)
!208 = !DILocalVariable(name: ".bound_tid.", arg: 2, scope: !205, type: !169, flags: DIFlagArtificial)
!209 = !DILocalVariable(name: "win", arg: 3, scope: !205, type: !173, flags: DIFlagArtificial)
!210 = !DILocation(line: 64, column: 1, scope: !205)
!211 = !{!212}
!212 = !{i64 2, i64 -1, i64 -1, i1 true}
