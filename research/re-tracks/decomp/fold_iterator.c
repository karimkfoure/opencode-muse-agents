
undefined1 * fold_iterator(undefined1 *param_1,long param_2)

{
  byte bVar1;
  undefined1 uVar2;
  long lStack_70;
  int *piStack_68;
  long lStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int *piStack_38;
  undefined1 uVar3;
  
  func_0x078639f0(&lStack_70);
  if (lStack_70 == -1) {
    uVar2 = 0xff;
    goto code_r0x0772a98c;
  }
  bVar1 = *(byte *)(param_2 + 0x48);
  if (bVar1 < 3) {
    if (2 < bVar1) {
code_r0x0772a897:
      piStack_38 = piStack_68;
      func_0x07657e30(param_2 + 0x50);
      piStack_68 = piStack_38;
    }
  }
  else if (bVar1 == 3) {
    if (*(long *)(param_2 + 0x50) != 0) {
      piStack_38 = piStack_68;
      (*(code *)&DAT_04732840)(*(undefined8 *)(param_2 + 0x58),*(long *)(param_2 + 0x50),1);
      piStack_68 = piStack_38;
    }
  }
  else if (bVar1 == 4) {
    piStack_38 = piStack_68;
    func_0x07c89080(param_2 + 0x50);
    piStack_68 = piStack_38;
    if (*(long *)(param_2 + 0x50) != 0) {
      (*(code *)&DAT_04732840)(*(undefined8 *)(param_2 + 0x58),*(long *)(param_2 + 0x50) << 5,8);
      piStack_68 = piStack_38;
    }
  }
  else if (bVar1 != 0xff) goto code_r0x0772a897;
  *(undefined4 *)(param_2 + 0x58) = uStack_48;
  *(undefined4 *)(param_2 + 0x5c) = uStack_44;
  *(undefined4 *)(param_2 + 0x60) = uStack_40;
  *(undefined4 *)(param_2 + 100) = uStack_3c;
  *(undefined4 *)(param_2 + 0x48) = uStack_58;
  *(undefined4 *)(param_2 + 0x4c) = uStack_54;
  *(undefined4 *)(param_2 + 0x50) = uStack_50;
  *(undefined4 *)(param_2 + 0x54) = uStack_4c;
  if (lStack_60 == 4) {
    if (*piStack_68 != 0x7473616c) goto code_r0x0772a976;
    uVar3 = 2;
    uVar2 = 2;
  }
  else if (lStack_60 == 5) {
    if ((char)piStack_68[1] != 't' || *piStack_68 != 0x73726966) goto code_r0x0772a976;
    uVar3 = 1;
    uVar2 = 1;
  }
  else if ((lStack_60 == 6) && ((short)piStack_68[1] == 0x6d61 && *piStack_68 == 0x65727473)) {
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
code_r0x0772a976:
    uVar3 = 3;
    uVar2 = 3;
  }
  if (lStack_70 != 0) {
    (*(code *)&DAT_04732840)(piStack_68,lStack_70,1);
    uVar2 = uVar3;
  }
code_r0x0772a98c:
  param_1[1] = uVar2;
  *param_1 = 0;
  return param_1;
}

