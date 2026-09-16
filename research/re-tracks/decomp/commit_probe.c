
void commit_probe(long *param_1)

{
  byte bVar1;
  ushort uVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  ulong *puVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  byte *pbVar11;
  undefined8 uVar12;
  ulong uVar13;
  bool bVar14;
  
  lVar7 = *param_1;
  if (lVar7 == -2) {
    bVar1 = *(byte *)(param_1 + 1);
    if (bVar1 < 3) {
      if (2 < bVar1) {
code_r0x06d080d3:
        uVar5 = param_1[2];
        if (uVar5 == 0) {
          return;
        }
        uVar10 = param_1[3];
        lVar7 = param_1[4];
        if (lVar7 == 0) {
          uVar9 = uVar5;
          if (uVar10 != 0) {
            uVar8 = uVar10;
            if ((uVar10 & 7) != 0) {
              uVar8 = 0;
              do {
                uVar5 = *(ulong *)(uVar5 + 0x278);
                uVar8 = uVar8 + 1;
              } while ((uVar10 & 7) != uVar8);
              uVar9 = uVar5;
              uVar8 = uVar10 - uVar8;
            }
            if (7 < uVar10) {
              do {
                uVar9 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(
                                                  long *)(uVar9 + 0x278) + 0x278) + 0x278) + 0x278)
                                                  + 0x278) + 0x278) + 0x278) + 0x278);
                uVar8 = uVar8 - 8;
              } while (uVar8 != 0);
            }
          }
        }
        else {
          uVar9 = 0;
          do {
            if (uVar9 == 0) {
              if (uVar10 != 0) {
                uVar9 = uVar10;
                if ((uVar10 & 7) != 0) {
                  uVar9 = 0;
                  do {
                    uVar5 = *(ulong *)(uVar5 + 0x278);
                    uVar9 = uVar9 + 1;
                  } while ((uVar10 & 7) != uVar9);
                  uVar9 = uVar10 - uVar9;
                }
                if (7 < uVar10) {
                  do {
                    uVar5 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*
                                                  (long *)(uVar5 + 0x278) + 0x278) + 0x278) + 0x278)
                                                  + 0x278) + 0x278) + 0x278) + 0x278);
                    uVar9 = uVar9 - 8;
                  } while (uVar9 != 0);
                }
              }
              uVar8 = 0;
              uVar13 = 0;
              uVar9 = uVar5;
              if (*(short *)(uVar5 + 0x272) == 0) goto code_r0x078137a0;
            }
            else {
              uVar8 = uVar5;
              uVar5 = uVar9;
              uVar13 = uVar10;
              if (*(ushort *)(uVar9 + 0x272) <= uVar10) {
code_r0x078137a0:
                do {
                  uVar5 = *(ulong *)(uVar9 + 0x160);
                  if (uVar5 == 0) {
                    uVar12 = 0x2d8;
                    if (uVar8 == 0) {
                      uVar12 = 0x278;
                    }
                    (*(code *)&DAT_04732840)(uVar9,uVar12,8);
                    (*(code *)&DAT_120a4420)(&UNK_121346f0);
                    pcVar4 = (code *)swi(3);
                    (*pcVar4)();
                    return;
                  }
                  uVar10 = uVar8 + 1;
                  uVar2 = *(ushort *)(uVar9 + 0x270);
                  uVar12 = 0x2d8;
                  if (uVar8 == 0) {
                    uVar12 = 0x278;
                  }
                  (*(code *)&DAT_04732840)(uVar9,uVar12,8);
                  uVar8 = uVar10;
                  uVar9 = uVar5;
                  uVar13 = (ulong)uVar2;
                } while (*(ushort *)(uVar5 + 0x272) <= uVar2);
              }
            }
            uVar9 = uVar5;
            if (uVar8 == 0) {
              uVar10 = uVar13 + 1;
              lVar3 = *(long *)(uVar5 + 0x168 + uVar13 * 0x18);
            }
            else {
              puVar6 = (ulong *)(uVar5 + 0x280 + uVar13 * 8);
              uVar10 = uVar8;
              if ((uVar8 & 7) != 0) {
                uVar10 = 0;
                do {
                  uVar9 = *puVar6;
                  puVar6 = (ulong *)(uVar9 + 0x278);
                  uVar10 = uVar10 + 1;
                } while ((uVar8 & 7) != uVar10);
                uVar10 = uVar8 - uVar10;
              }
              if (7 < uVar8) {
                do {
                  uVar9 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*
                                                  puVar6 + 0x278) + 0x278) + 0x278) + 0x278) + 0x278
                                                  ) + 0x278) + 0x278);
                  puVar6 = (ulong *)(uVar9 + 0x278);
                  uVar10 = uVar10 - 8;
                } while (uVar10 != 0);
              }
              uVar10 = 0;
              lVar3 = *(long *)(uVar5 + 0x168 + uVar13 * 0x18);
            }
            if (lVar3 != 0) {
              (*(code *)&DAT_04732840)(*(undefined8 *)(uVar5 + uVar13 * 0x18 + 0x170),lVar3,1);
            }
            pbVar11 = (byte *)(uVar5 + uVar13 * 0x20);
            bVar1 = *pbVar11;
            if (2 < bVar1) {
              if (bVar1 == 3) {
                if (*(long *)(pbVar11 + 8) != 0) {
                  (*(code *)&DAT_04732840)(*(undefined8 *)(pbVar11 + 0x10),*(long *)(pbVar11 + 8),1)
                  ;
                }
              }
              else if (bVar1 == 4) {
                func_0x07c89080(pbVar11 + 8);
                if (*(long *)(pbVar11 + 8) != 0) {
                  (*(code *)&DAT_04732840)
                            (*(undefined8 *)(pbVar11 + 0x10),*(long *)(pbVar11 + 8) << 5,8);
                }
              }
              else {
                func_0x07657e30(pbVar11 + 8);
              }
            }
            uVar5 = 0;
            lVar7 = lVar7 + -1;
          } while (lVar7 != 0);
        }
        if (*(ulong *)(uVar9 + 0x160) == 0) {
          uVar12 = 0x278;
        }
        else {
          lVar7 = 0;
          uVar5 = *(ulong *)(uVar9 + 0x160);
          uVar10 = uVar9;
          do {
            uVar9 = uVar5;
            bVar14 = lVar7 == 0;
            lVar7 = lVar7 + -1;
            uVar12 = 0x2d8;
            if (bVar14) {
              uVar12 = 0x278;
            }
            (*(code *)&DAT_04732840)(uVar10,uVar12,8);
            uVar5 = *(ulong *)(uVar9 + 0x160);
            uVar10 = uVar9;
          } while (*(ulong *)(uVar9 + 0x160) != 0);
          uVar12 = 0x2d8;
          if (lVar7 == 0) {
            uVar12 = 0x278;
          }
        }
        (*(code *)&DAT_04732840)(uVar9,uVar12,8);
        return;
      }
    }
    else if (bVar1 == 3) {
      if (param_1[2] != 0) {
        (*(code *)&DAT_04732840)(param_1[3],param_1[2],1);
        return;
      }
    }
    else if (bVar1 == 4) {
      func_0x07c89080(param_1 + 2);
      if (param_1[2] != 0) {
        (*(code *)&DAT_04732840)(param_1[3],param_1[2] << 5,8);
        return;
      }
    }
    else if (bVar1 != 0xff) goto code_r0x06d080d3;
  }
  else {
    record_release(param_1 + 3);
    if ((lVar7 != -1) && (lVar7 != 0)) {
      (*(code *)&DAT_04732840)(param_1[1],lVar7,1);
      return;
    }
  }
  return;
}

