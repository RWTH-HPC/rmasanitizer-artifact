; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c.ll'
source_filename = "results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ompi_predefined_datatype_t = type opaque

@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !0
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@.str.1 = private unnamed_addr constant [19 x i8] c"win_base[0] is %d\0A\00", align 1, !dbg !7
@.str.2 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !12
@0 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@1 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@2 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@3 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@4 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@5 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@6 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@7 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@8 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@9 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@10 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@11 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@12 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@13 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@14 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@15 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@16 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1
@17 = private unnamed_addr constant [86 x i8] c"results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c\00", align 1

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
  store i32 0, ptr %3, align 4
  store i32 %0, ptr %4, align 4
  call void @llvm.dbg.declare(metadata ptr %4, metadata !59, metadata !DIExpression()), !dbg !60
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !61, metadata !DIExpression()), !dbg !62
  call void @llvm.dbg.declare(metadata ptr %6, metadata !63, metadata !DIExpression()), !dbg !64
  call void @llvm.dbg.declare(metadata ptr %7, metadata !65, metadata !DIExpression()), !dbg !66
  call void @llvm.dbg.declare(metadata ptr %8, metadata !67, metadata !DIExpression()), !dbg !71
  call void @llvm.dbg.declare(metadata ptr %9, metadata !72, metadata !DIExpression()), !dbg !74
  call void @llvm.dbg.declare(metadata ptr %10, metadata !75, metadata !DIExpression()), !dbg !76
  store i32 1, ptr %10, align 4, !dbg !76
  call void @llvm.dbg.declare(metadata ptr %11, metadata !77, metadata !DIExpression()), !dbg !78
  store i32 2, ptr %11, align 4, !dbg !78
  call void @llvm.dbg.declare(metadata ptr %12, metadata !79, metadata !DIExpression()), !dbg !80
  call void @llvm.dbg.declare(metadata ptr %13, metadata !81, metadata !DIExpression()), !dbg !82
  store i32 42, ptr %13, align 4, !dbg !82
  %15 = call i32 @MPI_Init(ptr noundef %4, ptr noundef %5), !dbg !83
  %16 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !84
  %17 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !85
  %18 = load i32, ptr %7, align 4, !dbg !86
  %19 = icmp ne i32 %18, 2, !dbg !88
  br i1 %19, label %20, label %24, !dbg !89

20:                                               ; preds = %2
  %21 = load i32, ptr %7, align 4, !dbg !90
  %22 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %21, i32 noundef 2), !dbg !92
  %23 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !93
  br label %24, !dbg !94

24:                                               ; preds = %20, %2
  %25 = call i32 @parcoach_rma_MPI_Win_allocate(i64 40, i32 4, ptr @ompi_mpi_info_null, ptr @ompi_mpi_comm_world, ptr %9, ptr %8, i32 51, ptr @0), !dbg !95
  call void @llvm.dbg.declare(metadata ptr %14, metadata !96, metadata !DIExpression()), !dbg !98
  store i32 0, ptr %14, align 4, !dbg !98
  br label %26, !dbg !99

26:                                               ; preds = %34, %24
  %27 = load i32, ptr %14, align 4, !dbg !100
  %28 = icmp slt i32 %27, 10, !dbg !102
  br i1 %28, label %29, label %37, !dbg !103

29:                                               ; preds = %26
  %30 = load ptr, ptr %9, align 8, !dbg !104
  %31 = load i32, ptr %14, align 4, !dbg !106
  %32 = sext i32 %31 to i64, !dbg !104
  %33 = getelementptr inbounds i32, ptr %30, i64 %32, !dbg !104
  store i32 0, ptr %33, align 4, !dbg !107
  br label %34, !dbg !108

34:                                               ; preds = %29
  call void @parcoach_rma_load(ptr %14, i64 32, i32 52, ptr @16), !dbg !109
  %35 = load i32, ptr %14, align 4, !dbg !109
  %36 = add nsw i32 %35, 1, !dbg !109
  call void @parcoach_rma_store(ptr %14, i64 32, i32 52, ptr @17), !dbg !109
  store i32 %36, ptr %14, align 4, !dbg !109
  br label %26, !dbg !110, !llvm.loop !111

37:                                               ; preds = %26
  %38 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 56, ptr @1), !dbg !114
  %39 = load i32, ptr %6, align 4, !dbg !115
  %40 = icmp eq i32 %39, 0, !dbg !117
  br i1 %40, label %41, label %49, !dbg !118

