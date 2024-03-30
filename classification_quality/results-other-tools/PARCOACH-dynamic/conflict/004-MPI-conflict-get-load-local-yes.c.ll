; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/conflict/004-MPI-conflict-get-load-local-yes.c'
source_filename = "results-20240330-164421/PARCOACH-dynamic/conflict/004-MPI-conflict-get-load-local-yes.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ompi_predefined_datatype_t = type opaque

@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !0
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@.str.1 = private unnamed_addr constant [13 x i8] c"value is %d\0A\00", align 1, !dbg !7
@.str.2 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !12

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !40 {
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
  call void @llvm.dbg.declare(metadata ptr %4, metadata !47, metadata !DIExpression()), !dbg !48
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !49, metadata !DIExpression()), !dbg !50
  call void @llvm.dbg.declare(metadata ptr %6, metadata !51, metadata !DIExpression()), !dbg !52
  call void @llvm.dbg.declare(metadata ptr %7, metadata !53, metadata !DIExpression()), !dbg !54
  call void @llvm.dbg.declare(metadata ptr %8, metadata !55, metadata !DIExpression()), !dbg !59
  call void @llvm.dbg.declare(metadata ptr %9, metadata !60, metadata !DIExpression()), !dbg !62
  call void @llvm.dbg.declare(metadata ptr %10, metadata !63, metadata !DIExpression()), !dbg !64
  store i32 1, ptr %10, align 4, !dbg !64
  call void @llvm.dbg.declare(metadata ptr %11, metadata !65, metadata !DIExpression()), !dbg !66
  store i32 2, ptr %11, align 4, !dbg !66
  call void @llvm.dbg.declare(metadata ptr %12, metadata !67, metadata !DIExpression()), !dbg !68
  call void @llvm.dbg.declare(metadata ptr %13, metadata !69, metadata !DIExpression()), !dbg !70
  store i32 42, ptr %13, align 4, !dbg !70
  %15 = call i32 @MPI_Init(ptr noundef %4, ptr noundef %5), !dbg !71
  %16 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !72
  %17 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !73
  %18 = load i32, ptr %7, align 4, !dbg !74
  %19 = icmp ne i32 %18, 2, !dbg !76
  br i1 %19, label %20, label %24, !dbg !77

20:                                               ; preds = %2
  %21 = load i32, ptr %7, align 4, !dbg !78
  %22 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %21, i32 noundef 2), !dbg !80
  %23 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !81
  br label %24, !dbg !82

24:                                               ; preds = %20, %2
  %25 = call i32 @MPI_Win_allocate(i64 noundef 40, i32 noundef 4, ptr noundef @ompi_mpi_info_null, ptr noundef @ompi_mpi_comm_world, ptr noundef %9, ptr noundef %8), !dbg !83
  call void @llvm.dbg.declare(metadata ptr %14, metadata !84, metadata !DIExpression()), !dbg !86
  store i32 0, ptr %14, align 4, !dbg !86
  br label %26, !dbg !87

26:                                               ; preds = %34, %24
  %27 = load i32, ptr %14, align 4, !dbg !88
  %28 = icmp slt i32 %27, 10, !dbg !90
  br i1 %28, label %29, label %37, !dbg !91

29:                                               ; preds = %26
  %30 = load ptr, ptr %9, align 8, !dbg !92
  %31 = load i32, ptr %14, align 4, !dbg !94
  %32 = sext i32 %31 to i64, !dbg !92
  %33 = getelementptr inbounds i32, ptr %30, i64 %32, !dbg !92
  store i32 0, ptr %33, align 4, !dbg !95
  br label %34, !dbg !96

34:                                               ; preds = %29
  %35 = load i32, ptr %14, align 4, !dbg !97
  %36 = add nsw i32 %35, 1, !dbg !97
  store i32 %36, ptr %14, align 4, !dbg !97
  br label %26, !dbg !98, !llvm.loop !99

37:                                               ; preds = %26
  %38 = load ptr, ptr %8, align 8, !dbg !102
  %39 = call i32 @MPI_Win_fence(i32 noundef 0, ptr noundef %38), !dbg !103
  %40 = load i32, ptr %6, align 4, !dbg !104
  %41 = icmp eq i32 %40, 0, !dbg !106
  br i1 %41, label %42, label %47, !dbg !107

