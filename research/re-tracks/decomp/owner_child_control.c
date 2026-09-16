
long * owner_child_control(long *param_1,int *param_2)

{
  undefined4 *puVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  long *plVar8;
  long lVar9;
  undefined *puVar10;
  long lVar11;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  long lStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  if (*param_2 == 2) {
    uStack_50 = (long *)0x8;
    uStack_48 = (int *)0x0;
    lStack_58 = 0;
  }
  else {
    puVar10 = *(undefined **)(param_2 + 0x128);
    lVar11 = *(long *)(param_2 + 0x12a);
    if ((char)param_2[0x1cd] == '\x01') {
      plVar8 = (long *)(*(code *)&DAT_06c60840)(puVar10,lVar11);
      if (plVar8 == (long *)0x0) goto code_r0x07587898;
      if (*plVar8 != -1) {
        lVar11 = 0xc;
      }
      if ((int)*plVar8 != -1) {
        puVar10 = &UNK_006de48d;
      }
    }
    lVar9 = (*(code *)&DAT_06c60840)(puVar10,lVar11);
    if (lVar9 == 0) {
code_r0x07587898:
      (*(code *)&DAT_120a43e0)(&UNK_006cd078,0x31,&UNK_121357f0);
code_r0x075878b1:
      (*(code *)&DAT_12088fdb)(param_2,lVar11,&UNK_1214ab00);
      pcVar3 = (code *)swi(3);
      plVar8 = (long *)(*pcVar3)();
      return plVar8;
    }
    lStack_58 = *(long *)(lVar9 + 0x90);
    uStack_50 = (long *)(*(long *)(lVar9 + 0x98) * 0x10 + lStack_58);
    uStack_40 = *(undefined4 *)(lVar9 + 0xa0);
    uStack_3c = *(undefined4 *)(lVar9 + 0xa4);
    uStack_38 = *(undefined4 *)(lVar9 + 0xa8);
    uStack_34 = *(undefined4 *)(lVar9 + 0xac);
    uStack_48 = param_2;
    func_0x07bb2ea0(&uStack_78,&lStack_58);
    func_0x075878d0(param_2,&uStack_78);
    func_0x075880f0(param_2,&uStack_78);
    lStack_58 = CONCAT44(uStack_74,uStack_78);
    uStack_50 = (long *)CONCAT44(uStack_6c,uStack_70);
    uStack_48 = (int *)CONCAT44(uStack_64,uStack_68);
    lVar9 = (long)uStack_48;
    uStack_48 = (int *)lVar9;
    if (uStack_48 != (int *)0x0) {
      param_2 = (int *)0x0;
      lVar11 = 0;
      do {
        if ((*(long *)((long)uStack_50 + lVar11 + 0x10) == 8) &&
           (**(long **)((long)uStack_50 + lVar11 + 8) == 0x776f6c666b726f77)) {
          if (param_2 != (int *)0x0) {
            lVar2 = *(long *)((long)uStack_50 + lVar11);
            puVar1 = (undefined4 *)((long)uStack_50 + lVar11 + 8);
            uStack_78 = *puVar1;
            uStack_74 = puVar1[1];
            uStack_70 = puVar1[2];
            uStack_6c = puVar1[3];
            (*(code *)&DAT_120cba9a)
                      ((long)uStack_50 + lVar11,(long)uStack_50 + lVar11 + 0x18,
                       ((long)uStack_48 * 0x18 - lVar11) + -0x18);
            uVar7 = uStack_6c;
            uVar6 = uStack_70;
            uVar5 = uStack_74;
            uVar4 = uStack_78;
            lVar11 = (long)uStack_48 + -1;
            uStack_48 = (int *)lVar11;
            if (lVar2 == -1) goto code_r0x075878b1;
            if (lVar11 == lStack_58) {
              (*(code *)&DAT_1201b150)(&lStack_58);
            }
            plVar8 = uStack_50;
            (*(code *)&DAT_120cba9a)(uStack_50 + 3,uStack_50,lVar11 * 0x18);
            *plVar8 = lVar2;
            *(undefined4 *)(plVar8 + 1) = uVar4;
            *(undefined4 *)((long)plVar8 + 0xc) = uVar5;
            *(undefined4 *)(plVar8 + 2) = uVar6;
            *(undefined4 *)((long)plVar8 + 0x14) = uVar7;
            uStack_48 = (int *)lVar9;
          }
          break;
        }
        param_2 = (int *)((long)param_2 + 1);
        lVar11 = lVar11 + 0x18;
      } while ((long)uStack_48 * 0x18 != lVar11);
    }
  }
  func_0x07587fd0(&lStack_58);
  param_1[2] = (long)uStack_48;
  *param_1 = lStack_58;
  param_1[1] = (long)uStack_50;
  return param_1;
}

