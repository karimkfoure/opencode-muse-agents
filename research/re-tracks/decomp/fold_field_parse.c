
uint fold_field_parse(long param_1)

{
  uint uVar1;
  char cStack_28;
  undefined4 uStack_27;
  undefined4 uStack_23;
  undefined4 uStack_1f;
  undefined3 uStack_1b;
  undefined1 uStack_18;
  undefined3 uStack_17;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  cStack_28 = *(char *)(param_1 + 0x48);
  *(undefined1 *)(param_1 + 0x48) = 0xff;
  if (cStack_28 != -1) {
    uStack_27 = *(undefined4 *)(param_1 + 0x49);
    uStack_23 = *(undefined4 *)(param_1 + 0x4d);
    uStack_1f = *(undefined4 *)(param_1 + 0x51);
    uStack_14 = *(undefined4 *)(param_1 + 0x5c);
    uStack_10 = *(undefined4 *)(param_1 + 0x60);
    uStack_c = *(undefined4 *)(param_1 + 100);
    uStack_1b = (undefined3)*(undefined4 *)(param_1 + 0x55);
    uStack_18 = (undefined1)*(undefined4 *)(param_1 + 0x58);
    uStack_17 = (undefined3)((uint)*(undefined4 *)(param_1 + 0x58) >> 8);
    uVar1 = func_0x073ec410(&cStack_28);
    return uVar1 & 1;
  }
  phase_step_emit(&UNK_00222500,0x10);
  return 1;
}