42:                                               ; preds = %37
  %43 = load ptr, ptr %8, align 8, !dbg !108
  %44 = call i32 @MPI_Get(ptr noundef %10, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 1, i64 noundef 0, i32 noundef 1, ptr noundef @ompi_mpi_int, ptr noundef %43), !dbg !110
  %45 = load i32, ptr %10, align 4, !dbg !111
  %46 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %45), !dbg !112
  br label %47, !dbg !113

47:                                               ; preds = %42, %37
  %48 = load ptr, ptr %8, align 8, !dbg !114
  %49 = call i32 @MPI_Win_fence(i32 noundef 0, ptr noundef %48), !dbg !115
  %50 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !116
  %51 = load i32, ptr %6, align 4, !dbg !117
  %52 = load i32, ptr %10, align 4, !dbg !118
  %53 = load i32, ptr %11, align 4, !dbg !119
  %54 = load ptr, ptr %9, align 8, !dbg !120
  %55 = getelementptr inbounds i32, ptr %54, i64 0, !dbg !120
  %56 = load i32, ptr %55, align 4, !dbg !120
  %57 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %51, i32 noundef %52, i32 noundef %53, i32 noundef %56), !dbg !121
  %58 = call i32 @MPI_Win_free(ptr noundef %8), !dbg !122
  %59 = call i32 @MPI_Finalize(), !dbg !123
  ret i32 0, !dbg !124
}

