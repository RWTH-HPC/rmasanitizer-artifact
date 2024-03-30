; ModuleID = 'results-20240330-164421/PARCOACH-dynamic/conflict/028-MPI-conflict-acc-store-remote-yes.c'
source_filename = "results-20240330-164421/PARCOACH-dynamic/conflict/028-MPI-conflict-acc-store-remote-yes.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_info_t = type opaque
%struct.ompi_predefined_datatype_t = type opaque
%struct.ompi_predefined_op_t = type opaque

@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str = private unnamed_addr constant [49 x i8] c"Wrong number of MPI processes: %d. Expected: %d\0A\00", align 1, !dbg !0
@ompi_mpi_info_null = external global %struct.ompi_predefined_info_t, align 1
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@ompi_mpi_op_sum = external global %struct.ompi_predefined_op_t, align 1
@.str.1 = private unnamed_addr constant [94 x i8] c"Process %d: Execution finished, variable contents: value = %d, value2 = %d, win_base[0] = %d\0A\00", align 1, !dbg !7

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 !dbg !38 {
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
  call void @llvm.dbg.declare(metadata ptr %4, metadata !45, metadata !DIExpression()), !dbg !46
  store ptr %1, ptr %5, align 8
  call void @llvm.dbg.declare(metadata ptr %5, metadata !47, metadata !DIExpression()), !dbg !48
  call void @llvm.dbg.declare(metadata ptr %6, metadata !49, metadata !DIExpression()), !dbg !50
  call void @llvm.dbg.declare(metadata ptr %7, metadata !51, metadata !DIExpression()), !dbg !52
  call void @llvm.dbg.declare(metadata ptr %8, metadata !53, metadata !DIExpression()), !dbg !57
  call void @llvm.dbg.declare(metadata ptr %9, metadata !58, metadata !DIExpression()), !dbg !60
  call void @llvm.dbg.declare(metadata ptr %10, metadata !61, metadata !DIExpression()), !dbg !62
  store i32 1, ptr %10, align 4, !dbg !62
  call void @llvm.dbg.declare(metadata ptr %11, metadata !63, metadata !DIExpression()), !dbg !64
  store i32 2, ptr %11, align 4, !dbg !64
  call void @llvm.dbg.declare(metadata ptr %12, metadata !65, metadata !DIExpression()), !dbg !66
  call void @llvm.dbg.declare(metadata ptr %13, metadata !67, metadata !DIExpression()), !dbg !68
  store i32 42, ptr %13, align 4, !dbg !68
  %15 = call i32 @MPI_Init(ptr noundef %4, ptr noundef %5), !dbg !69
  %16 = call i32 @MPI_Comm_rank(ptr noundef @ompi_mpi_comm_world, ptr noundef %6), !dbg !70
  %17 = call i32 @MPI_Comm_size(ptr noundef @ompi_mpi_comm_world, ptr noundef %7), !dbg !71
  %18 = load i32, ptr %7, align 4, !dbg !72
  %19 = icmp ne i32 %18, 2, !dbg !74
  br i1 %19, label %20, label %24, !dbg !75

20:                                               ; preds = %2
  %21 = load i32, ptr %7, align 4, !dbg !76
  %22 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %21, i32 noundef 2), !dbg !78
  %23 = call i32 @MPI_Abort(ptr noundef @ompi_mpi_comm_world, i32 noundef 1), !dbg !79
  br label %24, !dbg !80

24:                                               ; preds = %20, %2
  %25 = call i32 @MPI_Win_allocate(i64 noundef 40, i32 noundef 4, ptr noundef @ompi_mpi_info_null, ptr noundef @ompi_mpi_comm_world, ptr noundef %9, ptr noundef %8), !dbg !81
  call void @llvm.dbg.declare(metadata ptr %14, metadata !82, metadata !DIExpression()), !dbg !84
  store i32 0, ptr %14, align 4, !dbg !84
  br label %26, !dbg !85

