; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c.ll'
source_filename = "results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ompi_predefined_datatype_t = type opaque

@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !0
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@.str.1 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !7
@0 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@1 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@2 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@3 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@4 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@5 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@6 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@7 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@8 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@9 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@10 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@11 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@12 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@13 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@14 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@15 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1
@16 = private unnamed_addr constant [92 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !48 {
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
  store i32 0, ptr %3, align 4
  store i32 %0, ptr %4, align 4
  call void @llvm.dbg.declare(metadata ptr %4, metadata !54, metadata !DIExpression()), !dbg !55
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !56, metadata !DIExpression()), !dbg !57
  call void @llvm.dbg.declare(metadata ptr %6, metadata !58, metadata !DIExpression()), !dbg !59
  call void @llvm.dbg.declare(metadata ptr %7, metadata !60, metadata !DIExpression()), !dbg !61
  call void @llvm.dbg.declare(metadata ptr %8, metadata !62, metadata !DIExpression()), !dbg !66
  call void @llvm.dbg.declare(metadata ptr %9, metadata !67, metadata !DIExpression()), !dbg !69
  call void @llvm.dbg.declare(metadata ptr %10, metadata !70, metadata !DIExpression()), !dbg !71
  store i32 1, ptr %10, align 4, !dbg !71
  call void @llvm.dbg.declare(metadata ptr %11, metadata !72, metadata !DIExpression()), !dbg !73
  store i32 2, ptr %11, align 4, !dbg !73
  call void @llvm.dbg.declare(metadata ptr %12, metadata !74, metadata !DIExpression()), !dbg !75
  call void @llvm.dbg.declare(metadata ptr %13, metadata !76, metadata !DIExpression()), !dbg !77
  store i32 42, ptr %13, align 4, !dbg !77
  %15 = call i32 @MPI_Init(ptr noundef %4, ptr noundef %5), !dbg !78
  %16 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !79
  %17 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !80
  %18 = load i32, ptr %7, align 4, !dbg !81
  %19 = icmp ne i32 %18, 3, !dbg !83
  br i1 %19, label %20, label %24, !dbg !84

20:                                               ; preds = %2
  %21 = load i32, ptr %7, align 4, !dbg !85
  %22 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %21, i32 noundef 3), !dbg !87
  %23 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !88
  br label %24, !dbg !89

24:                                               ; preds = %20, %2
  %25 = call i32 @parcoach_rma_MPI_Win_allocate(i64 40, i32 4, ptr @ompi_mpi_info_null, ptr @ompi_mpi_comm_world, ptr %9, ptr %8, i32 48, ptr @0), !dbg !90
  call void @llvm.dbg.declare(metadata ptr %14, metadata !91, metadata !DIExpression()), !dbg !93
  store i32 0, ptr %14, align 4, !dbg !93
  br label %26, !dbg !94

26:                                               ; preds = %34, %24
  %27 = load i32, ptr %14, align 4, !dbg !95
  %28 = icmp slt i32 %27, 10, !dbg !97
  br i1 %28, label %29, label %37, !dbg !98

29:                                               ; preds = %26
  %30 = load ptr, ptr %9, align 8, !dbg !99
  %31 = load i32, ptr %14, align 4, !dbg !101
  %32 = sext i32 %31 to i64, !dbg !99
  %33 = getelementptr inbounds i32, ptr %30, i64 %32, !dbg !99
  store i32 0, ptr %33, align 4, !dbg !102
  br label %34, !dbg !103

34:                                               ; preds = %29
  %35 = load i32, ptr %14, align 4, !dbg !104
  %36 = add nsw i32 %35, 1, !dbg !104
  store i32 %36, ptr %14, align 4, !dbg !104
  br label %26, !dbg !105, !llvm.loop !106

37:                                               ; preds = %26
  %38 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 53, ptr @1), !dbg !109
  %39 = load i32, ptr %6, align 4, !dbg !110
  %40 = icmp eq i32 %39, 0, !dbg !112
  br i1 %40, label %41, label %49, !dbg !113