; Function Attrs: nocallback nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @MPI_Init(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_rank(ptr noundef, ptr noundef) #2

declare i32 @MPI_Comm_size(ptr noundef, ptr noundef) #2

declare i32 @printf(ptr noundef, ...) #2

declare i32 @MPI_Abort(ptr noundef, i32 noundef) #2

declare i32 @MPI_Win_allocate(i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Win_fence(i32 noundef, ptr noundef) #2

declare i32 @MPI_Get(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Barrier(ptr noundef) #2

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!17}
!llvm.module.flags = !{!31, !32, !33, !34, !35, !36, !37, !38}
!llvm.ident = !{!39}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 48, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/conflict/004-MPI-conflict-get-load-local-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "86e418d7bff945af04052d236335d2fd")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 49)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 62, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 104, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 13)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 68, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 94)
!17 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, retainedTypes: !18, globals: !30, splitDebugInlining: false, nameTableKind: None)
!18 = !{!19, !23, !24, !27}
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
!30 = !{!0, !7, !12}
!31 = !{i32 7, !"Dwarf Version", i32 5}
!32 = !{i32 2, !"Debug Info Version", i32 3}
!33 = !{i32 1, !"wchar_size", i32 4}
!34 = !{i32 7, !"openmp", i32 50}
!35 = !{i32 7, !"PIC Level", i32 2}
!36 = !{i32 7, !"PIE Level", i32 2}
!37 = !{i32 7, !"uwtable", i32 2}
!38 = !{i32 7, !"frame-pointer", i32 2}
!39 = !{!"Debian clang version 15.0.6"}
!40 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 34, type: !41, scopeLine: 35, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !46)
!41 = !DISubroutineType(types: !42)
!42 = !{!43, !43, !44}
!43 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!44 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !45, size: 64)
!45 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!46 = !{}
!47 = !DILocalVariable(name: "argc", arg: 1, scope: !40, file: !2, line: 34, type: !43)
!48 = !DILocation(line: 34, column: 14, scope: !40)
!49 = !DILocalVariable(name: "argv", arg: 2, scope: !40, file: !2, line: 34, type: !44)
!50 = !DILocation(line: 34, column: 27, scope: !40)
!51 = !DILocalVariable(name: "rank", scope: !40, file: !2, line: 36, type: !43)
!52 = !DILocation(line: 36, column: 9, scope: !40)
!53 = !DILocalVariable(name: "size", scope: !40, file: !2, line: 36, type: !43)
!54 = !DILocation(line: 36, column: 15, scope: !40)
!55 = !DILocalVariable(name: "win", scope: !40, file: !2, line: 37, type: !56)
!56 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !20, line: 429, baseType: !57)
!57 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !58, size: 64)
!58 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !20, line: 429, flags: DIFlagFwdDecl)
!59 = !DILocation(line: 37, column: 13, scope: !40)
!60 = !DILocalVariable(name: "win_base", scope: !40, file: !2, line: 38, type: !61)
!61 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !43, size: 64)
!62 = !DILocation(line: 38, column: 10, scope: !40)
!63 = !DILocalVariable(name: "value", scope: !40, file: !2, line: 39, type: !43)
!64 = !DILocation(line: 39, column: 9, scope: !40)
!65 = !DILocalVariable(name: "value2", scope: !40, file: !2, line: 39, type: !43)
!66 = !DILocation(line: 39, column: 20, scope: !40)
!67 = !DILocalVariable(name: "result", scope: !40, file: !2, line: 40, type: !43)
!68 = !DILocation(line: 40, column: 9, scope: !40)
!69 = !DILocalVariable(name: "token", scope: !40, file: !2, line: 41, type: !43)
!70 = !DILocation(line: 41, column: 9, scope: !40)
!71 = !DILocation(line: 43, column: 5, scope: !40)
!72 = !DILocation(line: 44, column: 5, scope: !40)
!73 = !DILocation(line: 45, column: 5, scope: !40)
!74 = !DILocation(line: 47, column: 9, scope: !75)
!75 = distinct !DILexicalBlock(scope: !40, file: !2, line: 47, column: 9)
!76 = !DILocation(line: 47, column: 14, scope: !75)
!77 = !DILocation(line: 47, column: 9, scope: !40)
!78 = !DILocation(line: 48, column: 69, scope: !79)
!79 = distinct !DILexicalBlock(scope: !75, file: !2, line: 47, column: 27)
!80 = !DILocation(line: 48, column: 9, scope: !79)
!81 = !DILocation(line: 49, column: 9, scope: !79)
!82 = !DILocation(line: 50, column: 5, scope: !79)
!83 = !DILocation(line: 52, column: 5, scope: !40)
!84 = !DILocalVariable(name: "i", scope: !85, file: !2, line: 53, type: !43)
!85 = distinct !DILexicalBlock(scope: !40, file: !2, line: 53, column: 5)
!86 = !DILocation(line: 53, column: 14, scope: !85)
!87 = !DILocation(line: 53, column: 10, scope: !85)
!88 = !DILocation(line: 53, column: 21, scope: !89)
!89 = distinct !DILexicalBlock(scope: !85, file: !2, line: 53, column: 5)
!90 = !DILocation(line: 53, column: 23, scope: !89)
!91 = !DILocation(line: 53, column: 5, scope: !85)
!92 = !DILocation(line: 54, column: 9, scope: !93)
!93 = distinct !DILexicalBlock(scope: !89, file: !2, line: 53, column: 40)
!94 = !DILocation(line: 54, column: 18, scope: !93)
!95 = !DILocation(line: 54, column: 21, scope: !93)
!96 = !DILocation(line: 55, column: 5, scope: !93)
!97 = !DILocation(line: 53, column: 36, scope: !89)
!98 = !DILocation(line: 53, column: 5, scope: !89)
!99 = distinct !{!99, !91, !100, !101}
!100 = !DILocation(line: 55, column: 5, scope: !85)
!101 = !{!"llvm.loop.mustprogress"}
!102 = !DILocation(line: 57, column: 22, scope: !40)
!103 = !DILocation(line: 57, column: 5, scope: !40)
!104 = !DILocation(line: 58, column: 9, scope: !105)
!105 = distinct !DILexicalBlock(scope: !40, file: !2, line: 58, column: 9)
!106 = !DILocation(line: 58, column: 14, scope: !105)
!107 = !DILocation(line: 58, column: 9, scope: !40)
!108 = !DILocation(line: 60, column: 55, scope: !109)
!109 = distinct !DILexicalBlock(scope: !105, file: !2, line: 58, column: 20)
!110 = !DILocation(line: 60, column: 9, scope: !109)
!111 = !DILocation(line: 62, column: 33, scope: !109)
!112 = !DILocation(line: 62, column: 9, scope: !109)
!113 = !DILocation(line: 63, column: 5, scope: !109)
!114 = !DILocation(line: 64, column: 22, scope: !40)
!115 = !DILocation(line: 64, column: 5, scope: !40)
!116 = !DILocation(line: 66, column: 5, scope: !40)
!117 = !DILocation(line: 69, column: 9, scope: !40)
!118 = !DILocation(line: 70, column: 9, scope: !40)
!119 = !DILocation(line: 71, column: 9, scope: !40)
!120 = !DILocation(line: 72, column: 9, scope: !40)
!121 = !DILocation(line: 67, column: 5, scope: !40)
!122 = !DILocation(line: 74, column: 5, scope: !40)
!123 = !DILocation(line: 75, column: 5, scope: !40)
!124 = !DILocation(line: 77, column: 5, scope: !40)
