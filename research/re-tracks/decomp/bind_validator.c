
undefined8 * bind_validator(undefined8 *param_1,long *param_2,long *param_3,undefined8 *param_4)

{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  long *plVar8;
  undefined8 *puVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long *unaff_R15;
  undefined1 auStack_100 [24];
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  long *plStack_d8;
  long lStack_c8;
  long lStack_c0;
  long lStack_b8;
  long lStack_a8;
  long *plStack_a0;
  long *plStack_98;
  long lStack_90;
  long lStack_88;
  long lStack_80;
  long *plStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  long *plStack_60;
  long lStack_58;
  long *plStack_50;
  undefined8 *puStack_48;
  undefined8 *puStack_40;
  long lStack_38;
  
  lVar13 = *param_2;
  if (lVar13 == 0) {
    uStack_70 = 0;
    lStack_c8 = *param_3;
    lVar13 = param_3[1];
    plStack_d8 = unaff_R15;
joined_r0x077d66e5:
    if (lStack_c8 == -1) {
code_r0x077d6824:
      lVar10 = (long)param_2 * 0x20;
      uVar4 = *(undefined8 *)(lVar13 + lVar10);
      uVar5 = ((undefined8 *)(lVar13 + lVar10))[1];
      puVar9 = (undefined8 *)(lVar13 + 0x10 + lVar10);
      uVar6 = puVar9[1];
      param_1[2] = *puVar9;
      param_1[3] = uVar6;
      *param_1 = uVar4;
      param_1[1] = uVar5;
      uVar4 = param_4[1];
      uVar5 = param_4[2];
      uVar6 = param_4[3];
      *(undefined8 *)(lVar13 + lVar10) = *param_4;
      ((undefined8 *)(lVar13 + lVar10))[1] = uVar4;
      puVar9 = (undefined8 *)(lVar13 + 0x10 + lVar10);
      *puVar9 = uVar5;
      puVar9[1] = uVar6;
    }
    else {
      lStack_b8 = param_3[2];
      uStack_68 = 0;
      lStack_90 = lStack_c8;
      lStack_88 = lVar13;
      lStack_80 = lStack_b8;
      plStack_78 = param_2;
      plStack_60 = plStack_d8;
      lStack_38 = lVar13;
      if (uStack_70 == 0) {
        (*(code *)&DAT_04732870)();
        puVar9 = (undefined8 *)(*(code *)&DAT_04732830)(0x278,8);
        if (puVar9 == (undefined8 *)0x0) {
          (*(code *)&DAT_12088f47)(8,0x278);
          pcVar3 = (code *)swi(3);
          puVar9 = (undefined8 *)(*pcVar3)();
          return puVar9;
        }
        puVar9[0x2c] = 0;
        *param_2 = (long)puVar9;
        param_2[1] = 0;
        *(undefined2 *)((long)puVar9 + 0x272) = 1;
        puVar9[0x2d] = lStack_90;
        puVar9[0x2e] = lStack_88;
        puVar9[0x2f] = lStack_80;
        uVar4 = param_4[1];
        uVar5 = param_4[2];
        uVar6 = param_4[3];
        *puVar9 = *param_4;
        puVar9[1] = uVar4;
        puVar9[2] = uVar5;
        puVar9[3] = uVar6;
      }
      else {
        uStack_70._4_4_ = (undefined4)((ulong)uStack_70 >> 0x20);
        uStack_e8 = (undefined4)uStack_70;
        uStack_e4 = uStack_70._4_4_;
        uStack_e0 = 0;
        uStack_dc = 0;
        lStack_c0 = lVar13;
        func_0x06b4d550(auStack_100,&uStack_e8,&lStack_c8,param_4,&plStack_78,&lStack_58);
        param_2 = plStack_78;
      }
      param_2[2] = param_2[2] + 1;
      *(undefined1 *)param_1 = 0xff;
    }
    return param_1;
  }
  lVar10 = param_2[1];
  lStack_38 = param_3[1];
  uVar1 = param_3[2];
  plVar8 = (long *)(ulong)*(ushort *)(lVar13 + 0x272);
  plStack_98 = param_2;
  plStack_50 = param_3;
  puStack_48 = param_1;
  puStack_40 = param_4;
  if (plVar8 == (long *)0x0) goto code_r0x077d6680;
code_r0x077d65c4:
  lStack_a8 = (ulong)(uint)((int)plVar8 * 8) * 3;
  lVar14 = 0;
  param_2 = (long *)0x0;
  plStack_a0 = plVar8;
  lStack_58 = lVar10;
  do {
    uVar2 = *(ulong *)(lVar13 + 0x178 + lVar14);
    uVar11 = uVar2;
    if (uVar1 < uVar2) {
      uVar11 = uVar1;
    }
    iVar7 = (*(code *)&DAT_120caf7f)(lStack_38,*(undefined8 *)(lVar13 + 0x170 + lVar14),uVar11);
    lVar12 = uVar1 - uVar2;
    if (iVar7 != 0) {
      lVar12 = (long)iVar7;
    }
    uStack_70 = lVar13;
    lVar10 = lStack_58;
    if ((char)((0 < lVar12) - (lVar12 < 0)) != '\x01') {
      plStack_d8 = param_2;
      if (0 < lVar12 == lVar12 < 0) {
        param_4 = puStack_40;
        param_1 = puStack_48;
        if (*plStack_50 != 0) {
          (*(code *)&DAT_04732840)(lStack_38,*plStack_50,1);
          param_4 = puStack_40;
          param_1 = puStack_48;
        }
        goto code_r0x077d6824;
      }
      break;
    }
    param_2 = (long *)((long)param_2 + 1);
    lVar14 = lVar14 + 0x18;
    plStack_d8 = plStack_a0;
  } while (lStack_a8 != lVar14);
  do {
    if (lVar10 == 0) {
      lStack_c8 = *plStack_50;
      lVar13 = lStack_38;
      param_2 = plStack_98;
      param_3 = plStack_50;
      param_1 = puStack_48;
      param_4 = puStack_40;
      goto joined_r0x077d66e5;
    }
    lVar10 = lVar10 + -1;
    lVar13 = *(long *)(uStack_70 + 0x278 + (long)plStack_d8 * 8);
    plVar8 = (long *)(ulong)*(ushort *)(lVar13 + 0x272);
    if (plVar8 != (long *)0x0) goto code_r0x077d65c4;
code_r0x077d6680:
    plStack_d8 = (long *)0x0;
    uStack_70 = lVar13;
  } while( true );
}

