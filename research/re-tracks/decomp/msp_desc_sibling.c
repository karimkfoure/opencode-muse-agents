
void msp_desc_sibling(undefined8 *param_1,undefined8 param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uStack_b8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 uStack_a8;
  undefined8 *puStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  uStack_b8 = 0;
  uStack_a8 = 0;
  (*(code *)&DAT_04732870)();
  puVar3 = (undefined4 *)(*(code *)&DAT_04732830)(4,1);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0x65707974;
    uStack_98 = 4;
    uStack_88 = 4;
    uStack_90 = puVar3;
    (*(code *)&DAT_04732870)();
    uStack_68 = (undefined4 *)(*(code *)&DAT_04732830)(6,1);
    if (uStack_68 == (undefined4 *)0x0) goto code_r0x0a81c295;
    *(undefined2 *)(uStack_68 + 1) = 0x7463;
    *uStack_68 = 0x656a626f;
    _uStack_78 = CONCAT71(stack0xffffffffffffff89,3);
    uStack_70 = 6;
    uStack_60 = 6;
    schema_field_register(&uStack_58,&uStack_b8,&uStack_98,&uStack_78);
    uVar2 = uStack_58 & 0xff;
    if (uVar2 < 3) {
      if (2 < uVar2) {
code_r0x0a81be8b:
        func_0x0a833220(&uStack_50);
      }
    }
    else if (uVar2 == 3) {
      lVar5 = CONCAT44(uStack_4c,uStack_50);
      if (lVar5 != 0) {
        uVar6 = CONCAT44(uStack_44,uStack_48);
        uVar4 = 1;
code_r0x0a81bec9:
        (*(code *)&DAT_04732840)(uVar6,lVar5,uVar4);
      }
    }
    else if ((uStack_58 & 0xff) == 4) {
      func_0x0a779560(&uStack_50);
      if (CONCAT44(uStack_4c,uStack_50) != 0) {
        uVar6 = CONCAT44(uStack_44,uStack_48);
        lVar5 = CONCAT44(uStack_4c,uStack_50) << 5;
        uVar4 = 8;
        goto code_r0x0a81bec9;
      }
    }
    else if ((uStack_58 & 0xff) != 0xff) goto code_r0x0a81be8b;
    uStack_70 = uStack_b8;
    uStack_68._0_4_ = uStack_b0;
    uStack_68._4_4_ = uStack_ac;
    uStack_60 = uStack_a8;
    _uStack_78 = CONCAT71(stack0xffffffffffffff89,5);
    (*(code *)&DAT_0a8a52b0)(&uStack_58,&uStack_78);
    if ((char)uStack_58 != -1) {
      uStack_88 = CONCAT44(uStack_44,uStack_48);
      uStack_80 = uStack_40;
      uStack_7c = uStack_3c;
      uStack_98 = CONCAT44(uStack_54,uStack_58);
      uStack_90 = (undefined4 *)CONCAT44(uStack_4c,uStack_50);
      func_0x0a79e330(&uStack_78,param_2);
      func_0x0a762a30(&uStack_78,&UNK_0096a6dd,0xb,&UNK_0096b332,0x1e);
      uStack_48 = (undefined4)uStack_68;
      uStack_44 = uStack_68._4_4_;
      uStack_40 = (undefined4)uStack_60;
      uStack_3c = uStack_60._4_4_;
      uStack_58 = uStack_78;
      uStack_54 = uStack_74;
      uStack_50 = (undefined4)uStack_70;
      uStack_4c = uStack_70._4_4_;
      puStack_a0 = param_1;
      (*(code *)&DAT_0a894b90)(&uStack_98,&UNK_0096b350,7,0,&uStack_58);
      func_0x0a7c6960(&uStack_78,param_2);
      func_0x0a762a30(&uStack_78,&UNK_0096a6dd,0xb,&UNK_0096b357,0x13);
      uStack_48 = (undefined4)uStack_68;
      uStack_44 = uStack_68._4_4_;
      uStack_40 = (undefined4)uStack_60;
      uStack_3c = uStack_60._4_4_;
      uStack_58 = uStack_78;
      uStack_54 = uStack_74;
      uStack_50 = (undefined4)uStack_70;
      uStack_4c = uStack_70._4_4_;
      (*(code *)&DAT_0a894b90)(&uStack_98,&UNK_0096b36a,7,0,&uStack_58);
      func_0x0a79e330(&uStack_78,param_2);
      func_0x0a762a30(&uStack_78,&UNK_0096a6dd,0xb,&UNK_0096b371,0x51);
      uStack_48 = (undefined4)uStack_68;
      uStack_44 = uStack_68._4_4_;
      uStack_40 = (undefined4)uStack_60;
      uStack_3c = uStack_60._4_4_;
      uStack_58 = uStack_78;
      uStack_54 = uStack_74;
      uStack_50 = (undefined4)uStack_70;
      uStack_4c = uStack_70._4_4_;
      (*(code *)&DAT_0a894b90)(&uStack_98,&UNK_0096b3c2,6,0,&uStack_58);
      func_0x0a77fce0(&uStack_78,param_2);
      func_0x0a762a30(&uStack_78,&UNK_0096a6dd,0xb,&UNK_0096b3c8,0x21);
      uStack_48 = (undefined4)uStack_68;
      uStack_44 = uStack_68._4_4_;
      uStack_40 = (undefined4)uStack_60;
      uStack_3c = uStack_60._4_4_;
      uStack_58 = uStack_78;
      uStack_54 = uStack_74;
      uStack_50 = (undefined4)uStack_70;
      uStack_4c = uStack_70._4_4_;
      (*(code *)&DAT_0a894b90)(&uStack_98,&UNK_0096b3e9,5,1,&uStack_58);
      func_0x0a77fce0(&uStack_78,param_2);
      func_0x0a762a30(&uStack_78,&UNK_0096a6dd,0xb,&UNK_0096b3ee,0x29);
      uStack_48 = (undefined4)uStack_68;
      uStack_44 = uStack_68._4_4_;
      uStack_40 = (undefined4)uStack_60;
      uStack_3c = uStack_60._4_4_;
      uStack_58 = uStack_78;
      uStack_54 = uStack_74;
      uStack_50 = (undefined4)uStack_70;
      uStack_4c = uStack_70._4_4_;
      (*(code *)&DAT_0a894b90)(&uStack_98,&UNK_0096b417,5,1,&uStack_58);
      func_0x0a783b20(&uStack_78,param_2);
      func_0x0a762a30(&uStack_78,&UNK_0096a6dd,0xb,&UNK_0096b41c,0x2a);
      uStack_48 = (undefined4)uStack_68;
      uStack_44 = uStack_68._4_4_;
      uStack_40 = (undefined4)uStack_60;
      uStack_3c = uStack_60._4_4_;
      uStack_58 = uStack_78;
      uStack_54 = uStack_74;
      uStack_50 = (undefined4)uStack_70;
      uStack_4c = uStack_70._4_4_;
      (*(code *)&DAT_0a894b90)(&uStack_98,&UNK_0096b446,5,1,&uStack_58);
      func_0x0a78f0b0(&uStack_78,param_2);
      func_0x0a762a30(&uStack_78,&UNK_0096a6dd,0xb,&UNK_0096b44b,0x2d);
      uStack_48 = (undefined4)uStack_68;
      uStack_44 = uStack_68._4_4_;
      uStack_40 = (undefined4)uStack_60;
      uStack_3c = uStack_60._4_4_;
      uStack_58 = uStack_78;
      uStack_54 = uStack_74;
      uStack_50 = (undefined4)uStack_70;
      uStack_4c = uStack_70._4_4_;
      (*(code *)&DAT_0a894b90)(&uStack_98,&UNK_0096b478,10,1,&uStack_58);
      func_0x0a7830c0(&uStack_78,param_2);
      func_0x0a762a30(&uStack_78,&UNK_0096a6dd,0xb,&UNK_0096b482,0x34);
      uStack_48 = (undefined4)uStack_68;
      uStack_44 = uStack_68._4_4_;
      uStack_40 = (undefined4)uStack_60;
      uStack_3c = uStack_60._4_4_;
      uStack_58 = uStack_78;
      uStack_54 = uStack_74;
      uStack_50 = (undefined4)uStack_70;
      uStack_4c = uStack_70._4_4_;
      (*(code *)&DAT_0a894b90)(&uStack_98,&UNK_00263658,8,1,&uStack_58);
      func_0x0a77fce0(&uStack_78,param_2);
      func_0x0a762a30(&uStack_78,&UNK_0096a6dd,0xb,&UNK_0096b4b6,0x6f);
      uStack_48 = (undefined4)uStack_68;
      uStack_44 = uStack_68._4_4_;
      uStack_40 = (undefined4)uStack_60;
      uStack_3c = uStack_60._4_4_;
      uStack_58 = uStack_78;
      uStack_54 = uStack_74;
      uStack_50 = (undefined4)uStack_70;
      uStack_4c = uStack_70._4_4_;
      (*(code *)&DAT_0a894b90)(&uStack_98,&UNK_0096b525,9,1,&uStack_58);
      func_0x0a762a30(&uStack_98,&UNK_0096a6dd,0xb,&UNK_0096b52e,0x6d);
      puStack_a0[2] = uStack_88;
      puStack_a0[3] = CONCAT44(uStack_7c,uStack_80);
      *puStack_a0 = uStack_98;
      puStack_a0[1] = uStack_90;
      return;
    }
    (*(code *)&DAT_120a9080)(&UNK_0096a745,0x2b,&uStack_78,&UNK_121b5c10,&UNK_121b5cc0);
  }
  (*(code *)&DAT_1208422d)(1,4);
code_r0x0a81c295:
  (*(code *)&DAT_1208422d)(1,6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