41:                                               ; preds = %37
  store i32 1, ptr %10, align 4, !dbg !114
  %42 = load ptr, ptr %8, align 8, !dbg !116
  %43 = call i32 @parcoach_rma_MPI_Win_lock(i32 2, i32 1, i32 0, ptr %42, i32 57, ptr @2), !dbg !117
  call void @parcoach_rma_load(ptr %8, i64 64, i32 58, ptr @3), !dbg !118
  %44 = load ptr, ptr %8, align 8, !dbg !118
  %45 = call i32 @parcoach_rma_MPI_Put(ptr %10, i32 1, ptr @ompi_mpi_int, i32 1, i64 0, i32 1, ptr @ompi_mpi_int, ptr %44, i32 58, ptr @4), !dbg !119
  %46 = load ptr, ptr %8, align 8, !dbg !120
  %47 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %46, i32 59, ptr @5), !dbg !121
  %48 = call i32 @MPI_Send(ptr noundef %13, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 2, i32 noundef 0, ptr noundef @ompi_mpi_comm_world), !dbg !122
  br label %49, !dbg !123

49:                                               ; preds = %41, %37
  call void @parcoach_rma_load(ptr %6, i64 32, i32 64, ptr @6), !dbg !124
  %50 = load i32, ptr %6, align 4, !dbg !124
  %51 = icmp eq i32 %50, 1, !dbg !126
  br i1 %51, label %52, label %53, !dbg !127

52:                                               ; preds = %49
  br label %53, !dbg !128

53:                                               ; preds = %52, %49
  call void @parcoach_rma_load(ptr %6, i64 32, i32 68, ptr @7), !dbg !130
  %54 = load i32, ptr %6, align 4, !dbg !130
  %55 = icmp eq i32 %54, 2, !dbg !132
  br i1 %55, label %56, label %64, !dbg !133

56:                                               ; preds = %53
  %57 = call i32 @MPI_Recv(ptr noundef %13, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 0, i32 noundef 0, ptr noundef @ompi_mpi_comm_world, ptr noundef null), !dbg !134
  call void @parcoach_rma_store(ptr %10, i64 32, i32 72, ptr @8), !dbg !136
  store i32 1, ptr %10, align 4, !dbg !136
  call void @parcoach_rma_load(ptr %8, i64 64, i32 73, ptr @9), !dbg !137
  %58 = load ptr, ptr %8, align 8, !dbg !137
  %59 = call i32 @parcoach_rma_MPI_Win_lock(i32 2, i32 1, i32 0, ptr %58, i32 73, ptr @10), !dbg !138
  call void @parcoach_rma_load(ptr %8, i64 64, i32 74, ptr @11), !dbg !139
  %60 = load ptr, ptr %8, align 8, !dbg !139
  %61 = call i32 @parcoach_rma_MPI_Put(ptr %10, i32 1, ptr @ompi_mpi_int, i32 1, i64 0, i32 1, ptr @ompi_mpi_int, ptr %60, i32 74, ptr @12), !dbg !140
  call void @parcoach_rma_load(ptr %8, i64 64, i32 75, ptr @13), !dbg !141
  %62 = load ptr, ptr %8, align 8, !dbg !141
  %63 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %62, i32 75, ptr @14), !dbg !142
  br label %64, !dbg !143

64:                                               ; preds = %56, %53
  %65 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 78, ptr @15), !dbg !144
  %66 = load i32, ptr %6, align 4, !dbg !145
  %67 = load i32, ptr %10, align 4, !dbg !146
  %68 = load i32, ptr %11, align 4, !dbg !147
  %69 = load ptr, ptr %9, align 8, !dbg !148
  %70 = getelementptr inbounds i32, ptr %69, i64 0, !dbg !148
  %71 = load i32, ptr %70, align 4, !dbg !148
  %72 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %66, i32 noundef %67, i32 noundef %68, i32 noundef %71), !dbg !149
  %73 = call i32 @parcoach_rma_MPI_Win_free(ptr %8, i32 86, ptr @16), !dbg !150
  %74 = call i32 @MPI_Finalize(), !dbg !151
  ret i32 0, !dbg !152
}

