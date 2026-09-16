
undefined8 *
schema_field_register(undefined8 *param_1,long *param_2,long *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  int iVar8;
  long *plVar9;
  long lVar10;
  ulong uVar12;
  long lVar13;
  long lVar14;
  long *unaff_R15;
  long lStack_a8;
  long lStack_a0;
  long lStack_98;
  long *plStack_90;
  long lStack_88;
  undefined8 uStack_80;
  long *plStack_78;
  long lStack_70;
  long *plStack_68;
  long *plStack_60;
  long lStack_58;
  long *plStack_50;
  undefined8 *puStack_48;
  undefined8 *puStack_40;
  long lStack_38;
  long lVar11;
  
  lVar13 = *param_2;
  if (lVar13 == 0) {
    lStack_a8 = *param_3;
    lStack_38 = param_3[1];
    lStack_88 = 0;
    plStack_78 = unaff_R15;
    puVar7 = param_4;
    puVar1 = puStack_40;
joined_r0x0a82c153:
    puStack_40 = puVar7;
    lVar13 = lStack_38;
    if (lStack_a8 == -1) {
code_r0x0a82c1ba:
      lVar10 = (long)param_2 * 0x20;
      uVar4 = *(undefined8 *)(lVar13 + lVar10);
      uVar5 = ((undefined8 *)(lVar13 + lVar10))[1];
      puVar1 = (undefined8 *)(lVar13 + 0x10 + lVar10);
      uVar6 = puVar1[1];
      param_1[2] = *puVar1;
      param_1[3] = uVar6;
      *param_1 = uVar4;
      param_1[1] = uVar5;
      uVar4 = puStack_40[1];
      uVar5 = puStack_40[2];
      uVar6 = puStack_40[3];
      *(undefined8 *)(lVar13 + lVar10) = *puStack_40;
      ((undefined8 *)(lVar13 + lVar10))[1] = uVar4;
      puVar1 = (undefined8 *)(lVar13 + 0x10 + lVar10);
      *puVar1 = uVar5;
      puVar1[1] = uVar6;
    }
    else {
      lStack_98 = param_3[2];
      uStack_80 = 0;
      lStack_a0 = lVar13;
      plStack_90 = param_2;
      puVar7 = puStack_40;
      puStack_40 = puVar1;
      lStack_38 = lVar13;
      func_0x0a8223a0(&lStack_a8,puVar7);
      *(undefined1 *)param_1 = 0xff;
    }
    return param_1;
  }
  lVar10 = param_2[1];
  lStack_38 = param_3[1];
  uVar2 = param_3[2];
  plVar9 = (long *)(ulong)*(ushort *)(lVar13 + 0x272);
  plStack_60 = param_2;
  plStack_50 = param_3;
  puStack_48 = param_1;
  puStack_40 = param_4;
  if (plVar9 == (long *)0x0) goto code_r0x0a82c0f0;
code_r0x0a82c062:
  lStack_70 = (ulong)(uint)((int)plVar9 * 8) * 3;
  lVar14 = 0;
  param_2 = (long *)0x0;
  plStack_68 = plVar9;
  lStack_58 = lVar10;
  do {
    uVar3 = *(ulong *)(lVar13 + 0x178 + lVar14);
    uVar12 = uVar3;
    if (uVar2 < uVar3) {
      uVar12 = uVar2;
    }
    iVar8 = (*(code *)&DAT_120caf7f)(lStack_38,*(undefined8 *)(lVar13 + 0x170 + lVar14),uVar12);
    lVar10 = uVar2 - uVar3;
    if (iVar8 != 0) {
      lVar10 = (long)iVar8;
    }
    lVar11 = lStack_58;
    if ((char)((0 < lVar10) - (lVar10 < 0)) != '\x01') {
      plStack_78 = param_2;
      if (0 < lVar10 == lVar10 < 0) {
        param_1 = puStack_48;
        if (*plStack_50 != 0) {
          (*(code *)&DAT_04732840)(lStack_38,*plStack_50,1);
          param_1 = puStack_48;
        }
        goto code_r0x0a82c1ba;
      }
      break;
    }
    param_2 = (long *)((long)param_2 + 1);
    lVar14 = lVar14 + 0x18;
    plStack_78 = plStack_68;
  } while (lStack_70 != lVar14);
  do {
    lVar10 = lVar11 + -1;
    if (lVar11 == 0) {
      lStack_a8 = *plStack_50;
      lStack_88 = lVar13;
      param_1 = puStack_48;
      param_2 = plStack_60;
      param_3 = plStack_50;
      puVar7 = puStack_40;
      puVar1 = puStack_40;
      goto joined_r0x0a82c153;
    }
    lVar13 = *(long *)(lVar13 + 0x278 + (long)plStack_78 * 8);
    plVar9 = (long *)(ulong)*(ushort *)(lVar13 + 0x272);
    if (plVar9 != (long *)0x0) goto code_r0x0a82c062;
code_r0x0a82c0f0:
    lVar11 = lVar10;
    plStack_78 = (long *)0x0;
  } while( true );
}

