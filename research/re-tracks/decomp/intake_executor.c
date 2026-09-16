
undefined1 * intake_executor(undefined1 *param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lStack_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined8 uStack_80;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined8 uStack_70;
  long lStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  lVar1 = *(long *)(param_2 + 0x18);
  lVar2 = *(long *)(param_2 + 0x30);
  lStack_98 = -1;
  uStack_80 = 0;
  uStack_70 = 0;
  lVar3 = func_0x06e1c8a0(&lStack_98,*(undefined8 *)(param_3 + 0x20),*(undefined8 *)(param_3 + 0x28)
                          ,*(undefined8 *)(param_3 + 0x30),*(undefined8 *)(param_3 + 0x38));
  if (lVar3 != 0) {
    func_0x06656870(&lStack_98);
code_r0x079ba883:
    *(long *)(param_1 + 8) = lVar3;
    *param_1 = 0xff;
    return param_1;
  }
  lVar3 = CONCAT44(uStack_8c,uStack_90);
  if (lStack_98 == -3) goto code_r0x079ba883;
  uStack_50 = CONCAT44(uStack_84,uStack_88);
  uStack_48 = uStack_80;
  uStack_40 = uStack_78;
  uStack_3c = uStack_74;
  uStack_38 = (undefined4)uStack_70;
  uStack_34 = uStack_70._4_4_;
  lStack_60 = lStack_98;
  uStack_58 = lVar3;
  lVar3 = func_0x06e13f50(&lStack_60,&UNK_0026ce2c,4,param_2 + 0x48);
  if (lVar3 != 0) goto code_r0x079ba906;
  if (lStack_60 != -2) {
    lVar3 = func_0x06e2ca80(&lStack_60,&UNK_0070f3fd,0xb,param_2);
    if (lVar3 != 0) goto code_r0x079ba906;
    if (lVar1 != -1) {
      if (lStack_60 == -2) goto code_r0x079ba8e1;
      lVar3 = func_0x06e28770(&lStack_60,&UNK_002699dc,4,param_2 + 0x18);
      if (lVar3 != 0) goto code_r0x079ba906;
    }
    if (lVar2 == -1) {
code_r0x079ba974:
      uStack_78 = uStack_40;
      uStack_74 = uStack_3c;
      uStack_70 = CONCAT44(uStack_34,uStack_38);
      uStack_88 = (undefined4)uStack_50;
      uStack_84 = uStack_50._4_4_;
      uStack_80 = uStack_48;
      lStack_98 = lStack_60;
      uStack_90 = (undefined4)uStack_58;
      uStack_8c = uStack_58._4_4_;
      (*(code *)&DAT_0ff4b870)(param_1,&lStack_98);
      return param_1;
    }
    if (lStack_60 != -2) {
      lVar3 = func_0x06e28770(&lStack_60,&UNK_0070eb48,6,param_2 + 0x30);
      if (lVar3 == 0) goto code_r0x079ba974;
      goto code_r0x079ba906;
    }
  }
code_r0x079ba8e1:
  lVar3 = (*(code *)&DAT_0ff4ab00)();
code_r0x079ba906:
  *(long *)(param_1 + 8) = lVar3;
  *param_1 = 0xff;
  func_0x07977c60(&lStack_60);
  return param_1;
}

