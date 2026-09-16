
undefined8 worktree_place(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  ulong auStack_238 [3];
  undefined8 uStack_220;
  ulong uStack_218;
  undefined8 uStack_210;
  long lStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_88;
  long lStack_80;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined8 uStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  undefined8 uStack_40;
  long lStack_38;
  
  lVar7 = *(long *)(param_3 + 0xd8);
  uVar1 = *(undefined8 *)(param_3 + 0xe0);
  lVar2 = *(long *)(param_3 + 0xe8);
  uStack_40 = param_1;
  lStack_38 = param_2;
  (*(code *)&DAT_120cba68)(auStack_238,param_4,0x1b0);
  uVar5 = auStack_238[0];
  uStack_88 = 0;
  lStack_80 = lVar2;
  if ((lVar7 != -1) && (uStack_88 = uVar1, auStack_238[0] != 0xffffffffffffffff)) {
    auStack_238[2] = *(long *)(param_3 + 0x4b0);
    uStack_220 = *(undefined8 *)(param_3 + 0x4b8);
    auStack_238[0] = (ulong)(auStack_238[2] != 0);
    uStack_1f8 = 0;
    if (auStack_238[2] != 0) {
      uStack_1f8 = *(undefined8 *)(param_3 + 0x4c0);
    }
    auStack_238[1] = 0;
    uStack_210 = 0;
    uStack_218 = auStack_238[0];
    lStack_208 = auStack_238[2];
    uStack_200 = uStack_220;
    func_0x076fd180(&uStack_58,auStack_238);
    if (lVar2 < 0) {
      uVar8 = 0;
    }
    else {
      if (lVar2 == 0) {
        lVar6 = 1;
        lVar7 = 0;
code_r0x06e85c2d:
        (*(code *)&DAT_12068c80)(auStack_238,lVar6,lVar7,&UNK_006d7abc,0xf);
        uStack_60 = uStack_48;
        uStack_70 = uStack_58;
        uStack_6c = uStack_54;
        uStack_68 = uStack_50;
        uStack_64 = uStack_4c;
        (*(code *)&DAT_120cba68)(&uStack_220,param_4,0x1b0);
        lVar4 = lStack_38;
        lVar7 = lStack_38 + 0x460;
        lVar3 = *(long *)(lStack_38 + 0x460);
        if (lVar3 != -1) {
          if (lVar3 != 0) {
            (*(code *)&DAT_04732840)(*(undefined8 *)(lStack_38 + 0x468),lVar3,1);
          }
          func_0x0782fba0(lVar4 + 0x628);
          func_0x0596c0a0(lVar4 + 0x478);
        }
        (*(code *)&DAT_120cba68)(lVar7,auStack_238,0x1e0);
        uVar1 = uStack_40;
        (*(code *)&DAT_120cba68)(uStack_40,lVar4,0x660);
        if (lVar2 == 0) {
          return uVar1;
        }
        (*(code *)&DAT_04732840)(lVar6,lVar2,1);
        return uVar1;
      }
      (*(code *)&DAT_04732870)();
      uVar8 = 1;
      lVar6 = (*(code *)&DAT_04732830)(lVar2,1);
      if (lVar6 != 0) {
        (*(code *)&DAT_120cba68)(lVar6,uVar1,lVar2);
        lVar7 = lVar2;
        goto code_r0x06e85c2d;
      }
    }
    uVar5 = (*(code *)&DAT_1208422d)(uVar8,lVar2);
  }
  if (uVar5 != 0xffffffffffffffff) {
    func_0x06cf9b20(auStack_238);
  }
  uVar1 = uStack_40;
  (*(code *)&DAT_120cba68)(uStack_40,lStack_38,0x660);
  return uVar1;
}

