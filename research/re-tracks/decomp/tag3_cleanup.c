
void tag3_cleanup(ulong *param_1)

{
  byte bVar1;
  ushort uVar2;
  code *pcVar3;
  ulong uVar4;
  ulong uVar5;
  ulong *puVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  byte *pbVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  bool bVar14;
  
  uVar4 = *param_1;
  if (uVar4 == 0) {
    return;
  }
  uVar9 = param_1[1];
  uVar7 = param_1[2];
  if (uVar7 == 0) {
    uVar8 = uVar4;
    if (uVar9 != 0) {
      uVar7 = uVar9;
      if ((uVar9 & 7) != 0) {
        uVar7 = 0;
        do {
          uVar4 = *(ulong *)(uVar4 + 0x278);
          uVar7 = uVar7 + 1;
        } while ((uVar9 & 7) != uVar7);
        uVar8 = uVar4;
        uVar7 = uVar9 - uVar7;
      }
      if (7 < uVar9) {
        do {
          uVar8 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(
                                                  uVar8 + 0x278) + 0x278) + 0x278) + 0x278) + 0x278)
                                                + 0x278) + 0x278) + 0x278);
          uVar7 = uVar7 - 8;
        } while (uVar7 != 0);
      }
    }
  }
  else {
    uVar8 = 0;
    do {
      if (uVar8 == 0) {
        if (uVar9 != 0) {
          uVar8 = uVar9;
          if ((uVar9 & 7) != 0) {
            uVar8 = 0;
            do {
              uVar4 = *(ulong *)(uVar4 + 0x278);
              uVar8 = uVar8 + 1;
            } while ((uVar9 & 7) != uVar8);
            uVar8 = uVar9 - uVar8;
          }
          if (7 < uVar9) {
            do {
              uVar4 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long 
                                                  *)(uVar4 + 0x278) + 0x278) + 0x278) + 0x278) +
                                                  0x278) + 0x278) + 0x278) + 0x278);
              uVar8 = uVar8 - 8;
            } while (uVar8 != 0);
          }
        }
        uVar5 = 0;
        uVar13 = 0;
        uVar8 = uVar4;
        if (*(short *)(uVar4 + 0x272) == 0) goto code_r0x07657f70;
      }
      else {
        uVar5 = uVar4;
        uVar4 = uVar8;
        uVar13 = uVar9;
        if (*(ushort *)(uVar8 + 0x272) <= uVar9) {
code_r0x07657f70:
          do {
            uVar4 = *(ulong *)(uVar8 + 0x160);
            if (uVar4 == 0) {
              uVar12 = 0x2d8;
              if (uVar5 == 0) {
                uVar12 = 0x278;
              }
              (*(code *)&DAT_04732840)(uVar8,uVar12,8);
              (*(code *)&DAT_120a4420)(&UNK_121346f0);
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            uVar9 = uVar5 + 1;
            uVar2 = *(ushort *)(uVar8 + 0x270);
            uVar12 = 0x2d8;
            if (uVar5 == 0) {
              uVar12 = 0x278;
            }
            (*(code *)&DAT_04732840)(uVar8,uVar12,8);
            uVar5 = uVar9;
            uVar8 = uVar4;
            uVar13 = (ulong)uVar2;
          } while (*(ushort *)(uVar4 + 0x272) <= uVar2);
        }
      }
      uVar8 = uVar4;
      if (uVar5 == 0) {
        uVar9 = uVar13 + 1;
        lVar11 = *(long *)(uVar4 + 0x168 + uVar13 * 0x18);
      }
      else {
        puVar6 = (ulong *)(uVar4 + 0x280 + uVar13 * 8);
        uVar9 = uVar5;
        if ((uVar5 & 7) != 0) {
          uVar9 = 0;
          do {
            uVar8 = *puVar6;
            puVar6 = (ulong *)(uVar8 + 0x278);
            uVar9 = uVar9 + 1;
          } while ((uVar5 & 7) != uVar9);
          uVar9 = uVar5 - uVar9;
        }
        if (7 < uVar5) {
          do {
            uVar8 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*puVar6 +
                                                                                          0x278) +
                                                                                0x278) + 0x278) +
                                                            0x278) + 0x278) + 0x278) + 0x278);
            puVar6 = (ulong *)(uVar8 + 0x278);
            uVar9 = uVar9 - 8;
          } while (uVar9 != 0);
        }
        uVar9 = 0;
        lVar11 = *(long *)(uVar4 + 0x168 + uVar13 * 0x18);
      }
      if (lVar11 != 0) {
        (*(code *)&DAT_04732840)(*(undefined8 *)(uVar4 + uVar13 * 0x18 + 0x170),lVar11,1);
      }
      pbVar10 = (byte *)(uVar4 + uVar13 * 0x20);
      bVar1 = *pbVar10;
      if (2 < bVar1) {
        if (bVar1 == 3) {
          if (*(long *)(pbVar10 + 8) != 0) {
            (*(code *)&DAT_04732840)(*(undefined8 *)(pbVar10 + 0x10),*(long *)(pbVar10 + 8),1);
          }
        }
        else if (bVar1 == 4) {
          func_0x07c89080(pbVar10 + 8);
          if (*(long *)(pbVar10 + 8) != 0) {
            (*(code *)&DAT_04732840)(*(undefined8 *)(pbVar10 + 0x10),*(long *)(pbVar10 + 8) << 5,8);
          }
        }
        else {
          tag3_cleanup(pbVar10 + 8);
        }
      }
      uVar4 = 0;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  if (*(ulong *)(uVar8 + 0x160) == 0) {
    uVar12 = 0x278;
  }
  else {
    lVar11 = 0;
    uVar4 = *(ulong *)(uVar8 + 0x160);
    uVar9 = uVar8;
    do {
      uVar8 = uVar4;
      bVar14 = lVar11 == 0;
      lVar11 = lVar11 + -1;
      uVar12 = 0x2d8;
      if (bVar14) {
        uVar12 = 0x278;
      }
      (*(code *)&DAT_04732840)(uVar9,uVar12,8);
      uVar4 = *(ulong *)(uVar8 + 0x160);
      uVar9 = uVar8;
    } while (*(ulong *)(uVar8 + 0x160) != 0);
    uVar12 = 0x2d8;
    if (lVar11 == 0) {
      uVar12 = 0x278;
    }
  }
  (*(code *)&DAT_04732840)(uVar8,uVar12,8);
  return;
}

