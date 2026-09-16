
long commit_attach_child(long *param_1,long *param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uStack_c0;
  long lStack_b8;
  long lStack_b0;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 uStack_9c;
  undefined2 uStack_9b;
  undefined1 uStack_99;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  char acStack_78 [8];
  undefined1 uStack_70;
  undefined4 uStack_6f;
  undefined2 uStack_6b;
  undefined1 uStack_69;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined8 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  
  lVar2 = *param_1;
  if (lVar2 == -2) {
    lVar2 = (*(code *)&DAT_0ff4ab00)();
    return lVar2;
  }
  (*(code *)&DAT_04732870)();
  puVar3 = (undefined8 *)(*(code *)&DAT_04732830)(8,1);
  if (puVar3 == (undefined8 *)0x0) {
    (*(code *)&DAT_1208422d)(1,8);
    pcVar1 = (code *)swi(3);
    lVar2 = (*pcVar1)();
    return lVar2;
  }
  *puVar3 = 0x6465747065636361;
  if ((lVar2 != -1) && (lVar2 != 0)) {
    (*(code *)&DAT_04732840)(param_1[1],lVar2,1);
  }
  param_1[1] = (long)puVar3;
  param_1[2] = 8;
  *param_1 = -1;
  lStack_b8 = param_1[1];
  lStack_b0 = param_1[2];
  uStack_c0 = 8;
  if (*param_2 != -1) {
    uStack_58 = -1;
    uStack_40 = 0;
    uStack_30 = 0;
    lVar2 = worktree_bind_commit(&uStack_58,&UNK_006d3cc7,0x11,param_2 + 0x2c);
    if (lVar2 == 0) {
      if (uStack_58 == -2) {
code_r0x06dccd75:
        lVar2 = (*(code *)&DAT_0ff4ab00)();
      }
      else {
        lVar2 = worktree_bind_commit(&uStack_58,&UNK_006d425c,0x11,param_2 + 0x2e);
        if (lVar2 == 0) {
          if (uStack_58 == -2) goto code_r0x06dccd75;
          lVar2 = func_0x06e28560(&uStack_58,&UNK_006d426d,0xd,param_2 + 0x30);
          if (lVar2 == 0) {
            if (uStack_58 == -2) goto code_r0x06dccd75;
            func_0x06e2ca80(&uStack_58,&UNK_006d427a,10,param_2);
            lVar2 = func_0x06e1b2f0(&uStack_58,*(undefined1 *)((long)param_2 + 0x191));
            if (((lVar2 == 0) && (lVar2 = func_0x06e1b4e0(&uStack_58,param_2 + 10), lVar2 == 0)) &&
               (lVar2 = func_0x06df7420(&uStack_58,&UNK_006d42a3,0xb,param_2 + 3), lVar2 == 0)) {
              uStack_88 = uStack_38;
              uStack_84 = uStack_34;
              uStack_80 = (undefined4)uStack_30;
              uStack_7c = uStack_30._4_4_;
              uStack_98 = uStack_48;
              uStack_94 = uStack_44;
              uStack_90 = (undefined4)uStack_40;
              uStack_8c = uStack_40._4_4_;
              uStack_a8 = (undefined4)uStack_58;
              uStack_a4 = uStack_58._4_4_;
              uStack_a0 = uStack_50;
              uStack_9c = (undefined1)uStack_4c;
              uStack_9b = (undefined2)((uint)uStack_4c >> 8);
              uStack_99 = (undefined1)((uint)uStack_4c >> 0x18);
              (*(code *)&DAT_0ff4b870)(acStack_78,&uStack_a8);
              if (acStack_78[0] == -1) {
                lVar2 = CONCAT17(uStack_69,CONCAT25(uStack_6b,CONCAT41(uStack_6f,uStack_70)));
                goto code_r0x06dcce45;
              }
              goto code_r0x06dccd84;
            }
          }
        }
      }
    }
    func_0x06d08070(&uStack_58);
code_r0x06dcce45:
    (*(code *)&DAT_04732840)(lStack_b8,8,1);
    return lVar2;
  }
  acStack_78[0] = '\0';
code_r0x06dccd84:
  uStack_98 = uStack_68;
  uStack_94 = uStack_64;
  uStack_90 = uStack_60;
  uStack_8c = uStack_5c;
  uStack_a8 = CONCAT31((int3)acStack_78._1_7_,acStack_78[0]);
  uStack_a4 = SUB74(acStack_78._1_7_,3);
  uStack_a0 = CONCAT31((int3)uStack_6f,uStack_70);
  uStack_9c = (undefined1)((uint)uStack_6f >> 0x18);
  uStack_9b = uStack_6b;
  uStack_99 = uStack_69;
  bind_validator(&uStack_58,param_1 + 3,&uStack_c0,&uStack_a8);
  if ((byte)uStack_58 < 3) {
    if ((byte)uStack_58 < 3) {
      return 0;
    }
code_r0x06dcce0a:
    func_0x07813660(&uStack_50);
  }
  else {
    if ((byte)uStack_58 == 3) {
      lVar2 = CONCAT44(uStack_4c,uStack_50);
      if (lVar2 == 0) {
        return 0;
      }
      uVar5 = CONCAT44(uStack_44,uStack_48);
      uVar4 = 1;
    }
    else {
      if ((byte)uStack_58 != 4) {
        if ((byte)uStack_58 == 0xff) {
          return 0;
        }
        goto code_r0x06dcce0a;
      }
      func_0x07c89080(&uStack_50);
      if (CONCAT44(uStack_4c,uStack_50) == 0) {
        return 0;
      }
      uVar5 = CONCAT44(uStack_44,uStack_48);
      lVar2 = CONCAT44(uStack_4c,uStack_50) << 5;
      uVar4 = 8;
    }
    (*(code *)&DAT_04732840)(uVar5,lVar2,uVar4);
  }
  return 0;
}