41:                                               ; preds = %37
  store i32 1, ptr %10, align 4, !dbg !119
  %42 = load ptr, ptr %8, align 8, !dbg !121
  %43 = call i32 @parcoach_rma_MPI_Win_lock(i32 2, i32 1, i32 0, ptr %42, i32 60, ptr @2), !dbg !122
  call void @parcoach_rma_load(ptr %8, i64 64, i32 62, ptr @3), !dbg !123
  %44 = load ptr, ptr %8, align 8, !dbg !123
  %45 = call i32 @parcoach_rma_MPI_Put(ptr %10, i32 1, ptr @ompi_mpi_int, i32 1, i64 0, i32 1, ptr @ompi_mpi_int, ptr %44, i32 62, ptr @4), !dbg !124
  %46 = load ptr, ptr %8, align 8, !dbg !125
  %47 = call i32 @parcoach_rma_MPI_Win_unlock(i32 1, ptr %46, i32 63, ptr @5), !dbg !126
  %48 = call i32 @MPI_Send(ptr noundef %13, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 1, i32 noundef 0, ptr noundef @ompi_mpi_comm_world), !dbg !127
  br label %49, !dbg !128

49:                                               ; preds = %41, %37
  call void @parcoach_rma_load(ptr %6, i64 32, i32 68, ptr @6), !dbg !129
  %50 = load i32, ptr %6, align 4, !dbg !129
  %51 = icmp eq i32 %50, 1, !dbg !131
  br i1 %51, label %52, label %58, !dbg !132

52:                                               ; preds = %49
  call void @parcoach_rma_load(ptr %9, i64 64, i32 70, ptr @7), !dbg !133
  %53 = load ptr, ptr %9, align 8, !dbg !133
  %54 = getelementptr inbounds i32, ptr %53, i64 0, !dbg !133
  call void @parcoach_rma_load(ptr %54, i64 32, i32 70, ptr @8), !dbg !133
  %55 = load i32, ptr %54, align 4, !dbg !133
  %56 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %55), !dbg !135
  %57 = call i32 @MPI_Recv(ptr noundef %13, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 0, i32 noundef 0, ptr noundef @ompi_mpi_comm_world, ptr noundef null), !dbg !136
  br label %58, !dbg !137

58:                                               ; preds = %52, %49
  %59 = call i32 @parcoach_rma_MPI_Barrier(ptr @ompi_mpi_comm_world, i32 74, ptr @9), !dbg !138
  call void @parcoach_rma_load(ptr %6, i64 32, i32 77, ptr @10), !dbg !139
  %60 = load i32, ptr %6, align 4, !dbg !139
  call void @parcoach_rma_load(ptr %10, i64 32, i32 78, ptr @11), !dbg !140
  %61 = load i32, ptr %10, align 4, !dbg !140
  call void @parcoach_rma_load(ptr %11, i64 32, i32 79, ptr @12), !dbg !141
  %62 = load i32, ptr %11, align 4, !dbg !141
  call void @parcoach_rma_load(ptr %9, i64 64, i32 80, ptr @13), !dbg !142
  %63 = load ptr, ptr %9, align 8, !dbg !142
  %64 = getelementptr inbounds i32, ptr %63, i64 0, !dbg !142
  call void @parcoach_rma_load(ptr %64, i64 32, i32 80, ptr @14), !dbg !142
  %65 = load i32, ptr %64, align 4, !dbg !142
  %66 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %60, i32 noundef %61, i32 noundef %62, i32 noundef %65), !dbg !143
  %67 = call i32 @parcoach_rma_MPI_Win_free(ptr %8, i32 82, ptr @15), !dbg !144
  %68 = call i32 @MPI_Finalize(), !dbg !145
  ret i32 0, !dbg !146
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

declare i32 @parcoach_rma_MPI_Win_free(ptr, i32, ptr)