; Function Attrs: nocallback nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @MPI_Init(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_rank(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_size(ptr noundef, ptr noundef) #2

declare i32 @printf(ptr noundef, ...) #2

declare i32 @MPI_Abort(ptr noundef, i32 noundef) #2

declare i32 @MPI_Win_allocate(i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Barrier(ptr noundef) #2

declare i32 @MPI_Win_lock(i32 noundef, i32 noundef, i32 noundef, ptr noundef) #2

declare i32 @MPI_Put(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_unlock(i32 noundef, ptr noundef) #2

declare i32 @MPI_Send(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i32 noundef, ptr noundef) #2

declare i32 @MPI_Recv(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

declare i32 @parcoach_rma_MPI_Win_allocate(i64, i32, ptr, ptr, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Barrier(ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_lock(i32, i32, i32, ptr, i32, ptr)

declare void @parcoach_rma_load(ptr, i64, i32, ptr)

declare i32 @parcoach_rma_MPI_Put(ptr, i32, ptr, i32, i64, i32, ptr, ptr, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_unlock(i32, ptr, i32, ptr)

declare void @parcoach_rma_store(ptr, i64, i32, ptr)

declare i32 @parcoach_rma_MPI_Win_free(ptr, i32, ptr)

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!12}
!llvm.module.flags = !{!39, !40, !41, !42, !43, !44, !45, !46}
!llvm.ident = !{!47}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 44, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/sync/032-MPI-sync-lock-sendrecv-3procs-remote-no.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "c00f85c0d366ec5eacc3b68177132c9b")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 49)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 80, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 94)
!12 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, retainedTypes: !13, globals: !38, splitDebugInlining: false, nameTableKind: None)
!13 = !{!14, !18, !19, !22, !25}
!14 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Comm", file: !15, line: 419, baseType: !16)
!15 = !DIFile(filename: "/usr/lib/x86_64-linux-gnu/openmpi/include/mpi.h", directory: "", checksumkind: CSK_MD5, checksum: "c3ca5be6f2c6a6e16d01846df47c0b49")
!16 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !17, size: 64)
!17 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_communicator_t", file: !15, line: 419, flags: DIFlagFwdDecl)
!18 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!19 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Info", file: !15, line: 424, baseType: !20)
!20 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !21, size: 64)
!21 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_info_t", file: !15, line: 424, flags: DIFlagFwdDecl)
!22 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Datatype", file: !15, line: 420, baseType: !23)
!23 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !24, size: 64)
!24 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_datatype_t", file: !15, line: 420, flags: DIFlagFwdDecl)
!25 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !26, size: 64)
!26 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Status", file: !15, line: 428, baseType: !27)
!27 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_status_public_t", file: !15, line: 438, size: 192, elements: !28)
!28 = !{!29, !31, !32, !33, !34}
!29 = !DIDerivedType(tag: DW_TAG_member, name: "MPI_SOURCE", scope: !27, file: !15, line: 441, baseType: !30, size: 32)
!30 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!31 = !DIDerivedType(tag: DW_TAG_member, name: "MPI_TAG", scope: !27, file: !15, line: 442, baseType: !30, size: 32, offset: 32)
!32 = !DIDerivedType(tag: DW_TAG_member, name: "MPI_ERROR", scope: !27, file: !15, line: 443, baseType: !30, size: 32, offset: 64)
!33 = !DIDerivedType(tag: DW_TAG_member, name: "_cancelled", scope: !27, file: !15, line: 448, baseType: !30, size: 32, offset: 96)
!34 = !DIDerivedType(tag: DW_TAG_member, name: "_ucount", scope: !27, file: !15, line: 449, baseType: !35, size: 64, offset: 128)
!35 = !DIDerivedType(tag: DW_TAG_typedef, name: "size_t", file: !36, line: 46, baseType: !37)
!36 = !DIFile(filename: "/usr/lib/llvm-15/lib/clang/15.0.6/include/stddef.h", directory: "", checksumkind: CSK_MD5, checksum: "b76978376d35d5cd171876ac58ac1256")
!37 = !DIBasicType(name: "unsigned long", size: 64, encoding: DW_ATE_unsigned)
!38 = !{!0, !7}
!39 = !{i32 7, !"Dwarf Version", i32 5}
!40 = !{i32 2, !"Debug Info Version", i32 3}
!41 = !{i32 1, !"wchar_size", i32 4}
!42 = !{i32 7, !"openmp", i32 50}
!43 = !{i32 7, !"PIC Level", i32 2}
!44 = !{i32 7, !"PIE Level", i32 2}
!45 = !{i32 7, !"uwtable", i32 2}
!46 = !{i32 7, !"frame-pointer", i32 2}
!47 = !{!"Debian clang version 15.0.6"}
!48 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 30, type: !49, scopeLine: 31, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !12, retainedNodes: !53)
!49 = !DISubroutineType(types: !50)
!50 = !{!30, !30, !51}
!51 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !52, size: 64)
!52 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!53 = !{}
!54 = !DILocalVariable(name: "argc", arg: 1, scope: !48, file: !2, line: 30, type: !30)
!55 = !DILocation(line: 30, column: 14, scope: !48)
!56 = !DILocalVariable(name: "argv", arg: 2, scope: !48, file: !2, line: 30, type: !51)
!57 = !DILocation(line: 30, column: 27, scope: !48)
!58 = !DILocalVariable(name: "rank", scope: !48, file: !2, line: 32, type: !30)
!59 = !DILocation(line: 32, column: 9, scope: !48)
!60 = !DILocalVariable(name: "size", scope: !48, file: !2, line: 32, type: !30)
!61 = !DILocation(line: 32, column: 15, scope: !48)
!62 = !DILocalVariable(name: "win", scope: !48, file: !2, line: 33, type: !63)
!63 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !15, line: 429, baseType: !64)
!64 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !65, size: 64)
!65 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !15, line: 429, flags: DIFlagFwdDecl)
!66 = !DILocation(line: 33, column: 13, scope: !48)
!67 = !DILocalVariable(name: "win_base", scope: !48, file: !2, line: 34, type: !68)
!68 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !30, size: 64)
!69 = !DILocation(line: 34, column: 10, scope: !48)
!70 = !DILocalVariable(name: "value", scope: !48, file: !2, line: 35, type: !30)
!71 = !DILocation(line: 35, column: 9, scope: !48)
!72 = !DILocalVariable(name: "value2", scope: !48, file: !2, line: 35, type: !30)
!73 = !DILocation(line: 35, column: 20, scope: !48)
!74 = !DILocalVariable(name: "result", scope: !48, file: !2, line: 36, type: !30)
!75 = !DILocation(line: 36, column: 9, scope: !48)
!76 = !DILocalVariable(name: "token", scope: !48, file: !2, line: 37, type: !30)
!77 = !DILocation(line: 37, column: 9, scope: !48)
!78 = !DILocation(line: 39, column: 5, scope: !48)
!79 = !DILocation(line: 40, column: 5, scope: !48)
!80 = !DILocation(line: 41, column: 5, scope: !48)
!81 = !DILocation(line: 43, column: 9, scope: !82)
!82 = distinct !DILexicalBlock(scope: !48, file: !2, line: 43, column: 9)
!83 = !DILocation(line: 43, column: 14, scope: !82)
!84 = !DILocation(line: 43, column: 9, scope: !48)
!85 = !DILocation(line: 44, column: 69, scope: !86)
!86 = distinct !DILexicalBlock(scope: !82, file: !2, line: 43, column: 27)
!87 = !DILocation(line: 44, column: 9, scope: !86)
!88 = !DILocation(line: 45, column: 9, scope: !86)
!89 = !DILocation(line: 46, column: 5, scope: !86)
!90 = !DILocation(line: 48, column: 5, scope: !48)
!91 = !DILocalVariable(name: "i", scope: !92, file: !2, line: 49, type: !30)
!92 = distinct !DILexicalBlock(scope: !48, file: !2, line: 49, column: 5)
!93 = !DILocation(line: 49, column: 14, scope: !92)
!94 = !DILocation(line: 49, column: 10, scope: !92)
!95 = !DILocation(line: 49, column: 21, scope: !96)
!96 = distinct !DILexicalBlock(scope: !92, file: !2, line: 49, column: 5)
!97 = !DILocation(line: 49, column: 23, scope: !96)
!98 = !DILocation(line: 49, column: 5, scope: !92)
!99 = !DILocation(line: 50, column: 9, scope: !100)
!100 = distinct !DILexicalBlock(scope: !96, file: !2, line: 49, column: 40)
!101 = !DILocation(line: 50, column: 18, scope: !100)
!102 = !DILocation(line: 50, column: 21, scope: !100)
!103 = !DILocation(line: 51, column: 5, scope: !100)
!104 = !DILocation(line: 49, column: 36, scope: !96)
!105 = !DILocation(line: 49, column: 5, scope: !96)
!106 = distinct !{!106, !98, !107, !108}
!107 = !DILocation(line: 51, column: 5, scope: !92)
!108 = !{!"llvm.loop.mustprogress"}
!109 = !DILocation(line: 53, column: 5, scope: !48)
!110 = !DILocation(line: 55, column: 9, scope: !111)
!111 = distinct !DILexicalBlock(scope: !48, file: !2, line: 55, column: 9)
!112 = !DILocation(line: 55, column: 14, scope: !111)
!113 = !DILocation(line: 55, column: 9, scope: !48)
!114 = !DILocation(line: 56, column: 15, scope: !115)
!115 = distinct !DILexicalBlock(scope: !111, file: !2, line: 55, column: 20)
!116 = !DILocation(line: 57, column: 45, scope: !115)
!117 = !DILocation(line: 57, column: 9, scope: !115)
!118 = !DILocation(line: 58, column: 55, scope: !115)
!119 = !DILocation(line: 58, column: 9, scope: !115)
!120 = !DILocation(line: 59, column: 27, scope: !115)
!121 = !DILocation(line: 59, column: 9, scope: !115)
!122 = !DILocation(line: 61, column: 9, scope: !115)
!123 = !DILocation(line: 62, column: 5, scope: !115)
!124 = !DILocation(line: 64, column: 9, scope: !125)
!125 = distinct !DILexicalBlock(scope: !48, file: !2, line: 64, column: 9)
!126 = !DILocation(line: 64, column: 14, scope: !125)
!127 = !DILocation(line: 64, column: 9, scope: !48)
!128 = !DILocation(line: 66, column: 5, scope: !129)
!129 = distinct !DILexicalBlock(scope: !125, file: !2, line: 64, column: 20)
!130 = !DILocation(line: 68, column: 9, scope: !131)
!131 = distinct !DILexicalBlock(scope: !48, file: !2, line: 68, column: 9)
!132 = !DILocation(line: 68, column: 14, scope: !131)
!133 = !DILocation(line: 68, column: 9, scope: !48)
!134 = !DILocation(line: 70, column: 9, scope: !135)
!135 = distinct !DILexicalBlock(scope: !131, file: !2, line: 68, column: 20)
!136 = !DILocation(line: 72, column: 15, scope: !135)
!137 = !DILocation(line: 73, column: 45, scope: !135)
!138 = !DILocation(line: 73, column: 9, scope: !135)
!139 = !DILocation(line: 74, column: 55, scope: !135)
!140 = !DILocation(line: 74, column: 9, scope: !135)
!141 = !DILocation(line: 75, column: 27, scope: !135)
!142 = !DILocation(line: 75, column: 9, scope: !135)
!143 = !DILocation(line: 76, column: 5, scope: !135)
!144 = !DILocation(line: 78, column: 5, scope: !48)
!145 = !DILocation(line: 81, column: 9, scope: !48)
!146 = !DILocation(line: 82, column: 9, scope: !48)
!147 = !DILocation(line: 83, column: 9, scope: !48)
!148 = !DILocation(line: 84, column: 9, scope: !48)
!149 = !DILocation(line: 79, column: 5, scope: !48)
!150 = !DILocation(line: 86, column: 5, scope: !48)
!151 = !DILocation(line: 87, column: 5, scope: !48)
!152 = !DILocation(line: 89, column: 5, scope: !48)
