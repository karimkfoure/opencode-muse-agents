
undefined8 * fold_predicate(undefined8 *param_1,long *param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  ushort uVar3;
  long lVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  ulong *puVar9;
  undefined8 *puVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  undefined8 uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  long lVar18;
  bool bVar19;
  
  if (param_2[8] == 0) {
    lVar12 = *param_2;
    lVar4 = param_2[1];
    lVar18 = param_2[2];
    uVar15 = param_2[3];
    *param_2 = 0;
    if (lVar12 == 1) {
      if (lVar4 == 0) {
        if (uVar15 != 0) {
          uVar13 = uVar15;
          if ((uVar15 & 7) != 0) {
            uVar13 = 0;
            do {
              lVar18 = *(long *)(lVar18 + 0x278);
              uVar13 = uVar13 + 1;
            } while ((uVar15 & 7) != uVar13);
            uVar13 = uVar15 - uVar13;
          }
          if (7 < uVar15) {
            do {
              lVar18 = *(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long 
                                                  *)(lVar18 + 0x278) + 0x278) + 0x278) + 0x278) +
                                                  0x278) + 0x278) + 0x278) + 0x278);
              uVar13 = uVar13 - 8;
            } while (uVar13 != 0);
          }
        }
        lVar8 = *(long *)(lVar18 + 0x160);
        lVar12 = 0;
      }
      else {
        lVar8 = *(long *)(lVar4 + 0x160);
        lVar12 = lVar18;
        lVar18 = lVar4;
      }
      while (lVar4 = lVar8, lVar4 != 0) {
        bVar19 = lVar12 == 0;
        lVar12 = lVar12 + 1;
        uVar14 = 0x2d8;
        if (bVar19) {
          uVar14 = 0x278;
        }
        (*(code *)&DAT_04732840)(lVar18,uVar14,8);
        lVar18 = lVar4;
        lVar8 = *(long *)(lVar4 + 0x160);
      }
      uVar14 = 0x2d8;
      if (lVar12 == 0) {
        uVar14 = 0x278;
      }
      (*(code *)&DAT_04732840)(lVar18,uVar14,8);
    }
    *param_1 = 0xffffffffffffffff;
    return param_1;
  }
  param_2[8] = param_2[8] + -1;
  if ((int)*param_2 != 1) {
code_r0x07863dd9:
    (*(code *)&DAT_120a4420)(&UNK_121502d0);
    pcVar5 = (code *)swi(3);
    puVar10 = (undefined8 *)(*pcVar5)();
    return puVar10;
  }
  uVar15 = param_2[1];
  if (uVar15 == 0) {
    uVar15 = param_2[2];
    uVar13 = param_2[3];
    if (uVar13 != 0) {
      uVar16 = uVar13;
      if ((uVar13 & 7) != 0) {
        uVar16 = 0;
        do {
          uVar15 = *(ulong *)(uVar15 + 0x278);
          uVar16 = uVar16 + 1;
        } while ((uVar13 & 7) != uVar16);
        uVar16 = uVar13 - uVar16;
      }
      if (7 < uVar13) {
        do {
          uVar15 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(
                                                  uVar15 + 0x278) + 0x278) + 0x278) + 0x278) + 0x278
                                                  ) + 0x278) + 0x278) + 0x278);
          uVar16 = uVar16 - 8;
        } while (uVar16 != 0);
      }
    }
    *param_2 = 1;
    param_2[1] = uVar15;
    param_2[2] = 0;
    param_2[3] = 0;
  }
  uVar13 = param_2[2];
  uVar16 = param_2[3];
  uVar11 = (ulong)*(ushort *)(uVar15 + 0x272);
  if (uVar11 <= uVar16) {
    do {
      uVar17 = *(ulong *)(uVar15 + 0x160);
      if (uVar17 == 0) {
        uVar14 = 0x2d8;
        if (uVar13 == 0) {
          uVar14 = 0x278;
        }
        (*(code *)&DAT_04732840)(uVar15,uVar14,8);
        (*(code *)&DAT_120a4420)(&UNK_121346f0);
        goto code_r0x07863dd9;
      }
      uVar1 = uVar13 + 1;
      uVar3 = *(ushort *)(uVar15 + 0x270);
      uVar16 = (ulong)uVar3;
      uVar14 = 0x2d8;
      if (uVar13 == 0) {
        uVar14 = 0x278;
      }
      (*(code *)&DAT_04732840)(uVar15,uVar14,8);
      uVar13 = uVar1;
      uVar15 = uVar17;
    } while (*(ushort *)(uVar17 + 0x272) <= uVar3);
  }
  if (uVar13 == 0) {
    lVar12 = uVar16 + 1;
    uVar11 = uVar15;
  }
  else {
    puVar9 = (ulong *)(uVar15 + 0x280 + uVar16 * 8);
    uVar17 = uVar13;
    if ((uVar13 & 7) != 0) {
      uVar17 = 0;
      do {
        uVar11 = *puVar9;
        puVar9 = (ulong *)(uVar11 + 0x278);
        uVar17 = uVar17 + 1;
      } while ((uVar13 & 7) != uVar17);
      uVar17 = uVar13 - uVar17;
    }
    lVar12 = 0;
    if (7 < uVar13) {
      do {
        lVar12 = 0;
        uVar11 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*puVar9 +
                                                                                       0x278) +
                                                                             0x278) + 0x278) + 0x278
                                                         ) + 0x278) + 0x278) + 0x278);
        puVar9 = (ulong *)(uVar11 + 0x278);
        uVar17 = uVar17 - 8;
      } while (uVar17 != 0);
    }
  }
  param_2[1] = uVar11;
  param_2[2] = 0;
  param_2[3] = lVar12;
  param_1[2] = *(undefined8 *)(uVar15 + 0x178 + uVar16 * 0x18);
  puVar10 = (undefined8 *)(uVar15 + 0x168 + uVar16 * 0x18);
  uVar14 = puVar10[1];
  *param_1 = *puVar10;
  param_1[1] = uVar14;
  puVar10 = (undefined8 *)(uVar15 + uVar16 * 0x20);
  uVar14 = puVar10[1];
  puVar2 = (undefined8 *)(uVar15 + 0x10 + uVar16 * 0x20);
  uVar6 = *puVar2;
  uVar7 = puVar2[1];
  param_1[3] = *puVar10;
  param_1[4] = uVar14;
  param_1[5] = uVar6;
  param_1[6] = uVar7;
  return param_1;
}