26:                                               ; preds = %34, %24
  %27 = load i32, ptr %14, align 4, !dbg !86
  %28 = icmp slt i32 %27, 10, !dbg !88
  br i1 %28, label %29, label %37, !dbg !89

29:                                               ; preds = %26
  %30 = load ptr, ptr %9, align 8, !dbg !90
  %31 = load i32, ptr %14, align 4, !dbg !92
  %32 = sext i32 %31 to i64, !dbg !90
  %33 = getelementptr inbounds i32, ptr %30, i64 %32, !dbg !90
  store i32 0, ptr %33, align 4, !dbg !93
  br label %34, !dbg !94

34:                                               ; preds = %29
  %35 = load i32, ptr %14, align 4, !dbg !95
  %36 = add nsw i32 %35, 1, !dbg !95
  store i32 %36, ptr %14, align 4, !dbg !95
  br label %26, !dbg !96, !llvm.loop !97

37:                                               ; preds = %26
  %38 = load ptr, ptr %8, align 8, !dbg !100
  %39 = call i32 @MPI_Win_fence(i32 noundef 0, ptr noundef %38), !dbg !101
  %40 = load i32, ptr %6, align 4, !dbg !102
  %41 = icmp eq i32 %40, 0, !dbg !104
  br i1 %41, label %42, label %45, !dbg !105

42:                                               ; preds = %37
  %43 = load ptr, ptr %8, align 8, !dbg !106
  %44 = call i32 @MPI_Accumulate(ptr noundef %10, i32 noundef 1, ptr noundef @ompi_mpi_int, i32 noundef 1, i64 noundef 0, i32 noundef 1, ptr noundef @ompi_mpi_int, ptr noundef @ompi_mpi_op_sum, ptr noundef %43), !dbg !108
  br label %45, !dbg !109

45:                                               ; preds = %42, %37
  %46 = load i32, ptr %6, align 4, !dbg !110
  %47 = icmp eq i32 %46, 1, !dbg !112
  br i1 %47, label %48, label %51, !dbg !113

48:                                               ; preds = %45
  %49 = load ptr, ptr %9, align 8, !dbg !114
  %50 = getelementptr inbounds i32, ptr %49, i64 0, !dbg !114
  store i32 42, ptr %50, align 4, !dbg !116
  br label %51, !dbg !117

51:                                               ; preds = %48, %45
  %52 = load ptr, ptr %8, align 8, !dbg !118
  %53 = call i32 @MPI_Win_fence(i32 noundef 0, ptr noundef %52), !dbg !119
  %54 = call i32 @MPI_Barrier(ptr noundef @ompi_mpi_comm_world), !dbg !120
  %55 = load i32, ptr %6, align 4, !dbg !121
  %56 = load i32, ptr %10, align 4, !dbg !122
  %57 = load i32, ptr %11, align 4, !dbg !123
  %58 = load ptr, ptr %9, align 8, !dbg !124
  %59 = getelementptr inbounds i32, ptr %58, i64 0, !dbg !124
  %60 = load i32, ptr %59, align 4, !dbg !124
  %61 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %55, i32 noundef %56, i32 noundef %57, i32 noundef %60), !dbg !125
  %62 = call i32 @MPI_Win_free(ptr noundef %8), !dbg !126
  %63 = call i32 @MPI_Finalize(), !dbg !127
  ret i32 0, !dbg !128
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

declare i32 @MPI_Accumulate(ptr noundef, i32 noundef, ptr noundef, i32 noundef, i64 noundef, i32 noundef, ptr noundef, ptr noundef, ptr noundef) #2

declare i32 @MPI_Barrier(ptr noundef) #2

declare i32 @MPI_Win_free(ptr noundef) #2

