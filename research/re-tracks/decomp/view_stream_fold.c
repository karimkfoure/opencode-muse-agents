
/* WARNING: Type propagation algorithm not settling */

ulong * view_stream_fold(ulong *param_1,long param_2)

{
  int iVar1;
  byte bVar2;
  ulong *puVar3;
  byte bVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  ulong uVar9;
  undefined8 uVar10;
  long lVar11;
  ulong uVar12;
  ulong unaff_R12;
  ulong unaff_R13;
  ulong uVar13;
  bool bVar14;
  bool bVar15;
  undefined1 auVar16 [16];
  undefined1 auStack_410 [344];
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  ulong uStack_2a8;
  ulong uStack_2a0;
  ulong uStack_298;
  ulong uStack_290;
  undefined4 uStack_288;
  undefined4 uStack_284;
  undefined4 uStack_280;
  undefined4 uStack_27c;
  ulong uStack_278;
  ulong uStack_270;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined8 uStack_250;
  ulong uStack_248;
  ulong uStack_240;
  ulong uStack_238;
  ulong uStack_230;
  ulong uStack_228;
  ulong uStack_220;
  ulong uStack_218;
  ulong uStack_210;
  ulong uStack_208;
  ulong uStack_200;
  ulong uStack_1f8;
  ulong uStack_1f0;
  ulong uStack_1e8;
  ulong uStack_1e0;
  undefined1 auStack_1d8 [64];
  long lStack_198;
  byte bStack_190;
  undefined4 uStack_18f;
  undefined4 uStack_18b;
  undefined4 uStack_187;
  undefined4 uStack_183;
  undefined3 uStack_17f;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  ulong uStack_170;
  ulong uStack_168;
  ulong uStack_160;
  ulong uStack_158;
  ulong uStack_150;
  ulong uStack_148;
  ulong uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  ulong uStack_120;
  byte bStack_118;
  undefined4 uStack_117;
  undefined4 uStack_113;
  undefined4 uStack_10f;
  undefined4 uStack_10b;
  undefined3 uStack_107;
  undefined4 uStack_104;
  undefined8 uStack_100;
  ulong uStack_f8;
  ulong uStack_f0;
  ulong uStack_e8;
  ulong uStack_e0;
  ulong uStack_d8;
  ulong uStack_d0;
  ulong uStack_c8;
  ulong uStack_c0;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  ulong uStack_a8;
  ulong uStack_a0;
  ulong uStack_98;
  ulong uStack_90;
  byte bStack_88;
  undefined4 uStack_87;
  undefined4 uStack_83;
  undefined4 uStack_7f;
  undefined4 uStack_7b;
  undefined3 uStack_77;
  undefined4 uStack_74;
  undefined8 uStack_70;
  ulong uStack_68;
  ulong uStack_60;
  ulong uStack_50;
  ulong *puStack_48;
  ulong uStack_40;
  char cStack_31;
  
  uStack_250 = *(undefined8 *)(param_2 + 0x10);
  puStack_48 = param_1;
  (*(code *)&DAT_0ff44220)(auStack_1d8);
  func_0x0772cbe0(&bStack_118,auStack_1d8);
  if (bStack_118 == 0) {
    uStack_a8 = 0xfffffffffffffffe;
    cStack_31 = -1;
    uStack_158 = 2;
    uStack_40 = 0xffffffffffffffff;
    uVar9 = 2;
    uStack_50 = 0xffffffffffffffff;
    uStack_90 = 0xffffffffffffffff;
    uStack_a0 = 0xffffffffffffffff;
    uStack_98 = 0xffffffffffffffff;
    uStack_120 = 0xfffffffffffffffe;
    do {
      bVar2 = bStack_190;
      uVar12 = uStack_220;
      uVar13 = uStack_218;
      switch((undefined1)uStack_117) {
      case 0:
        if (uStack_50 != 0xffffffffffffffff) {
          bStack_88 = 0x39;
          uStack_87 = 0x6d3c;
          uStack_83 = 0x9000000;
          uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
          goto code_r0x06d99c21;
        }
        func_0x07731a70(&bStack_118,auStack_1d8);
        uStack_50 = CONCAT35((uint3)uStack_113,CONCAT41(uStack_117,bStack_118));
        uVar12 = CONCAT35((undefined3)uStack_10b,CONCAT41(uStack_10f,uStack_113._3_1_));
        if (uStack_50 != 0xffffffffffffffff) {
          uStack_240 = CONCAT44(uStack_104,CONCAT31(uStack_107,uStack_10b._3_1_));
          unaff_R12 = uVar12;
          uVar12 = uStack_220;
          uVar13 = uStack_218;
          uVar5 = uStack_158;
          break;
        }
        puStack_48[1] = uVar12;
        *puStack_48 = 2;
        goto code_r0x06d9985f;
      case 1:
        if (uStack_90 != 0xffffffffffffffff) {
          puVar8 = &UNK_006d465c;
code_r0x06d99bb8:
          bStack_88 = (byte)puVar8;
          uStack_87 = (undefined4)((ulong)puVar8 >> 8);
          uStack_83 = 0xa000000;
          uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
          goto code_r0x06d99c21;
        }
        func_0x07731a70(&bStack_118,auStack_1d8);
        uStack_90 = CONCAT35((uint3)uStack_113,CONCAT41(uStack_117,bStack_118));
        uVar6 = CONCAT35((undefined3)uStack_10b,CONCAT41(uStack_10f,uStack_113._3_1_));
        if (uStack_90 == 0xffffffffffffffff) {
          puStack_48[1] = uVar6;
          *puStack_48 = 2;
          uStack_40 = CONCAT71(uStack_40._1_7_,1);
          uStack_90 = 0xffffffffffffffff;
          goto code_r0x06d994cf;
        }
        uStack_238 = CONCAT44(uStack_104,CONCAT31(uStack_107,uStack_10b._3_1_));
        uVar12 = uStack_220;
        uVar13 = uStack_218;
        uVar5 = uStack_158;
        uStack_140 = uVar6;
        break;
      case 2:
        if (uStack_a0 != 0xffffffffffffffff) {
          bStack_88 = 0x66;
          uStack_87 = 0x6d46;
          uStack_83 = 0xb000000;
          uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
          goto code_r0x06d99c21;
        }
        func_0x077311e0(&bStack_118,auStack_1d8);
        uStack_a0 = CONCAT35((uint3)uStack_113,CONCAT41(uStack_117,bStack_118));
        uVar6 = CONCAT35((undefined3)uStack_10b,CONCAT41(uStack_10f,uStack_113._3_1_));
        if (uStack_a0 == 0xffffffffffffffff) {
          puStack_48[1] = uVar6;
          *puStack_48 = 2;
          uStack_40 = CONCAT71(uStack_40._1_7_,1);
          uStack_a0 = 0xffffffffffffffff;
          goto code_r0x06d994cf;
        }
        uStack_1e8 = CONCAT44(uStack_104,CONCAT31(uStack_107,uStack_10b._3_1_));
        uStack_168 = uStack_100;
        uStack_1f0 = uStack_f8;
        uStack_1e0 = uStack_f0;
        uStack_210 = uStack_e8;
        uStack_1f8 = uStack_e0;
        uStack_278 = uStack_d8;
        uStack_270 = uStack_d0;
        uStack_148 = uStack_c8;
        uStack_200 = uStack_c0;
        uStack_268 = uStack_b8;
        uStack_264 = uStack_b4;
        uStack_260 = uStack_b0;
        uStack_25c = uStack_ac;
        uVar12 = uStack_220;
        uVar13 = uStack_218;
        uStack_160 = uVar6;
        uVar5 = uStack_158;
        break;
      case 3:
        if (uStack_98 != 0xffffffffffffffff) {
          puVar8 = &UNK_006d4646;
          goto code_r0x06d99beb;
        }
        func_0x07731a70(&bStack_118,auStack_1d8);
        uStack_98 = CONCAT35((uint3)uStack_113,CONCAT41(uStack_117,bStack_118));
        uVar6 = CONCAT35((undefined3)uStack_10b,CONCAT41(uStack_10f,uStack_113._3_1_));
        if (uStack_98 == 0xffffffffffffffff) {
          puStack_48[1] = uVar6;
          *puStack_48 = 2;
          uStack_40 = CONCAT71(uStack_40._1_7_,1);
          uStack_98 = 0xffffffffffffffff;
          goto code_r0x06d994cf;
        }
        uStack_248 = CONCAT44(uStack_104,CONCAT31(uStack_107,uStack_10b._3_1_));
        uVar12 = uStack_220;
        uVar13 = uStack_218;
        uStack_170 = uVar6;
        uVar5 = uStack_158;
        break;
      case 4:
        if (cStack_31 != -1) {
          bStack_88 = 0x58;
          uStack_87 = 0x2636;
          uStack_83 = 0x8000000;
          uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
          goto code_r0x06d99c21;
        }
        bStack_190 = 0xff;
        if (bVar2 == 0xff) {
          uVar7 = phase_step_emit(&UNK_00222500,0x10);
          uStack_83._3_1_ = (undefined1)uVar7;
          uStack_7f = (undefined4)((ulong)uVar7 >> 8);
          uStack_7b._0_3_ = (undefined3)((ulong)uVar7 >> 0x28);
        }
        else {
          bStack_118 = bVar2;
          uStack_107 = uStack_17f;
          uStack_104 = uStack_17c;
          uStack_100 = CONCAT44(uStack_174,uStack_178);
          uStack_117 = uStack_18f;
          uStack_113 = uStack_18b;
          uStack_10f = uStack_187;
          uStack_10b = uStack_183;
          func_0x04fc2b60(&bStack_88,&bStack_118);
          if (bStack_88 != 1) {
            cStack_31 = (char)uStack_87;
            uVar12 = uStack_220;
            uVar13 = uStack_218;
            uVar5 = uStack_158;
            break;
          }
        }
        uVar6 = CONCAT35((undefined3)uStack_7b,CONCAT41(uStack_7f,uStack_83._3_1_));
        goto code_r0x06d99b44;
      case 5:
        if (uStack_a8 != 0xfffffffffffffffe) {
          puVar8 = &UNK_006d379c;
code_r0x06d99beb:
          bStack_88 = (byte)puVar8;
          uStack_87 = (undefined4)((ulong)puVar8 >> 8);
          uStack_83 = 0x6000000;
          uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
          goto code_r0x06d99c21;
        }
        bStack_190 = 0xff;
        if (bVar2 == 0xff) {
          uVar6 = phase_step_emit(&UNK_00222500,0x10);
        }
        else {
          bStack_118 = bVar2;
          uStack_107 = uStack_17f;
          uStack_104 = uStack_17c;
          uStack_100 = CONCAT44(uStack_174,uStack_178);
          uStack_117 = uStack_18f;
          uStack_113 = uStack_18b;
          uStack_10f = uStack_187;
          uStack_10b = uStack_183;
          func_0x0690bf10(&bStack_88,&bStack_118);
          uStack_a8 = CONCAT35((uint3)uStack_83,CONCAT41(uStack_87,bStack_88));
          uVar6 = CONCAT35((undefined3)uStack_7b,CONCAT41(uStack_7f,uStack_83._3_1_));
          if (uStack_a8 != 0xfffffffffffffffe) {
            uStack_228 = CONCAT44(uStack_74,CONCAT31(uStack_77,uStack_7b._3_1_));
            uVar12 = uStack_220;
            uVar13 = uStack_218;
            uVar5 = uStack_158;
            uStack_150 = uVar6;
            break;
          }
        }
        puStack_48[1] = uVar6;
        *puStack_48 = 2;
        uStack_40 = CONCAT71(uStack_40._1_7_,1);
        uStack_a8 = 0xfffffffffffffffe;
        goto code_r0x06d994cf;
      case 6:
        if (uVar9 != 2) {
          puVar8 = &UNK_006d4725;
          goto code_r0x06d99bb8;
        }
        uVar9 = (ulong)bStack_190;
        bStack_190 = 0xff;
        uVar5 = uStack_158;
        if (bVar2 == 0) break;
        if (bVar2 == 0xff) {
code_r0x06d99a83:
          bStack_190 = 0xff;
          uVar6 = phase_step_emit(&UNK_00222500,0x10);
        }
        else {
          bStack_118 = bVar2;
          uStack_107 = uStack_17f;
          uStack_104 = uStack_17c;
          uStack_100 = CONCAT44(uStack_174,uStack_178);
          uStack_117 = uStack_18f;
          uStack_113 = uStack_18b;
          uStack_10f = uStack_187;
          uStack_10b = uStack_183;
          auVar16 = func_0x073ec410(&bStack_118);
          uVar6 = auVar16._8_8_;
          uVar9 = auVar16._0_8_ + 1;
          uVar12 = uStack_220;
          uVar13 = uVar6;
          uVar5 = uStack_158;
          if (uVar9 != 2) break;
        }
code_r0x06d99a97:
        puStack_48[1] = uVar6;
        *puStack_48 = 2;
        goto code_r0x06d99b53;
      case 7:
        if (uStack_158 != 2) {
          bStack_88 = 0xf6;
          uStack_87 = 0x6d48;
          uStack_83 = 0x12000000;
          uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
          goto code_r0x06d99c21;
        }
        uVar5 = (ulong)bStack_190;
        bStack_190 = 0xff;
        if (bVar2 != 0) {
          if (bVar2 == 0xff) goto code_r0x06d99a83;
          bStack_118 = bVar2;
          uStack_107 = uStack_17f;
          uStack_104 = uStack_17c;
          uStack_100 = CONCAT44(uStack_174,uStack_178);
          uStack_117 = uStack_18f;
          uStack_113 = uStack_18b;
          uStack_10f = uStack_187;
          uStack_10b = uStack_183;
          auVar16 = func_0x073ec410(&bStack_118);
          uVar6 = auVar16._8_8_;
          uVar5 = auVar16._0_8_ + 1;
          uVar12 = uVar6;
          uVar13 = uStack_218;
          if (uVar5 == 2) goto code_r0x06d99a97;
        }
        break;
      case 8:
        if (uStack_40 != 0xffffffffffffffff) {
          puVar8 = &UNK_006d4720;
          goto code_r0x06d99c15;
        }
        bStack_190 = 0xff;
        if (bVar2 == 0xff) {
          uVar6 = phase_step_emit(&UNK_00222500,0x10);
        }
        else {
          bStack_88 = bVar2;
          uStack_77 = uStack_17f;
          uStack_74 = uStack_17c;
          uStack_70 = CONCAT44(uStack_174,uStack_178);
          uStack_87 = uStack_18f;
          uStack_83 = uStack_18b;
          uStack_7f = uStack_187;
          uStack_7b = uStack_183;
          func_0x0690cd00(&bStack_118,&bStack_88);
          uStack_40 = CONCAT35((uint3)uStack_113,CONCAT41(uStack_117,bStack_118));
          uVar6 = CONCAT35((undefined3)uStack_10b,CONCAT41(uStack_10f,uStack_113._3_1_));
          if (uStack_40 != 0xffffffffffffffff) {
            uStack_2b8 = CONCAT31(uStack_107,uStack_10b._3_1_);
            uStack_298 = uStack_e8;
            uStack_290 = uStack_e0;
            uStack_2a8 = uStack_f8;
            uStack_2a0 = uStack_f0;
            uStack_2b4 = uStack_104;
            uStack_2b0 = (undefined4)uStack_100;
            uStack_2ac = uStack_100._4_4_;
            uStack_230 = uVar6;
            uVar12 = uStack_220;
            uVar13 = uStack_218;
            uVar5 = uStack_158;
            break;
          }
        }
        goto code_r0x06d99b44;
      case 9:
        if (uStack_120 == 0xfffffffffffffffe) {
          bStack_190 = 0xff;
          if (bVar2 == 0xff) {
            uVar6 = phase_step_emit(&UNK_00222500,0x10);
          }
          else {
            bStack_118 = bVar2;
            uStack_107 = uStack_17f;
            uStack_104 = uStack_17c;
            uStack_100 = CONCAT44(uStack_174,uStack_178);
            uStack_117 = uStack_18f;
            uStack_113 = uStack_18b;
            uStack_10f = uStack_187;
            uStack_10b = uStack_183;
            func_0x0690cc20(&bStack_88,&bStack_118);
            uStack_120 = CONCAT35((uint3)uStack_83,CONCAT41(uStack_87,bStack_88));
            uVar6 = CONCAT35((undefined3)uStack_7b,CONCAT41(uStack_7f,uStack_83._3_1_));
            if (uStack_120 != 0xfffffffffffffffe) {
              uStack_288 = CONCAT31(uStack_77,uStack_7b._3_1_);
              uStack_284 = uStack_74;
              uStack_280 = (undefined4)uStack_70;
              uStack_27c = uStack_70._4_4_;
              uVar12 = uStack_220;
              uVar13 = uStack_218;
              uStack_208 = uVar6;
              uVar5 = uStack_158;
              break;
            }
          }
          puStack_48[1] = uVar6;
          *puStack_48 = 2;
          bVar2 = 1;
          bVar14 = true;
          bVar15 = true;
          bVar4 = 1;
          goto joined_r0x06d99aec;
        }
        puVar8 = &UNK_006d2e64;
code_r0x06d99c15:
        bStack_88 = (byte)puVar8;
        uStack_87 = (undefined4)((ulong)puVar8 >> 8);
        uStack_83 = 0x5000000;
        uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
code_r0x06d99c21:
        uStack_7f = 0;
        bStack_118 = (byte)&bStack_88;
        uStack_117 = (undefined4)((ulong)&bStack_88 >> 8);
        uStack_113._0_3_ = (uint3)((ulong)&bStack_88 >> 0x28);
        uStack_113 = (uint)(uint3)uStack_113;
        uStack_10f = 0x5b4ad;
        uStack_10b = (uint)uStack_10b._3_1_ << 0x18;
        uVar6 = func_0x06a8f9e0(&UNK_0029e67a,&bStack_118);
code_r0x06d99b44:
        puStack_48[1] = uVar6;
        *puStack_48 = 2;
code_r0x06d99b53:
        uStack_40 = CONCAT71(uStack_40._1_7_,1);
        goto code_r0x06d994cf;
      case 10:
        uVar6 = func_0x07731140(auStack_1d8);
        uVar12 = uStack_220;
        uVar13 = uStack_218;
        uVar5 = uStack_158;
        if (uVar6 != 0) goto code_r0x06d99b44;
        break;
      default:
        if (uStack_50 == 0xffffffffffffffff) {
          bStack_88 = 0x39;
          uStack_87 = 0x6d3c;
          uStack_83 = 0x9000000;
          uStack_7f = 0;
          uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
          bStack_118 = (byte)&bStack_88;
          uStack_117 = (undefined4)((ulong)&bStack_88 >> 8);
          uStack_113._0_3_ = (uint3)((ulong)&bStack_88 >> 0x28);
          uStack_113 = (uint)(uint3)uStack_113;
          uStack_10f = 0x5b4ad;
          uStack_10b = (uint)uStack_10b._3_1_ << 0x18;
          uVar9 = func_0x06a8f9e0(&UNK_002950fd,&bStack_118);
          puStack_48[1] = uVar9;
          *puStack_48 = 2;
code_r0x06d9985f:
          uStack_40 = CONCAT71(uStack_40._1_7_,1);
          uStack_50 = 0xffffffffffffffff;
          goto code_r0x06d994cf;
        }
        bVar14 = uStack_90 == 0xffffffffffffffff;
        if (bVar14) {
          bStack_88 = 0x5c;
          uStack_87 = 0x6d46;
          uStack_83 = 0xa000000;
          uStack_7f = 0;
          uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
          bStack_118 = (byte)&bStack_88;
          uStack_117 = (undefined4)((ulong)&bStack_88 >> 8);
          uStack_113._0_3_ = (uint3)((ulong)&bStack_88 >> 0x28);
          uStack_113 = (uint)(uint3)uStack_113;
          uStack_10f = 0x5b4ad;
          uStack_10b = (uint)uStack_10b._3_1_ << 0x18;
          uVar9 = func_0x06a8f9e0(&UNK_002950fd,&bStack_118);
          puStack_48[1] = uVar9;
          *puStack_48 = 2;
          uStack_40 = CONCAT71(uStack_40._1_7_,1);
          bVar15 = true;
        }
        else {
          bVar15 = uStack_a0 == 0xffffffffffffffff;
          if (bVar15) {
            uStack_138 = &UNK_006d4666;
            uStack_130 = 0xb;
            bStack_88 = (byte)&uStack_138;
            uStack_87 = (undefined4)((ulong)&uStack_138 >> 8);
            uStack_83._0_3_ = (uint3)((ulong)&uStack_138 >> 0x28);
            uStack_83 = (uint)(uint3)uStack_83;
            uStack_7f = 0x5b4ad;
            uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
            uVar9 = func_0x06a8f9e0(&UNK_002950fd,&bStack_88);
            puStack_48[1] = uVar9;
            *puStack_48 = 2;
            uStack_40 = CONCAT71(uStack_40._1_7_,1);
          }
          else {
            bStack_118 = (byte)uStack_a0;
            uStack_117 = (undefined4)(uStack_a0 >> 8);
            uStack_113._0_3_ = (uint3)(uStack_a0 >> 0x28);
            uStack_113._3_1_ = (undefined1)uStack_160;
            uStack_10f = (undefined4)(uStack_160 >> 8);
            uStack_10b._0_3_ = (undefined3)(uStack_160 >> 0x28);
            uStack_10b._3_1_ = (byte)uStack_1e8;
            uStack_107 = (undefined3)(uStack_1e8 >> 8);
            uStack_104 = (undefined4)(uStack_1e8 >> 0x20);
            uStack_100 = uStack_168;
            uStack_f8 = uStack_1f0;
            uStack_f0 = uStack_1e0;
            uStack_e8 = uStack_210;
            uStack_e0 = uStack_1f8;
            uStack_d8 = uStack_278;
            uStack_d0 = uStack_270;
            uStack_c8 = uStack_148;
            uStack_c0 = uStack_200;
            uStack_b8 = uStack_268;
            uStack_b4 = uStack_264;
            uStack_b0 = uStack_260;
            uStack_ac = uStack_25c;
            if (uStack_98 == 0xffffffffffffffff) {
              uStack_40 = CONCAT71(uStack_40._1_7_,1);
              uStack_138 = &UNK_006d4646;
              uStack_130 = 6;
              bStack_88 = (byte)&uStack_138;
              uStack_87 = (undefined4)((ulong)&uStack_138 >> 8);
              uStack_83._0_3_ = (uint3)((ulong)&uStack_138 >> 0x28);
              uStack_83 = (uint)(uint3)uStack_83;
              uStack_7f = 0x5b4ad;
              uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
              uVar9 = func_0x06a8f9e0(&UNK_002950fd,&bStack_88);
              puStack_48[1] = uVar9;
              *puStack_48 = 2;
            }
            else {
              if (cStack_31 != -1) {
                uVar12 = uStack_a8;
                if (uStack_a8 == 0xfffffffffffffffe) {
                  uVar12 = 0xffffffffffffffff;
                }
                if (uVar9 == 2) {
                  uVar9 = 0;
                }
                uVar13 = uStack_158;
                if (uStack_158 == 2) {
                  uVar13 = 0;
                }
                if (uStack_40 == 0xffffffffffffffff) {
                  uStack_40 = 2;
                }
                else {
                  uStack_68 = uStack_298;
                  uStack_60 = uStack_290;
                  uStack_7b._3_1_ = (byte)uStack_2a8;
                  uStack_77 = (undefined3)(uStack_2a8 >> 8);
                  uStack_74 = (undefined4)(uStack_2a8 >> 0x20);
                  uStack_70 = uStack_2a0;
                  bStack_88 = (byte)uStack_2b8;
                  uStack_87 = (undefined4)(CONCAT44(uStack_2b4,uStack_2b8) >> 8);
                  uStack_83._3_1_ = (undefined1)uStack_2b0;
                  uStack_83 = CONCAT13(uStack_83._3_1_,(int3)((uint)uStack_2b4 >> 8));
                  uStack_7f = (undefined4)(CONCAT44(uStack_2ac,uStack_2b0) >> 8);
                  uStack_7b._0_3_ = (undefined3)((uint)uStack_2ac >> 8);
                }
                uVar6 = 0xffffffffffffffff;
                if (uStack_120 != 0xfffffffffffffffe) {
                  uStack_138 = (undefined *)CONCAT44(uStack_284,uStack_288);
                  uStack_130 = CONCAT44(uStack_27c,uStack_280);
                  uVar6 = uStack_120;
                }
                puStack_48[0xc] = uStack_50;
                puStack_48[0xd] = unaff_R12;
                puStack_48[0xe] = uStack_240;
                puStack_48[0xf] = uStack_90;
                puStack_48[0x10] = uStack_140;
                puStack_48[0x11] = uStack_238;
                puStack_48[0x12] = uStack_a0;
                puStack_48[0x13] = uStack_160;
                puStack_48[0x14] = uStack_1e8;
                puStack_48[0x15] = uStack_168;
                puStack_48[0x16] = uStack_1f0;
                puStack_48[0x17] = uStack_1e0;
                puStack_48[0x18] = uStack_210;
                puStack_48[0x19] = uStack_1f8;
                puStack_48[0x1a] = uStack_278;
                puStack_48[0x1b] = uStack_270;
                puStack_48[0x1c] = uStack_148;
                puStack_48[0x1d] = uStack_200;
                puStack_48[0x1e] = CONCAT44(uStack_264,uStack_268);
                puStack_48[0x1f] = CONCAT44(uStack_25c,uStack_260);
                puStack_48[0x20] = uStack_98;
                puStack_48[0x21] = uStack_170;
                puStack_48[0x22] = uStack_248;
                *puStack_48 = uVar9;
                puStack_48[1] = uStack_218;
                puStack_48[2] = uVar13;
                puStack_48[3] = uStack_220;
                puStack_48[4] = uStack_40;
                puStack_48[5] = uStack_230;
                puStack_48[10] = uStack_68;
                puStack_48[0xb] = uStack_60;
                puStack_48[8] = CONCAT44(uStack_74,CONCAT31(uStack_77,uStack_7b._3_1_));
                puStack_48[9] = uStack_70;
                puStack_48[6] = CONCAT35((uint3)uStack_83,CONCAT41(uStack_87,bStack_88));
                puStack_48[7] = CONCAT35((undefined3)uStack_7b,CONCAT41(uStack_7f,uStack_83._3_1_));
                puStack_48[0x23] = uVar12;
                puStack_48[0x24] = uStack_150;
                puStack_48[0x25] = uStack_228;
                puStack_48[0x26] = uVar6;
                puStack_48[0x27] = uStack_208;
                *(int *)(puStack_48 + 0x28) = (int)uStack_138;
                *(int *)((long)puStack_48 + 0x144) = uStack_138._4_4_;
                *(int *)(puStack_48 + 0x29) = (int)uStack_130;
                *(int *)((long)puStack_48 + 0x14c) = uStack_130._4_4_;
                *(char *)(puStack_48 + 0x2a) = cStack_31;
                iVar1 = (int)*puStack_48;
                puVar3 = puStack_48;
                goto joined_r0x06d99a78;
              }
              uStack_40 = (ulong)uStack_40._1_7_ << 8;
              uStack_138 = &UNK_00263658;
              uStack_130 = 8;
              bStack_88 = (byte)&uStack_138;
              uStack_87 = (undefined4)((ulong)&uStack_138 >> 8);
              uStack_83._0_3_ = (uint3)((ulong)&uStack_138 >> 0x28);
              uStack_83 = (uint)(uint3)uStack_83;
              uStack_7f = 0x5b4ad;
              uStack_7b = (uint)uStack_7b._3_1_ << 0x18;
              uVar9 = func_0x06a8f9e0(&UNK_002950fd,&bStack_88);
              puStack_48[1] = uVar9;
              *puStack_48 = 2;
              if (uStack_98 != 0) {
                (*(code *)&DAT_04732840)(uStack_170,uStack_98,1);
              }
            }
            func_0x06cf96b0(&bStack_118);
          }
          if (uStack_90 != 0) {
            (*(code *)&DAT_04732840)(uStack_140,uStack_90,1);
          }
        }
        if (uStack_50 == 0) {
          uStack_50 = 0;
        }
        else {
          (*(code *)&DAT_04732840)(unaff_R12,uStack_50,1);
        }
        bVar2 = 0;
        goto joined_r0x06d99eb6;
      }
      uStack_158 = uVar5;
      uStack_218 = uVar13;
      uStack_220 = uVar12;
      func_0x0772cbe0(&bStack_118,auStack_1d8);
    } while (bStack_118 == 0);
  }
  else {
    uStack_98 = 0xffffffffffffffff;
    uStack_120 = 0xfffffffffffffffe;
    uStack_a8 = 0xfffffffffffffffe;
    uStack_a0 = 0xffffffffffffffff;
    uStack_90 = 0xffffffffffffffff;
    uStack_50 = 0xffffffffffffffff;
    unaff_R12 = unaff_R13;
  }
  puStack_48[1] = CONCAT35((undefined3)uStack_10b,CONCAT41(uStack_10f,uStack_113._3_1_));
  *puStack_48 = 2;
  uStack_40 = CONCAT71(uStack_40._1_7_,1);
code_r0x06d994cf:
  bVar15 = true;
  bVar14 = true;
  bVar2 = 1;
joined_r0x06d99eb6:
  if (uStack_120 - 1 < 0xfffffffffffffffd) {
    (*(code *)&DAT_04732840)(uStack_208,uStack_120,1);
  }
  bVar4 = (byte)uStack_40;
joined_r0x06d99aec:
  if (uStack_a8 - 1 < 0xfffffffffffffffd) {
    (*(code *)&DAT_04732840)(uStack_150,uStack_a8,1);
  }
  if ((0 < (long)uStack_98 & bVar4) != 0) {
    (*(code *)&DAT_04732840)(uStack_170,uStack_98,1);
  }
  puVar3 = puStack_48;
  if ((bool)(uStack_a0 != 0xffffffffffffffff & bVar15)) {
    if (uStack_a0 != 0) {
      (*(code *)&DAT_04732840)(uStack_160,uStack_a0,1);
    }
    if (uStack_168 != 0) {
      (*(code *)&DAT_04732840)(uStack_1f0,uStack_168,1);
    }
    if (uStack_210 != 0) {
      (*(code *)&DAT_04732840)(uStack_1f8,uStack_210,1);
    }
    if (uStack_148 != 0) {
      (*(code *)&DAT_04732840)(uStack_200,uStack_148,1);
    }
  }
  if ((bool)(0 < (long)uStack_90 & bVar14)) {
    (*(code *)&DAT_04732840)(uStack_140,uStack_90,1);
  }
  if ((bool)(0 < (long)uStack_50 & bVar2)) {
    (*(code *)&DAT_04732840)(unaff_R12,uStack_50,1);
  }
  iVar1 = (int)*puVar3;
joined_r0x06d99a78:
  uStack_18b._3_1_ = (undefined1)(uStack_18b >> 0x18);
  if ((iVar1 != 2) && ((*(code *)&DAT_120cba68)(auStack_410,puVar3,0x158), lStack_198 != 0)) {
    uVar9 = func_0x06b1d460(uStack_250,&UNK_12138720,&UNK_12138280);
    puVar3[1] = uVar9;
    *puVar3 = 2;
    func_0x06d04460(auStack_410);
  }
  func_0x078b5420(auStack_1d8);
  if (bStack_190 < 3) {
    if (bStack_190 < 3) {
      return puVar3;
    }
code_r0x06d99669:
    func_0x07813660((long)&uStack_18b + 3);
  }
  else {
    if (bStack_190 == 3) {
      lVar11 = CONCAT35((undefined3)uStack_183,CONCAT41(uStack_187,uStack_18b._3_1_));
      if (lVar11 == 0) {
        return puVar3;
      }
      uVar7 = CONCAT44(uStack_17c,CONCAT31(uStack_17f,uStack_183._3_1_));
      uVar10 = 1;
    }
    else {
      if (bStack_190 != 4) {
        if (bStack_190 == 0xff) {
          return puVar3;
        }
        goto code_r0x06d99669;
      }
      func_0x07c89080((long)&uStack_18b + 3);
      lVar11 = CONCAT35((undefined3)uStack_183,CONCAT41(uStack_187,uStack_18b._3_1_));
      if (lVar11 == 0) {
        return puVar3;
      }
      uVar7 = CONCAT44(uStack_17c,CONCAT31(uStack_17f,uStack_183._3_1_));
      lVar11 = lVar11 << 5;
      uVar10 = 8;
    }
    (*(code *)&DAT_04732840)(uVar7,lVar11,uVar10);
  }
  return puVar3;
}