declare void @parcoach_rma_store(ptr, i64, i32, ptr)

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!17}
!llvm.module.flags = !{!44, !45, !46, !47, !48, !49, !50, !51}
!llvm.ident = !{!52}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 47, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/sync/030-MPI-sync-lock-sendrecv-remote-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "f7472156b92515621299df1d79ef183d")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 49)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 70, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 152, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 19)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 76, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 94)
!17 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, retainedTypes: !18, globals: !43, splitDebugInlining: false, nameTableKind: None)
!18 = !{!19, !23, !24, !27, !30}
!19 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Comm", file: !20, line: 419, baseType: !21)
!20 = !DIFile(filename: "/usr/lib/x86_64-linux-gnu/openmpi/include/mpi.h", directory: "", checksumkind: CSK_MD5, checksum: "c3ca5be6f2c6a6e16d01846df47c0b49")
!21 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !22, size: 64)
!22 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_communicator_t", file: !20, line: 419, flags: DIFlagFwdDecl)
!23 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!24 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Info", file: !20, line: 424, baseType: !25)
!25 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !26, size: 64)
!26 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_info_t", file: !20, line: 424, flags: DIFlagFwdDecl)
!27 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Datatype", file: !20, line: 420, baseType: !28)
!28 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !29, size: 64)
!29 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_datatype_t", file: !20, line: 420, flags: DIFlagFwdDecl)
!30 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !31, size: 64)
!31 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Status", file: !20, line: 428, baseType: !32)
!32 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_status_public_t", file: !20, line: 438, size: 192, elements: !33)
!33 = !{!34, !36, !37, !38, !39}
!34 = !DIDerivedType(tag: DW_TAG_member, name: "MPI_SOURCE", scope: !32, file: !20, line: 441, baseType: !35, size: 32)
!35 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!36 = !DIDerivedType(tag: DW_TAG_member, name: "MPI_TAG", scope: !32, file: !20, line: 442, baseType: !35, size: 32, offset: 32)
!37 = !DIDerivedType(tag: DW_TAG_member, name: "MPI_ERROR", scope: !32, file: !20, line: 443, baseType: !35, size: 32, offset: 64)
!38 = !DIDerivedType(tag: DW_TAG_member, name: "_cancelled", scope: !32, file: !20, line: 448, baseType: !35, size: 32, offset: 96)
!39 = !DIDerivedType(tag: DW_TAG_member, name: "_ucount", scope: !32, file: !20, line: 449, baseType: !40, size: 64, offset: 128)
!40 = !DIDerivedType(tag: DW_TAG_typedef, name: "size_t", file: !41, line: 46, baseType: !42)
!41 = !DIFile(filename: "/usr/lib/llvm-15/lib/clang/15.0.6/include/stddef.h", directory: "", checksumkind: CSK_MD5, checksum: "b76978376d35d5cd171876ac58ac1256")
!42 = !DIBasicType(name: "unsigned long", size: 64, encoding: DW_ATE_unsigned)
!43 = !{!0, !7, !12}
!44 = !{i32 7, !"Dwarf Version", i32 5}
!45 = !{i32 2, !"Debug Info Version", i32 3}
!46 = !{i32 1, !"wchar_size", i32 4}
!47 = !{i32 7, !"openmp", i32 50}
!48 = !{i32 7, !"PIC Level", i32 2}
!49 = !{i32 7, !"PIE Level", i32 2}
!50 = !{i32 7, !"uwtable", i32 2}
!51 = !{i32 7, !"frame-pointer", i32 2}
!52 = !{!"Debian clang version 15.0.6"}
!53 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 33, type: !54, scopeLine: 34, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !58)
!54 = !DISubroutineType(types: !55)
!55 = !{!35, !35, !56}
!56 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !57, size: 64)
!57 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!58 = !{}
!59 = !DILocalVariable(name: "argc", arg: 1, scope: !53, file: !2, line: 33, type: !35)
!60 = !DILocation(line: 33, column: 14, scope: !53)
!61 = !DILocalVariable(name: "argv", arg: 2, scope: !53, file: !2, line: 33, type: !56)
!62 = !DILocation(line: 33, column: 27, scope: !53)
!63 = !DILocalVariable(name: "rank", scope: !53, file: !2, line: 35, type: !35)
!64 = !DILocation(line: 35, column: 9, scope: !53)
!65 = !DILocalVariable(name: "size", scope: !53, file: !2, line: 35, type: !35)
!66 = !DILocation(line: 35, column: 15, scope: !53)
!67 = !DILocalVariable(name: "win", scope: !53, file: !2, line: 36, type: !68)
!68 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !20, line: 429, baseType: !69)
!69 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !70, size: 64)
!70 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !20, line: 429, flags: DIFlagFwdDecl)
!71 = !DILocation(line: 36, column: 13, scope: !53)
!72 = !DILocalVariable(name: "win_base", scope: !53, file: !2, line: 37, type: !73)
!73 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !35, size: 64)
!74 = !DILocation(line: 37, column: 10, scope: !53)
!75 = !DILocalVariable(name: "value", scope: !53, file: !2, line: 38, type: !35)
!76 = !DILocation(line: 38, column: 9, scope: !53)
!77 = !DILocalVariable(name: "value2", scope: !53, file: !2, line: 38, type: !35)
!78 = !DILocation(line: 38, column: 20, scope: !53)
!79 = !DILocalVariable(name: "result", scope: !53, file: !2, line: 39, type: !35)
!80 = !DILocation(line: 39, column: 9, scope: !53)
!81 = !DILocalVariable(name: "token", scope: !53, file: !2, line: 40, type: !35)
!82 = !DILocation(line: 40, column: 9, scope: !53)
!83 = !DILocation(line: 42, column: 5, scope: !53)
!84 = !DILocation(line: 43, column: 5, scope: !53)
!85 = !DILocation(line: 44, column: 5, scope: !53)
!86 = !DILocation(line: 46, column: 9, scope: !87)
!87 = distinct !DILexicalBlock(scope: !53, file: !2, line: 46, column: 9)
!88 = !DILocation(line: 46, column: 14, scope: !87)
!89 = !DILocation(line: 46, column: 9, scope: !53)
!90 = !DILocation(line: 47, column: 69, scope: !91)
!91 = distinct !DILexicalBlock(scope: !87, file: !2, line: 46, column: 27)
!92 = !DILocation(line: 47, column: 9, scope: !91)
!93 = !DILocation(line: 48, column: 9, scope: !91)
!94 = !DILocation(line: 49, column: 5, scope: !91)
!95 = !DILocation(line: 51, column: 5, scope: !53)
!96 = !DILocalVariable(name: "i", scope: !97, file: !2, line: 52, type: !35)
!97 = distinct !DILexicalBlock(scope: !53, file: !2, line: 52, column: 5)
!98 = !DILocation(line: 52, column: 14, scope: !97)
!99 = !DILocation(line: 52, column: 10, scope: !97)
!100 = !DILocation(line: 52, column: 21, scope: !101)
!101 = distinct !DILexicalBlock(scope: !97, file: !2, line: 52, column: 5)
!102 = !DILocation(line: 52, column: 23, scope: !101)
!103 = !DILocation(line: 52, column: 5, scope: !97)
!104 = !DILocation(line: 53, column: 9, scope: !105)
!105 = distinct !DILexicalBlock(scope: !101, file: !2, line: 52, column: 40)
!106 = !DILocation(line: 53, column: 18, scope: !105)
!107 = !DILocation(line: 53, column: 21, scope: !105)
!108 = !DILocation(line: 54, column: 5, scope: !105)
!109 = !DILocation(line: 52, column: 36, scope: !101)
!110 = !DILocation(line: 52, column: 5, scope: !101)
!111 = distinct !{!111, !103, !112, !113}
!112 = !DILocation(line: 54, column: 5, scope: !97)
!113 = !{!"llvm.loop.mustprogress"}
!114 = !DILocation(line: 56, column: 5, scope: !53)
!115 = !DILocation(line: 58, column: 9, scope: !116)
!116 = distinct !DILexicalBlock(scope: !53, file: !2, line: 58, column: 9)
!117 = !DILocation(line: 58, column: 14, scope: !116)
!118 = !DILocation(line: 58, column: 9, scope: !53)
!119 = !DILocation(line: 59, column: 15, scope: !120)
!120 = distinct !DILexicalBlock(scope: !116, file: !2, line: 58, column: 20)
!121 = !DILocation(line: 60, column: 45, scope: !120)
!122 = !DILocation(line: 60, column: 9, scope: !120)
!123 = !DILocation(line: 62, column: 55, scope: !120)
!124 = !DILocation(line: 62, column: 9, scope: !120)
!125 = !DILocation(line: 63, column: 27, scope: !120)
!126 = !DILocation(line: 63, column: 9, scope: !120)
!127 = !DILocation(line: 65, column: 9, scope: !120)
!128 = !DILocation(line: 66, column: 5, scope: !120)
!129 = !DILocation(line: 68, column: 9, scope: !130)
!130 = distinct !DILexicalBlock(scope: !53, file: !2, line: 68, column: 9)
!131 = !DILocation(line: 68, column: 14, scope: !130)
!132 = !DILocation(line: 68, column: 9, scope: !53)
!133 = !DILocation(line: 70, column: 39, scope: !134)
!134 = distinct !DILexicalBlock(scope: !130, file: !2, line: 68, column: 20)
!135 = !DILocation(line: 70, column: 9, scope: !134)
!136 = !DILocation(line: 71, column: 9, scope: !134)
!137 = !DILocation(line: 72, column: 5, scope: !134)
!138 = !DILocation(line: 74, column: 5, scope: !53)
!139 = !DILocation(line: 77, column: 9, scope: !53)
!140 = !DILocation(line: 78, column: 9, scope: !53)
!141 = !DILocation(line: 79, column: 9, scope: !53)
!142 = !DILocation(line: 80, column: 9, scope: !53)
!143 = !DILocation(line: 75, column: 5, scope: !53)
!144 = !DILocation(line: 82, column: 5, scope: !53)
!145 = !DILocation(line: 83, column: 5, scope: !53)
!146 = !DILocation(line: 85, column: 5, scope: !53)
