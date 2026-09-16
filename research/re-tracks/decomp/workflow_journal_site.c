
bool workflow_journal_site(long *param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined7 uVar5;
  long lVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  undefined1 auVar10 [16];
  undefined8 *puStack_98;
  undefined *puStack_90;
  undefined **ppuStack_88;
  undefined *puStack_80;
  undefined *puStack_78;
  long lStack_70;
  undefined8 uStack_68;
  long lStack_60;
  long lStack_58;
  undefined8 uStack_50;
  long lStack_48;
  undefined8 uStack_40;
  uint uStack_34;
  
  bVar7 = (char)param_1[0x8e] != '\0';
  lVar2 = *param_1;
  uVar5 = (undefined7)((ulong)param_4 >> 8);
  if (bVar7 || lVar2 == -1) {
    return bVar7 && lVar2 == -1;
  }
  if (2 < *(uint *)(param_1 + 0x3f)) {
    return false;
  }
  auVar10 = (*(code *)&DAT_0f08fd90)(param_2);
  lVar6 = auVar10._8_8_;
  lVar4 = auVar10._0_8_;
  if (lVar4 == 0) {
    if (param_1[0x71] == -1) {
      uStack_34 = 1;
      goto code_r0x0c17c1a1;
    }
code_r0x0c17c149:
    if ((param_1[0x73] == lVar6 && *(int *)(param_2 + 0x1a0) == 1) && lVar4 != 0) {
      iVar3 = (*(code *)&DAT_120cae9d)(param_1[0x72],lVar4,lVar6);
      uStack_34 = (uint)CONCAT71(uVar5,iVar3 == 0);
    }
    else {
      uStack_34 = 0;
      lVar6 = param_1[0x73];
    }
code_r0x0c17c18f:
    puStack_78 = (undefined *)param_1[0x72];
  }
  else {
    uStack_34 = (*(code *)&DAT_0f0e0760)(lVar4,lVar6);
    if (param_1[0x71] != -1) {
      if ((((byte)uStack_34 & lVar6 == param_1[0x73]) == 0) ||
         (iVar3 = (*(code *)&DAT_120cae9d)(param_1[0x72],lVar4,lVar6), iVar3 != 0))
      goto code_r0x0c17c149;
      uStack_34 = (uint)CONCAT71(uVar5,1);
      goto code_r0x0c17c18f;
    }
    uStack_34 = uStack_34 ^ 1;
code_r0x0c17c1a1:
    lVar6 = 0xc;
    puStack_78 = &UNK_01198612;
  }
  uStack_68 = *(undefined8 *)(param_2 + 0x68);
  lVar4 = *(long *)(param_2 + 0x70);
  puStack_98 = &uStack_68;
  puStack_90 = &UNK_0dce8e70;
  ppuStack_88 = &puStack_78;
  puStack_80 = &UNK_0dce8e70;
  lStack_70 = lVar6;
  lStack_60 = lVar4;
  uStack_40 = uStack_68;
  (*(code *)&DAT_12089060)(&lStack_58,&UNK_00367c19,&puStack_98);
  if (*(int *)(param_2 + 0x1a0) == 2) {
    bVar7 = param_1[0x77] == -1;
code_r0x0c17c26f:
    iVar3 = (int)param_1[0x7d];
joined_r0x0c17c2a1:
    if (iVar3 == 2) goto code_r0x0c17c2a3;
code_r0x0c17c27e:
    if ((iVar3 == 1) && (*(char *)((long)param_1 + 0x3ec) == '\x02')) {
code_r0x0c17c2b0:
      if ((param_1[0x5e] == *(long *)(param_2 + 0x28)) &&
         ((iVar3 = (*(code *)&DAT_120cae9d)(param_1[0x5d],*(undefined8 *)(param_2 + 0x20)),
          iVar3 == 0 && (param_1[0x61] == *(long *)(param_2 + 0x40))))) {
        iVar3 = (*(code *)&DAT_120cae9d)(param_1[0x60],*(undefined8 *)(param_2 + 0x38));
        if ((iVar3 == 0 & (byte)uStack_34) == 1) {
          if (param_1[0x74] == -1) {
            bVar8 = *(long *)(param_2 + 0x148) == -1 || *(long *)(param_2 + 0x130) == -1;
          }
          else {
            if (*(long *)(param_2 + 0x130) == -1) goto code_r0x0c17c39a;
            bVar9 = false;
            if ((*(long *)(param_2 + 0x148) == -1) || (*(long *)(param_2 + 0x158) != param_1[0x76]))
            goto code_r0x0c17c39c;
            iVar3 = (*(code *)&DAT_120cae9d)(param_1[0x75],*(undefined8 *)(param_2 + 0x150));
            bVar8 = iVar3 == 0;
          }
          bVar9 = false;
          if ((!(bool)(bVar8 & bVar7)) || (param_1[100] != lVar4)) goto code_r0x0c17c39c;
          iVar3 = (*(code *)&DAT_120cae9d)(param_1[99],uStack_40,lVar4);
          if (iVar3 == 0) {
            if (param_1[0x7a] == -1) {
              if (*(long *)(param_2 + 0x178) == -1) goto code_r0x0c17c40e;
            }
            else if (((*(long *)(param_2 + 0x178) != -1) &&
                     (param_1[0x7c] == *(long *)(param_2 + 0x188))) &&
                    (iVar3 = (*(code *)&DAT_120cae9d)
                                       (param_1[0x7b],*(undefined8 *)(param_2 + 0x180)), iVar3 == 0)
                    ) {
code_r0x0c17c40e:
              if (((param_1[0x67] == *(long *)(param_2 + 0x110)) &&
                  (iVar3 = (*(code *)&DAT_120cae9d)(param_1[0x66],*(undefined8 *)(param_2 + 0x108)),
                  iVar3 == 0)) &&
                 ((param_1[0x6a] == *(long *)(&UNK_0119b738 + (ulong)*(byte *)(param_2 + 0x1a4) * 8)
                  && (iVar3 = (*(code *)&DAT_120cae9d)
                                        (param_1[0x69],
                                         *(undefined8 *)
                                          (&UNK_12211300 + (ulong)*(byte *)(param_2 + 0x1a4) * 8)),
                     iVar3 == 0)))) {
                bVar1 = *(byte *)(param_2 + 0x1a5);
                if (((param_1[0x6d] == *(long *)(&UNK_0119b750 + (ulong)bVar1 * 8)) &&
                    (iVar3 = (*(code *)&DAT_120cae9d)
                                       (param_1[0x6c],
                                        *(undefined8 *)(&UNK_12211318 + (ulong)bVar1 * 8)),
                    iVar3 == 0)) &&
                   ((param_1[0x70] ==
                     *(long *)(&UNK_0119b768 + (ulong)*(byte *)(param_2 + 0x1a6) * 8) &&
                    ((((iVar3 = (*(code *)&DAT_120cae9d)
                                          (param_1[0x6f],
                                           *(undefined8 *)
                                            (&UNK_12211330 + (ulong)*(byte *)(param_2 + 0x1a6) * 8))
                       , iVar3 == 0 && (param_1[0x80] == lStack_48)) &&
                      (iVar3 = (*(code *)&DAT_120cae9d)(param_1[0x7f],uStack_50), iVar3 == 0)) &&
                     ((param_1[0x83] == *(long *)(param_2 + 0xf8) &&
                      (iVar3 = (*(code *)&DAT_120cae9d)
                                         (param_1[0x82],*(undefined8 *)(param_2 + 0xf0)),
                      (int)lVar2 == 2)))))))) {
                  bVar9 = false;
                  if (iVar3 == 0) {
                    bVar9 = (bool)(char)param_1[0x87] == (bVar1 != 1);
                  }
                  goto code_r0x0c17c39c;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    if (*(int *)(param_2 + 0x1a0) == 1) {
      if (param_1[0x77] == -1) {
        bVar7 = true;
        iVar3 = (int)param_1[0x7d];
        goto joined_r0x0c17c2a1;
      }
      if ((*(long *)(param_2 + 0x118) != -1) && (param_1[0x79] == *(long *)(param_2 + 0x128))) {
        iVar3 = (*(code *)&DAT_120cae9d)(param_1[0x78],*(undefined8 *)(param_2 + 0x120));
        bVar7 = iVar3 == 0;
        goto code_r0x0c17c26f;
      }
    }
    bVar7 = false;
    iVar3 = (int)param_1[0x7d];
    if (iVar3 != 2) goto code_r0x0c17c27e;
code_r0x0c17c2a3:
    if (*(char *)((long)param_1 + 0x3ec) == '\0') goto code_r0x0c17c2b0;
  }
code_r0x0c17c39a:
  bVar9 = false;
code_r0x0c17c39c:
  if (lStack_58 != 0) {
    (*(code *)&DAT_04732840)(uStack_50,lStack_58,1);
  }
  return bVar9;
}