declare i32 @MPI_Finalize() #2

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!12}
!llvm.module.flags = !{!29, !30, !31, !32, !33, !34, !35, !36}
!llvm.ident = !{!37}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 48, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "results-20240330-164421/PARCOACH-dynamic/conflict/028-MPI-conflict-acc-store-remote-yes.c", directory: "/rmaracebench", checksumkind: CSK_MD5, checksum: "03a753ef35bc6be94f05f11850da8183")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 392, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 49)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 74, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 752, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 94)
!12 = distinct !DICompileUnit(language: DW_LANG_C99, file: !2, producer: "Debian clang version 15.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, retainedTypes: !13, globals: !28, splitDebugInlining: false, nameTableKind: None)
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
!25 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Op", file: !15, line: 425, baseType: !26)
!26 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !27, size: 64)
!27 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_op_t", file: !15, line: 425, flags: DIFlagFwdDecl)
!28 = !{!0, !7}
!29 = !{i32 7, !"Dwarf Version", i32 5}
!30 = !{i32 2, !"Debug Info Version", i32 3}
!31 = !{i32 1, !"wchar_size", i32 4}
!32 = !{i32 7, !"openmp", i32 50}
!33 = !{i32 7, !"PIC Level", i32 2}
!34 = !{i32 7, !"PIE Level", i32 2}
!35 = !{i32 7, !"uwtable", i32 2}
!36 = !{i32 7, !"frame-pointer", i32 2}
!37 = !{!"Debian clang version 15.0.6"}
!38 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 34, type: !39, scopeLine: 35, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !12, retainedNodes: !44)
!39 = !DISubroutineType(types: !40)
!40 = !{!41, !41, !42}
!41 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!42 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !43, size: 64)
!43 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!44 = !{}
!45 = !DILocalVariable(name: "argc", arg: 1, scope: !38, file: !2, line: 34, type: !41)
!46 = !DILocation(line: 34, column: 14, scope: !38)
!47 = !DILocalVariable(name: "argv", arg: 2, scope: !38, file: !2, line: 34, type: !42)
!48 = !DILocation(line: 34, column: 27, scope: !38)
!49 = !DILocalVariable(name: "rank", scope: !38, file: !2, line: 36, type: !41)
!50 = !DILocation(line: 36, column: 9, scope: !38)
!51 = !DILocalVariable(name: "size", scope: !38, file: !2, line: 36, type: !41)
!52 = !DILocation(line: 36, column: 15, scope: !38)
!53 = !DILocalVariable(name: "win", scope: !38, file: !2, line: 37, type: !54)
!54 = !DIDerivedType(tag: DW_TAG_typedef, name: "MPI_Win", file: !15, line: 429, baseType: !55)
!55 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !56, size: 64)
!56 = !DICompositeType(tag: DW_TAG_structure_type, name: "ompi_win_t", file: !15, line: 429, flags: DIFlagFwdDecl)
!57 = !DILocation(line: 37, column: 13, scope: !38)
!58 = !DILocalVariable(name: "win_base", scope: !38, file: !2, line: 38, type: !59)
!59 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !41, size: 64)
!60 = !DILocation(line: 38, column: 10, scope: !38)
!61 = !DILocalVariable(name: "value", scope: !38, file: !2, line: 39, type: !41)
!62 = !DILocation(line: 39, column: 9, scope: !38)
!63 = !DILocalVariable(name: "value2", scope: !38, file: !2, line: 39, type: !41)
!64 = !DILocation(line: 39, column: 20, scope: !38)
!65 = !DILocalVariable(name: "result", scope: !38, file: !2, line: 40, type: !41)
!66 = !DILocation(line: 40, column: 9, scope: !38)
!67 = !DILocalVariable(name: "token", scope: !38, file: !2, line: 41, type: !41)
!68 = !DILocation(line: 41, column: 9, scope: !38)
!69 = !DILocation(line: 43, column: 5, scope: !38)
!70 = !DILocation(line: 44, column: 5, scope: !38)
!71 = !DILocation(line: 45, column: 5, scope: !38)
!72 = !DILocation(line: 47, column: 9, scope: !73)
!73 = distinct !DILexicalBlock(scope: !38, file: !2, line: 47, column: 9)
!74 = !DILocation(line: 47, column: 14, scope: !73)
!75 = !DILocation(line: 47, column: 9, scope: !38)
!76 = !DILocation(line: 48, column: 69, scope: !77)
!77 = distinct !DILexicalBlock(scope: !73, file: !2, line: 47, column: 27)
!78 = !DILocation(line: 48, column: 9, scope: !77)
!79 = !DILocation(line: 49, column: 9, scope: !77)
!80 = !DILocation(line: 50, column: 5, scope: !77)
!81 = !DILocation(line: 52, column: 5, scope: !38)
!82 = !DILocalVariable(name: "i", scope: !83, file: !2, line: 53, type: !41)
!83 = distinct !DILexicalBlock(scope: !38, file: !2, line: 53, column: 5)
!84 = !DILocation(line: 53, column: 14, scope: !83)
!85 = !DILocation(line: 53, column: 10, scope: !83)
!86 = !DILocation(line: 53, column: 21, scope: !87)
!87 = distinct !DILexicalBlock(scope: !83, file: !2, line: 53, column: 5)
!88 = !DILocation(line: 53, column: 23, scope: !87)
!89 = !DILocation(line: 53, column: 5, scope: !83)
!90 = !DILocation(line: 54, column: 9, scope: !91)
!91 = distinct !DILexicalBlock(scope: !87, file: !2, line: 53, column: 40)
!92 = !DILocation(line: 54, column: 18, scope: !91)
!93 = !DILocation(line: 54, column: 21, scope: !91)
!94 = !DILocation(line: 55, column: 5, scope: !91)
!95 = !DILocation(line: 53, column: 36, scope: !87)
!96 = !DILocation(line: 53, column: 5, scope: !87)
!97 = distinct !{!97, !89, !98, !99}
!98 = !DILocation(line: 55, column: 5, scope: !83)
!99 = !{!"llvm.loop.mustprogress"}
!100 = !DILocation(line: 57, column: 22, scope: !38)
!101 = !DILocation(line: 57, column: 5, scope: !38)
!102 = !DILocation(line: 59, column: 9, scope: !103)
!103 = distinct !DILexicalBlock(scope: !38, file: !2, line: 59, column: 9)
!104 = !DILocation(line: 59, column: 14, scope: !103)
!105 = !DILocation(line: 59, column: 9, scope: !38)
!106 = !DILocation(line: 62, column: 71, scope: !107)
!107 = distinct !DILexicalBlock(scope: !103, file: !2, line: 59, column: 20)
!108 = !DILocation(line: 62, column: 9, scope: !107)
!109 = !DILocation(line: 63, column: 5, scope: !107)
!110 = !DILocation(line: 65, column: 9, scope: !111)
!111 = distinct !DILexicalBlock(scope: !38, file: !2, line: 65, column: 9)
!112 = !DILocation(line: 65, column: 14, scope: !111)
!113 = !DILocation(line: 65, column: 9, scope: !38)
!114 = !DILocation(line: 67, column: 9, scope: !115)
!115 = distinct !DILexicalBlock(scope: !111, file: !2, line: 65, column: 20)
!116 = !DILocation(line: 67, column: 21, scope: !115)
!117 = !DILocation(line: 68, column: 5, scope: !115)
!118 = !DILocation(line: 70, column: 22, scope: !38)
!119 = !DILocation(line: 70, column: 5, scope: !38)
!120 = !DILocation(line: 72, column: 5, scope: !38)
!121 = !DILocation(line: 75, column: 9, scope: !38)
!122 = !DILocation(line: 76, column: 9, scope: !38)
!123 = !DILocation(line: 77, column: 9, scope: !38)
!124 = !DILocation(line: 78, column: 9, scope: !38)
!125 = !DILocation(line: 73, column: 5, scope: !38)
!126 = !DILocation(line: 80, column: 5, scope: !38)
!127 = !DILocation(line: 81, column: 5, scope: !38)
!128 = !DILocation(line: 83, column: 5, scope: !38)
