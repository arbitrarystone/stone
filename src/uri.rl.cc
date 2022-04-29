
#line 1 "/home/lighthouse/workspace/stone/src/uri.rl"
#include "uri.hpp"
#include <sstream>

namespace stone {
	
	static const int uri_parser_start = 451;
	static const int uri_parser_first_final = 451;
	static const int uri_parser_error = 0;
	
	static const int uri_parser_en_main = 451;
	
	static const char _uri_parser_nfa_targs[] = {
		0, 0
	};
	
	static const char _uri_parser_nfa_offsets[] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0
	};
	
	static const char _uri_parser_nfa_push_actions[] = {
		0, 0
	};
	
	static const char _uri_parser_nfa_pop_trans[] = {
		0, 0
	};
	
	
	#line 132 "/home/lighthouse/workspace/stone/src/uri.rl"
	
	
	Uri::ptr Uri::Create(const std::string& uristr) {
		Uri::ptr uri(new Uri);
		int cs = 0;
		const char* mark = 0;
		
		{
			cs = (int)uri_parser_start;
		}
		
		#line 139 "/home/lighthouse/workspace/stone/src/uri.rl"
		
		const char *p = uristr.c_str();
		const char *pe = p + uristr.size();
		const char* eof = pe;
		
		{
			if ( p == pe )
			goto _test_eof;
			switch ( cs )
			{
				case 451:
				goto st_case_451;
				case 452:
				goto st_case_452;
				case 0:
				goto st_case_0;
				case 453:
				goto st_case_453;
				case 454:
				goto st_case_454;
				case 1:
				goto st_case_1;
				case 2:
				goto st_case_2;
				case 3:
				goto st_case_3;
				case 4:
				goto st_case_4;
				case 455:
				goto st_case_455;
				case 5:
				goto st_case_5;
				case 6:
				goto st_case_6;
				case 456:
				goto st_case_456;
				case 457:
				goto st_case_457;
				case 7:
				goto st_case_7;
				case 8:
				goto st_case_8;
				case 458:
				goto st_case_458;
				case 459:
				goto st_case_459;
				case 9:
				goto st_case_9;
				case 10:
				goto st_case_10;
				case 11:
				goto st_case_11;
				case 12:
				goto st_case_12;
				case 13:
				goto st_case_13;
				case 14:
				goto st_case_14;
				case 15:
				goto st_case_15;
				case 16:
				goto st_case_16;
				case 17:
				goto st_case_17;
				case 18:
				goto st_case_18;
				case 19:
				goto st_case_19;
				case 20:
				goto st_case_20;
				case 21:
				goto st_case_21;
				case 22:
				goto st_case_22;
				case 460:
				goto st_case_460;
				case 461:
				goto st_case_461;
				case 462:
				goto st_case_462;
				case 463:
				goto st_case_463;
				case 464:
				goto st_case_464;
				case 465:
				goto st_case_465;
				case 466:
				goto st_case_466;
				case 23:
				goto st_case_23;
				case 24:
				goto st_case_24;
				case 25:
				goto st_case_25;
				case 26:
				goto st_case_26;
				case 27:
				goto st_case_27;
				case 28:
				goto st_case_28;
				case 29:
				goto st_case_29;
				case 30:
				goto st_case_30;
				case 467:
				goto st_case_467;
				case 31:
				goto st_case_31;
				case 32:
				goto st_case_32;
				case 468:
				goto st_case_468;
				case 33:
				goto st_case_33;
				case 34:
				goto st_case_34;
				case 35:
				goto st_case_35;
				case 469:
				goto st_case_469;
				case 470:
				goto st_case_470;
				case 36:
				goto st_case_36;
				case 37:
				goto st_case_37;
				case 471:
				goto st_case_471;
				case 472:
				goto st_case_472;
				case 473:
				goto st_case_473;
				case 474:
				goto st_case_474;
				case 475:
				goto st_case_475;
				case 476:
				goto st_case_476;
				case 477:
				goto st_case_477;
				case 478:
				goto st_case_478;
				case 479:
				goto st_case_479;
				case 480:
				goto st_case_480;
				case 481:
				goto st_case_481;
				case 482:
				goto st_case_482;
				case 483:
				goto st_case_483;
				case 484:
				goto st_case_484;
				case 485:
				goto st_case_485;
				case 486:
				goto st_case_486;
				case 487:
				goto st_case_487;
				case 488:
				goto st_case_488;
				case 38:
				goto st_case_38;
				case 39:
				goto st_case_39;
				case 40:
				goto st_case_40;
				case 41:
				goto st_case_41;
				case 42:
				goto st_case_42;
				case 43:
				goto st_case_43;
				case 44:
				goto st_case_44;
				case 45:
				goto st_case_45;
				case 46:
				goto st_case_46;
				case 47:
				goto st_case_47;
				case 48:
				goto st_case_48;
				case 49:
				goto st_case_49;
				case 50:
				goto st_case_50;
				case 51:
				goto st_case_51;
				case 52:
				goto st_case_52;
				case 53:
				goto st_case_53;
				case 54:
				goto st_case_54;
				case 55:
				goto st_case_55;
				case 56:
				goto st_case_56;
				case 57:
				goto st_case_57;
				case 58:
				goto st_case_58;
				case 59:
				goto st_case_59;
				case 60:
				goto st_case_60;
				case 61:
				goto st_case_61;
				case 62:
				goto st_case_62;
				case 63:
				goto st_case_63;
				case 64:
				goto st_case_64;
				case 65:
				goto st_case_65;
				case 66:
				goto st_case_66;
				case 67:
				goto st_case_67;
				case 68:
				goto st_case_68;
				case 69:
				goto st_case_69;
				case 70:
				goto st_case_70;
				case 71:
				goto st_case_71;
				case 72:
				goto st_case_72;
				case 73:
				goto st_case_73;
				case 74:
				goto st_case_74;
				case 75:
				goto st_case_75;
				case 76:
				goto st_case_76;
				case 77:
				goto st_case_77;
				case 78:
				goto st_case_78;
				case 79:
				goto st_case_79;
				case 80:
				goto st_case_80;
				case 81:
				goto st_case_81;
				case 82:
				goto st_case_82;
				case 83:
				goto st_case_83;
				case 84:
				goto st_case_84;
				case 85:
				goto st_case_85;
				case 86:
				goto st_case_86;
				case 87:
				goto st_case_87;
				case 88:
				goto st_case_88;
				case 89:
				goto st_case_89;
				case 90:
				goto st_case_90;
				case 91:
				goto st_case_91;
				case 92:
				goto st_case_92;
				case 93:
				goto st_case_93;
				case 94:
				goto st_case_94;
				case 95:
				goto st_case_95;
				case 96:
				goto st_case_96;
				case 97:
				goto st_case_97;
				case 98:
				goto st_case_98;
				case 99:
				goto st_case_99;
				case 100:
				goto st_case_100;
				case 101:
				goto st_case_101;
				case 102:
				goto st_case_102;
				case 103:
				goto st_case_103;
				case 104:
				goto st_case_104;
				case 105:
				goto st_case_105;
				case 106:
				goto st_case_106;
				case 107:
				goto st_case_107;
				case 108:
				goto st_case_108;
				case 109:
				goto st_case_109;
				case 110:
				goto st_case_110;
				case 111:
				goto st_case_111;
				case 112:
				goto st_case_112;
				case 113:
				goto st_case_113;
				case 114:
				goto st_case_114;
				case 115:
				goto st_case_115;
				case 116:
				goto st_case_116;
				case 117:
				goto st_case_117;
				case 118:
				goto st_case_118;
				case 119:
				goto st_case_119;
				case 120:
				goto st_case_120;
				case 121:
				goto st_case_121;
				case 122:
				goto st_case_122;
				case 123:
				goto st_case_123;
				case 124:
				goto st_case_124;
				case 125:
				goto st_case_125;
				case 126:
				goto st_case_126;
				case 127:
				goto st_case_127;
				case 128:
				goto st_case_128;
				case 129:
				goto st_case_129;
				case 130:
				goto st_case_130;
				case 131:
				goto st_case_131;
				case 132:
				goto st_case_132;
				case 133:
				goto st_case_133;
				case 134:
				goto st_case_134;
				case 135:
				goto st_case_135;
				case 136:
				goto st_case_136;
				case 137:
				goto st_case_137;
				case 138:
				goto st_case_138;
				case 139:
				goto st_case_139;
				case 140:
				goto st_case_140;
				case 141:
				goto st_case_141;
				case 142:
				goto st_case_142;
				case 143:
				goto st_case_143;
				case 144:
				goto st_case_144;
				case 145:
				goto st_case_145;
				case 146:
				goto st_case_146;
				case 147:
				goto st_case_147;
				case 148:
				goto st_case_148;
				case 149:
				goto st_case_149;
				case 150:
				goto st_case_150;
				case 151:
				goto st_case_151;
				case 152:
				goto st_case_152;
				case 153:
				goto st_case_153;
				case 154:
				goto st_case_154;
				case 155:
				goto st_case_155;
				case 156:
				goto st_case_156;
				case 157:
				goto st_case_157;
				case 158:
				goto st_case_158;
				case 159:
				goto st_case_159;
				case 160:
				goto st_case_160;
				case 161:
				goto st_case_161;
				case 162:
				goto st_case_162;
				case 163:
				goto st_case_163;
				case 164:
				goto st_case_164;
				case 165:
				goto st_case_165;
				case 166:
				goto st_case_166;
				case 167:
				goto st_case_167;
				case 168:
				goto st_case_168;
				case 169:
				goto st_case_169;
				case 170:
				goto st_case_170;
				case 171:
				goto st_case_171;
				case 172:
				goto st_case_172;
				case 173:
				goto st_case_173;
				case 174:
				goto st_case_174;
				case 175:
				goto st_case_175;
				case 176:
				goto st_case_176;
				case 177:
				goto st_case_177;
				case 178:
				goto st_case_178;
				case 179:
				goto st_case_179;
				case 180:
				goto st_case_180;
				case 181:
				goto st_case_181;
				case 182:
				goto st_case_182;
				case 183:
				goto st_case_183;
				case 184:
				goto st_case_184;
				case 185:
				goto st_case_185;
				case 186:
				goto st_case_186;
				case 187:
				goto st_case_187;
				case 188:
				goto st_case_188;
				case 189:
				goto st_case_189;
				case 190:
				goto st_case_190;
				case 191:
				goto st_case_191;
				case 192:
				goto st_case_192;
				case 193:
				goto st_case_193;
				case 194:
				goto st_case_194;
				case 195:
				goto st_case_195;
				case 196:
				goto st_case_196;
				case 197:
				goto st_case_197;
				case 198:
				goto st_case_198;
				case 199:
				goto st_case_199;
				case 200:
				goto st_case_200;
				case 201:
				goto st_case_201;
				case 202:
				goto st_case_202;
				case 203:
				goto st_case_203;
				case 204:
				goto st_case_204;
				case 205:
				goto st_case_205;
				case 206:
				goto st_case_206;
				case 207:
				goto st_case_207;
				case 208:
				goto st_case_208;
				case 209:
				goto st_case_209;
				case 210:
				goto st_case_210;
				case 211:
				goto st_case_211;
				case 212:
				goto st_case_212;
				case 213:
				goto st_case_213;
				case 214:
				goto st_case_214;
				case 215:
				goto st_case_215;
				case 216:
				goto st_case_216;
				case 217:
				goto st_case_217;
				case 218:
				goto st_case_218;
				case 219:
				goto st_case_219;
				case 220:
				goto st_case_220;
				case 221:
				goto st_case_221;
				case 222:
				goto st_case_222;
				case 223:
				goto st_case_223;
				case 224:
				goto st_case_224;
				case 225:
				goto st_case_225;
				case 226:
				goto st_case_226;
				case 227:
				goto st_case_227;
				case 228:
				goto st_case_228;
				case 489:
				goto st_case_489;
				case 490:
				goto st_case_490;
				case 491:
				goto st_case_491;
				case 492:
				goto st_case_492;
				case 493:
				goto st_case_493;
				case 494:
				goto st_case_494;
				case 495:
				goto st_case_495;
				case 496:
				goto st_case_496;
				case 497:
				goto st_case_497;
				case 498:
				goto st_case_498;
				case 499:
				goto st_case_499;
				case 500:
				goto st_case_500;
				case 501:
				goto st_case_501;
				case 502:
				goto st_case_502;
				case 503:
				goto st_case_503;
				case 504:
				goto st_case_504;
				case 505:
				goto st_case_505;
				case 506:
				goto st_case_506;
				case 507:
				goto st_case_507;
				case 508:
				goto st_case_508;
				case 509:
				goto st_case_509;
				case 510:
				goto st_case_510;
				case 511:
				goto st_case_511;
				case 229:
				goto st_case_229;
				case 230:
				goto st_case_230;
				case 231:
				goto st_case_231;
				case 232:
				goto st_case_232;
				case 233:
				goto st_case_233;
				case 234:
				goto st_case_234;
				case 235:
				goto st_case_235;
				case 236:
				goto st_case_236;
				case 237:
				goto st_case_237;
				case 238:
				goto st_case_238;
				case 239:
				goto st_case_239;
				case 240:
				goto st_case_240;
				case 241:
				goto st_case_241;
				case 242:
				goto st_case_242;
				case 512:
				goto st_case_512;
				case 513:
				goto st_case_513;
				case 243:
				goto st_case_243;
				case 244:
				goto st_case_244;
				case 514:
				goto st_case_514;
				case 515:
				goto st_case_515;
				case 516:
				goto st_case_516;
				case 517:
				goto st_case_517;
				case 518:
				goto st_case_518;
				case 519:
				goto st_case_519;
				case 245:
				goto st_case_245;
				case 246:
				goto st_case_246;
				case 247:
				goto st_case_247;
				case 248:
				goto st_case_248;
				case 249:
				goto st_case_249;
				case 250:
				goto st_case_250;
				case 251:
				goto st_case_251;
				case 252:
				goto st_case_252;
				case 520:
				goto st_case_520;
				case 253:
				goto st_case_253;
				case 254:
				goto st_case_254;
				case 521:
				goto st_case_521;
				case 255:
				goto st_case_255;
				case 256:
				goto st_case_256;
				case 257:
				goto st_case_257;
				case 522:
				goto st_case_522;
				case 523:
				goto st_case_523;
				case 258:
				goto st_case_258;
				case 259:
				goto st_case_259;
				case 524:
				goto st_case_524;
				case 525:
				goto st_case_525;
				case 526:
				goto st_case_526;
				case 527:
				goto st_case_527;
				case 528:
				goto st_case_528;
				case 529:
				goto st_case_529;
				case 530:
				goto st_case_530;
				case 531:
				goto st_case_531;
				case 532:
				goto st_case_532;
				case 533:
				goto st_case_533;
				case 534:
				goto st_case_534;
				case 535:
				goto st_case_535;
				case 536:
				goto st_case_536;
				case 537:
				goto st_case_537;
				case 538:
				goto st_case_538;
				case 539:
				goto st_case_539;
				case 540:
				goto st_case_540;
				case 541:
				goto st_case_541;
				case 260:
				goto st_case_260;
				case 261:
				goto st_case_261;
				case 262:
				goto st_case_262;
				case 263:
				goto st_case_263;
				case 264:
				goto st_case_264;
				case 265:
				goto st_case_265;
				case 266:
				goto st_case_266;
				case 267:
				goto st_case_267;
				case 268:
				goto st_case_268;
				case 269:
				goto st_case_269;
				case 270:
				goto st_case_270;
				case 271:
				goto st_case_271;
				case 272:
				goto st_case_272;
				case 273:
				goto st_case_273;
				case 274:
				goto st_case_274;
				case 275:
				goto st_case_275;
				case 276:
				goto st_case_276;
				case 277:
				goto st_case_277;
				case 278:
				goto st_case_278;
				case 279:
				goto st_case_279;
				case 280:
				goto st_case_280;
				case 281:
				goto st_case_281;
				case 282:
				goto st_case_282;
				case 283:
				goto st_case_283;
				case 284:
				goto st_case_284;
				case 285:
				goto st_case_285;
				case 286:
				goto st_case_286;
				case 287:
				goto st_case_287;
				case 288:
				goto st_case_288;
				case 289:
				goto st_case_289;
				case 290:
				goto st_case_290;
				case 291:
				goto st_case_291;
				case 292:
				goto st_case_292;
				case 293:
				goto st_case_293;
				case 294:
				goto st_case_294;
				case 295:
				goto st_case_295;
				case 296:
				goto st_case_296;
				case 297:
				goto st_case_297;
				case 298:
				goto st_case_298;
				case 299:
				goto st_case_299;
				case 300:
				goto st_case_300;
				case 301:
				goto st_case_301;
				case 302:
				goto st_case_302;
				case 303:
				goto st_case_303;
				case 304:
				goto st_case_304;
				case 305:
				goto st_case_305;
				case 306:
				goto st_case_306;
				case 307:
				goto st_case_307;
				case 308:
				goto st_case_308;
				case 309:
				goto st_case_309;
				case 310:
				goto st_case_310;
				case 311:
				goto st_case_311;
				case 312:
				goto st_case_312;
				case 313:
				goto st_case_313;
				case 314:
				goto st_case_314;
				case 315:
				goto st_case_315;
				case 316:
				goto st_case_316;
				case 317:
				goto st_case_317;
				case 318:
				goto st_case_318;
				case 319:
				goto st_case_319;
				case 320:
				goto st_case_320;
				case 321:
				goto st_case_321;
				case 322:
				goto st_case_322;
				case 323:
				goto st_case_323;
				case 324:
				goto st_case_324;
				case 325:
				goto st_case_325;
				case 326:
				goto st_case_326;
				case 327:
				goto st_case_327;
				case 328:
				goto st_case_328;
				case 329:
				goto st_case_329;
				case 330:
				goto st_case_330;
				case 331:
				goto st_case_331;
				case 332:
				goto st_case_332;
				case 333:
				goto st_case_333;
				case 334:
				goto st_case_334;
				case 335:
				goto st_case_335;
				case 336:
				goto st_case_336;
				case 337:
				goto st_case_337;
				case 338:
				goto st_case_338;
				case 339:
				goto st_case_339;
				case 340:
				goto st_case_340;
				case 341:
				goto st_case_341;
				case 342:
				goto st_case_342;
				case 343:
				goto st_case_343;
				case 344:
				goto st_case_344;
				case 345:
				goto st_case_345;
				case 346:
				goto st_case_346;
				case 347:
				goto st_case_347;
				case 348:
				goto st_case_348;
				case 349:
				goto st_case_349;
				case 350:
				goto st_case_350;
				case 351:
				goto st_case_351;
				case 352:
				goto st_case_352;
				case 353:
				goto st_case_353;
				case 354:
				goto st_case_354;
				case 355:
				goto st_case_355;
				case 356:
				goto st_case_356;
				case 357:
				goto st_case_357;
				case 358:
				goto st_case_358;
				case 359:
				goto st_case_359;
				case 360:
				goto st_case_360;
				case 361:
				goto st_case_361;
				case 362:
				goto st_case_362;
				case 363:
				goto st_case_363;
				case 364:
				goto st_case_364;
				case 365:
				goto st_case_365;
				case 366:
				goto st_case_366;
				case 367:
				goto st_case_367;
				case 368:
				goto st_case_368;
				case 369:
				goto st_case_369;
				case 370:
				goto st_case_370;
				case 371:
				goto st_case_371;
				case 372:
				goto st_case_372;
				case 373:
				goto st_case_373;
				case 374:
				goto st_case_374;
				case 375:
				goto st_case_375;
				case 376:
				goto st_case_376;
				case 377:
				goto st_case_377;
				case 378:
				goto st_case_378;
				case 379:
				goto st_case_379;
				case 380:
				goto st_case_380;
				case 381:
				goto st_case_381;
				case 382:
				goto st_case_382;
				case 383:
				goto st_case_383;
				case 384:
				goto st_case_384;
				case 385:
				goto st_case_385;
				case 386:
				goto st_case_386;
				case 387:
				goto st_case_387;
				case 388:
				goto st_case_388;
				case 389:
				goto st_case_389;
				case 390:
				goto st_case_390;
				case 391:
				goto st_case_391;
				case 392:
				goto st_case_392;
				case 393:
				goto st_case_393;
				case 394:
				goto st_case_394;
				case 395:
				goto st_case_395;
				case 396:
				goto st_case_396;
				case 397:
				goto st_case_397;
				case 398:
				goto st_case_398;
				case 399:
				goto st_case_399;
				case 400:
				goto st_case_400;
				case 401:
				goto st_case_401;
				case 402:
				goto st_case_402;
				case 403:
				goto st_case_403;
				case 404:
				goto st_case_404;
				case 405:
				goto st_case_405;
				case 406:
				goto st_case_406;
				case 407:
				goto st_case_407;
				case 408:
				goto st_case_408;
				case 409:
				goto st_case_409;
				case 410:
				goto st_case_410;
				case 411:
				goto st_case_411;
				case 412:
				goto st_case_412;
				case 413:
				goto st_case_413;
				case 414:
				goto st_case_414;
				case 415:
				goto st_case_415;
				case 416:
				goto st_case_416;
				case 417:
				goto st_case_417;
				case 418:
				goto st_case_418;
				case 419:
				goto st_case_419;
				case 420:
				goto st_case_420;
				case 421:
				goto st_case_421;
				case 422:
				goto st_case_422;
				case 423:
				goto st_case_423;
				case 424:
				goto st_case_424;
				case 425:
				goto st_case_425;
				case 426:
				goto st_case_426;
				case 427:
				goto st_case_427;
				case 428:
				goto st_case_428;
				case 429:
				goto st_case_429;
				case 430:
				goto st_case_430;
				case 431:
				goto st_case_431;
				case 432:
				goto st_case_432;
				case 433:
				goto st_case_433;
				case 434:
				goto st_case_434;
				case 435:
				goto st_case_435;
				case 436:
				goto st_case_436;
				case 437:
				goto st_case_437;
				case 438:
				goto st_case_438;
				case 439:
				goto st_case_439;
				case 440:
				goto st_case_440;
				case 441:
				goto st_case_441;
				case 442:
				goto st_case_442;
				case 443:
				goto st_case_443;
				case 444:
				goto st_case_444;
				case 445:
				goto st_case_445;
				case 446:
				goto st_case_446;
				case 447:
				goto st_case_447;
				case 448:
				goto st_case_448;
				case 449:
				goto st_case_449;
				case 450:
				goto st_case_450;
				case 542:
				goto st_case_542;
				case 543:
				goto st_case_543;
				case 544:
				goto st_case_544;
				case 545:
				goto st_case_545;
				case 546:
				goto st_case_546;
				case 547:
				goto st_case_547;
				case 548:
				goto st_case_548;
				case 549:
				goto st_case_549;
				case 550:
				goto st_case_550;
				case 551:
				goto st_case_551;
				case 552:
				goto st_case_552;
				case 553:
				goto st_case_553;
				case 554:
				goto st_case_554;
				case 555:
				goto st_case_555;
				case 556:
				goto st_case_556;
				case 557:
				goto st_case_557;
				case 558:
				goto st_case_558;
				case 559:
				goto st_case_559;
				case 560:
				goto st_case_560;
			}
			goto st_out;
			st_case_451:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto st453;
				}
				case 37: {
					goto st3;
				}
				case 47: {
					goto st458;
				}
				case 58: {
					goto st0;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 63: {
					goto st456;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 91 ) {
				if ( ( (*( p))) > 32 ) {
					if ( 65 <= ( (*( p))) ) {
						goto ctr461;
					}
				} else if ( ( (*( p))) >= 0 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 94 ) {
				if ( ( (*( p))) > 122 ) {
					if ( ( (*( p))) <= 125 ) {
						goto st0;
					}
				} else if ( ( (*( p))) >= 97 ) {
					goto ctr461;
				}
			} else {
				goto st0;
			}
			{
				goto st452;
			}
			st452:
			p+= 1;
			if ( p == pe )
			goto _test_eof452;
			st_case_452:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto st453;
				}
				case 37: {
					goto st3;
				}
				case 47: {
					goto st455;
				}
				case 58: {
					goto st0;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 63: {
					goto st456;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 91 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 94 ) {
				if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto st452;
			}
			st_case_0:
			st0:
			cs = 0;
			goto _out;
			ctr467:
			{
				#line 16 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 103 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setQuery(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st453;
			ctr469:
			{
				#line 103 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setQuery(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st453;
			ctr474:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st453;
			ctr485:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st453;
			ctr489:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			
			goto st453;
			ctr493:
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			
			goto st453;
			ctr548:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st453;
			ctr559:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st453;
			ctr563:
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st453;
			ctr566:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st453;
			ctr570:
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st453;
			st453:
			p+= 1;
			if ( p == pe )
			goto _test_eof453;
			st_case_453:
			switch( ( (*( p))) ) {
				case 37: {
					goto ctr463;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 34 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 35 ) {
				if ( ( (*( p))) > 94 ) {
					if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
						goto st0;
					}
				} else if ( ( (*( p))) >= 91 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto ctr462;
			}
			ctr462:
			{
				#line 16 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st454;
			st454:
			p+= 1;
			if ( p == pe )
			goto _test_eof454;
			st_case_454:
			switch( ( (*( p))) ) {
				case 37: {
					goto st1;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 34 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 35 ) {
				if ( ( (*( p))) > 94 ) {
					if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
						goto st0;
					}
				} else if ( ( (*( p))) >= 91 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto st454;
			}
			ctr463:
			{
				#line 16 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st1;
			st1:
			p+= 1;
			if ( p == pe )
			goto _test_eof1;
			st_case_1:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st2;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st2;
				}
			} else {
				goto st2;
			}
			{
				goto st0;
			}
			st2:
			p+= 1;
			if ( p == pe )
			goto _test_eof2;
			st_case_2:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st454;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st454;
				}
			} else {
				goto st454;
			}
			{
				goto st0;
			}
			st3:
			p+= 1;
			if ( p == pe )
			goto _test_eof3;
			st_case_3:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st4;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st4;
				}
			} else {
				goto st4;
			}
			{
				goto st0;
			}
			st4:
			p+= 1;
			if ( p == pe )
			goto _test_eof4;
			st_case_4:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st452;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st452;
				}
			} else {
				goto st452;
			}
			{
				goto st0;
			}
			ctr476:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st455;
			ctr486:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st455;
			ctr490:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			
			goto st455;
			ctr494:
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			
			goto st455;
			st455:
			p+= 1;
			if ( p == pe )
			goto _test_eof455;
			st_case_455:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto st453;
				}
				case 37: {
					goto st5;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 63: {
					goto st456;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 91 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 94 ) {
				if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto st455;
			}
			st5:
			p+= 1;
			if ( p == pe )
			goto _test_eof5;
			st_case_5:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st6;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st6;
				}
			} else {
				goto st6;
			}
			{
				goto st0;
			}
			st6:
			p+= 1;
			if ( p == pe )
			goto _test_eof6;
			st_case_6:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st455;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st455;
				}
			} else {
				goto st455;
			}
			{
				goto st0;
			}
			ctr482:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st456;
			ctr488:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st456;
			ctr492:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			
			goto st456;
			ctr496:
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			
			goto st456;
			ctr556:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st456;
			ctr562:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st456;
			ctr565:
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st456;
			ctr569:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st456;
			ctr573:
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				//std::cout << std::string(mark, fpc - mark) << std::endl;
				uri->setPath(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st456;
			st456:
			p+= 1;
			if ( p == pe )
			goto _test_eof456;
			st_case_456:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto ctr467;
				}
				case 37: {
					goto ctr468;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 91 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 94 ) {
				if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto ctr466;
			}
			ctr466:
			{
				#line 16 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st457;
			st457:
			p+= 1;
			if ( p == pe )
			goto _test_eof457;
			st_case_457:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto ctr469;
				}
				case 37: {
					goto st7;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 91 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 94 ) {
				if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto st457;
			}
			ctr468:
			{
				#line 16 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st7;
			st7:
			p+= 1;
			if ( p == pe )
			goto _test_eof7;
			st_case_7:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st8;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st8;
				}
			} else {
				goto st8;
			}
			{
				goto st0;
			}
			st8:
			p+= 1;
			if ( p == pe )
			goto _test_eof8;
			st_case_8:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st457;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st457;
				}
			} else {
				goto st457;
			}
			{
				goto st0;
			}
			st458:
			p+= 1;
			if ( p == pe )
			goto _test_eof458;
			st_case_458:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto st453;
				}
				case 37: {
					goto st5;
				}
				case 47: {
					goto st459;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 63: {
					goto st456;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 91 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 94 ) {
				if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto st455;
			}
			st459:
			p+= 1;
			if ( p == pe )
			goto _test_eof459;
			st_case_459:
			switch( ( (*( p))) ) {
				case 2: {
					goto ctr472;
				}
				case 33: {
					goto ctr473;
				}
				case 35: {
					goto ctr474;
				}
				case 37: {
					goto ctr475;
				}
				case 47: {
					goto ctr476;
				}
				case 48: {
					goto ctr477;
				}
				case 49: {
					goto ctr478;
				}
				case 50: {
					goto ctr479;
				}
				case 58: {
					goto ctr481;
				}
				case 59: {
					goto ctr473;
				}
				case 61: {
					goto ctr473;
				}
				case 63: {
					goto ctr482;
				}
				case 64: {
					goto ctr483;
				}
				case 91: {
					goto ctr484;
				}
				case 95: {
					goto ctr473;
				}
				case 126: {
					goto ctr473;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto ctr473;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto ctr473;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto ctr473;
				}
			} else {
				goto ctr480;
			}
			{
				goto st0;
			}
			ctr472:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st9;
			st9:
			p+= 1;
			if ( p == pe )
			goto _test_eof9;
			st_case_9:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st10;
			}
			{
				goto st0;
			}
			st10:
			p+= 1;
			if ( p == pe )
			goto _test_eof10;
			st_case_10:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st11;
			}
			{
				goto st0;
			}
			st11:
			p+= 1;
			if ( p == pe )
			goto _test_eof11;
			st_case_11:
			if ( ( (*( p))) == 46 ) {
				goto st12;
			}
			{
				goto st0;
			}
			st12:
			p+= 1;
			if ( p == pe )
			goto _test_eof12;
			st_case_12:
			switch( ( (*( p))) ) {
				case 2: {
					goto st13;
				}
				case 48: {
					goto st15;
				}
				case 49: {
					goto st27;
				}
				case 50: {
					goto st29;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st28;
			}
			{
				goto st0;
			}
			st13:
			p+= 1;
			if ( p == pe )
			goto _test_eof13;
			st_case_13:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st14;
			}
			{
				goto st0;
			}
			st14:
			p+= 1;
			if ( p == pe )
			goto _test_eof14;
			st_case_14:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st15;
			}
			{
				goto st0;
			}
			st15:
			p+= 1;
			if ( p == pe )
			goto _test_eof15;
			st_case_15:
			if ( ( (*( p))) == 46 ) {
				goto st16;
			}
			{
				goto st0;
			}
			st16:
			p+= 1;
			if ( p == pe )
			goto _test_eof16;
			st_case_16:
			switch( ( (*( p))) ) {
				case 2: {
					goto st17;
				}
				case 48: {
					goto st19;
				}
				case 49: {
					goto st23;
				}
				case 50: {
					goto st25;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st24;
			}
			{
				goto st0;
			}
			st17:
			p+= 1;
			if ( p == pe )
			goto _test_eof17;
			st_case_17:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st18;
			}
			{
				goto st0;
			}
			st18:
			p+= 1;
			if ( p == pe )
			goto _test_eof18;
			st_case_18:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st19;
			}
			{
				goto st0;
			}
			st19:
			p+= 1;
			if ( p == pe )
			goto _test_eof19;
			st_case_19:
			if ( ( (*( p))) == 46 ) {
				goto st20;
			}
			{
				goto st0;
			}
			st20:
			p+= 1;
			if ( p == pe )
			goto _test_eof20;
			st_case_20:
			switch( ( (*( p))) ) {
				case 2: {
					goto st21;
				}
				case 48: {
					goto st460;
				}
				case 49: {
					goto st463;
				}
				case 50: {
					goto st465;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st464;
			}
			{
				goto st0;
			}
			st21:
			p+= 1;
			if ( p == pe )
			goto _test_eof21;
			st_case_21:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st22;
			}
			{
				goto st0;
			}
			st22:
			p+= 1;
			if ( p == pe )
			goto _test_eof22;
			st_case_22:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st460;
			}
			{
				goto st0;
			}
			st460:
			p+= 1;
			if ( p == pe )
			goto _test_eof460;
			st_case_460:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr485;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 63: {
					goto ctr488;
				}
			}
			{
				goto st0;
			}
			ctr507:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st461;
			ctr487:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st461;
			st461:
			p+= 1;
			if ( p == pe )
			goto _test_eof461;
			st_case_461:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr489;
				}
				case 47: {
					goto ctr490;
				}
				case 63: {
					goto ctr492;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto ctr491;
			}
			{
				goto st0;
			}
			ctr491:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st462;
			st462:
			p+= 1;
			if ( p == pe )
			goto _test_eof462;
			st_case_462:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr493;
				}
				case 47: {
					goto ctr494;
				}
				case 63: {
					goto ctr496;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st462;
			}
			{
				goto st0;
			}
			st463:
			p+= 1;
			if ( p == pe )
			goto _test_eof463;
			st_case_463:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr485;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 63: {
					goto ctr488;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st464;
			}
			{
				goto st0;
			}
			st464:
			p+= 1;
			if ( p == pe )
			goto _test_eof464;
			st_case_464:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr485;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 63: {
					goto ctr488;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st460;
			}
			{
				goto st0;
			}
			st465:
			p+= 1;
			if ( p == pe )
			goto _test_eof465;
			st_case_465:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr485;
				}
				case 47: {
					goto ctr486;
				}
				case 53: {
					goto st466;
				}
				case 58: {
					goto ctr487;
				}
				case 63: {
					goto ctr488;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st460;
			}
			{
				goto st0;
			}
			st466:
			p+= 1;
			if ( p == pe )
			goto _test_eof466;
			st_case_466:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr485;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 63: {
					goto ctr488;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st460;
			}
			{
				goto st0;
			}
			st23:
			p+= 1;
			if ( p == pe )
			goto _test_eof23;
			st_case_23:
			if ( ( (*( p))) == 46 ) {
				goto st20;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st24;
			}
			{
				goto st0;
			}
			st24:
			p+= 1;
			if ( p == pe )
			goto _test_eof24;
			st_case_24:
			if ( ( (*( p))) == 46 ) {
				goto st20;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st19;
			}
			{
				goto st0;
			}
			st25:
			p+= 1;
			if ( p == pe )
			goto _test_eof25;
			st_case_25:
			switch( ( (*( p))) ) {
				case 46: {
					goto st20;
				}
				case 53: {
					goto st26;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st19;
			}
			{
				goto st0;
			}
			st26:
			p+= 1;
			if ( p == pe )
			goto _test_eof26;
			st_case_26:
			if ( ( (*( p))) == 46 ) {
				goto st20;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st19;
			}
			{
				goto st0;
			}
			st27:
			p+= 1;
			if ( p == pe )
			goto _test_eof27;
			st_case_27:
			if ( ( (*( p))) == 46 ) {
				goto st16;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st28;
			}
			{
				goto st0;
			}
			st28:
			p+= 1;
			if ( p == pe )
			goto _test_eof28;
			st_case_28:
			if ( ( (*( p))) == 46 ) {
				goto st16;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st15;
			}
			{
				goto st0;
			}
			st29:
			p+= 1;
			if ( p == pe )
			goto _test_eof29;
			st_case_29:
			switch( ( (*( p))) ) {
				case 46: {
					goto st16;
				}
				case 53: {
					goto st30;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st15;
			}
			{
				goto st0;
			}
			st30:
			p+= 1;
			if ( p == pe )
			goto _test_eof30;
			st_case_30:
			if ( ( (*( p))) == 46 ) {
				goto st16;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st15;
			}
			{
				goto st0;
			}
			ctr473:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st467;
			st467:
			p+= 1;
			if ( p == pe )
			goto _test_eof467;
			st_case_467:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st467;
				}
			} else {
				goto st467;
			}
			{
				goto st0;
			}
			ctr475:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st31;
			st31:
			p+= 1;
			if ( p == pe )
			goto _test_eof31;
			st_case_31:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st32;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st32;
				}
			} else {
				goto st32;
			}
			{
				goto st0;
			}
			st32:
			p+= 1;
			if ( p == pe )
			goto _test_eof32;
			st_case_32:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st467;
				}
			} else {
				goto st467;
			}
			{
				goto st0;
			}
			ctr481:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st468;
			ctr499:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st468;
			st468:
			p+= 1;
			if ( p == pe )
			goto _test_eof468;
			st_case_468:
			switch( ( (*( p))) ) {
				case 33: {
					goto st33;
				}
				case 35: {
					goto ctr489;
				}
				case 37: {
					goto st34;
				}
				case 47: {
					goto ctr490;
				}
				case 61: {
					goto st33;
				}
				case 63: {
					goto ctr492;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st33;
				}
				case 126: {
					goto st33;
				}
			}
			if ( ( (*( p))) < 58 ) {
				if ( ( (*( p))) > 46 ) {
					if ( 48 <= ( (*( p))) ) {
						goto ctr500;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st33;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st33;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st33;
				}
			} else {
				goto st33;
			}
			{
				goto st0;
			}
			st33:
			p+= 1;
			if ( p == pe )
			goto _test_eof33;
			st_case_33:
			switch( ( (*( p))) ) {
				case 33: {
					goto st33;
				}
				case 37: {
					goto st34;
				}
				case 61: {
					goto st33;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st33;
				}
				case 126: {
					goto st33;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st33;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st33;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st33;
				}
			} else {
				goto st33;
			}
			{
				goto st0;
			}
			st34:
			p+= 1;
			if ( p == pe )
			goto _test_eof34;
			st_case_34:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st35;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st35;
				}
			} else {
				goto st35;
			}
			{
				goto st0;
			}
			st35:
			p+= 1;
			if ( p == pe )
			goto _test_eof35;
			st_case_35:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st33;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st33;
				}
			} else {
				goto st33;
			}
			{
				goto st0;
			}
			ctr38:
			{
				#line 34 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if(mark) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setUserinfo(std::string(mark, p - mark));
				}
				mark = NULL;
			}
			
			goto st469;
			ctr483:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 34 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if(mark) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setUserinfo(std::string(mark, p - mark));
				}
				mark = NULL;
			}
			
			goto st469;
			st469:
			p+= 1;
			if ( p == pe )
			goto _test_eof469;
			st_case_469:
			switch( ( (*( p))) ) {
				case 2: {
					goto ctr472;
				}
				case 33: {
					goto ctr501;
				}
				case 35: {
					goto ctr474;
				}
				case 37: {
					goto ctr502;
				}
				case 47: {
					goto ctr476;
				}
				case 48: {
					goto ctr503;
				}
				case 49: {
					goto ctr504;
				}
				case 50: {
					goto ctr505;
				}
				case 58: {
					goto ctr507;
				}
				case 59: {
					goto ctr501;
				}
				case 61: {
					goto ctr501;
				}
				case 63: {
					goto ctr482;
				}
				case 91: {
					goto ctr484;
				}
				case 95: {
					goto ctr501;
				}
				case 126: {
					goto ctr501;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto ctr501;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto ctr501;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto ctr501;
				}
			} else {
				goto ctr506;
			}
			{
				goto st0;
			}
			ctr501:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st470;
			st470:
			p+= 1;
			if ( p == pe )
			goto _test_eof470;
			st_case_470:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st470;
				}
			} else {
				goto st470;
			}
			{
				goto st0;
			}
			ctr502:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st36;
			st36:
			p+= 1;
			if ( p == pe )
			goto _test_eof36;
			st_case_36:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st37;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st37;
				}
			} else {
				goto st37;
			}
			{
				goto st0;
			}
			st37:
			p+= 1;
			if ( p == pe )
			goto _test_eof37;
			st_case_37:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st470;
				}
			} else {
				goto st470;
			}
			{
				goto st0;
			}
			ctr503:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st471;
			st471:
			p+= 1;
			if ( p == pe )
			goto _test_eof471;
			st_case_471:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st472;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st470;
				}
			} else {
				goto st470;
			}
			{
				goto st0;
			}
			st472:
			p+= 1;
			if ( p == pe )
			goto _test_eof472;
			st_case_472:
			switch( ( (*( p))) ) {
				case 2: {
					goto st13;
				}
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 47: {
					goto ctr486;
				}
				case 48: {
					goto st473;
				}
				case 49: {
					goto st481;
				}
				case 50: {
					goto st483;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st482;
			}
			{
				goto st0;
			}
			st473:
			p+= 1;
			if ( p == pe )
			goto _test_eof473;
			st_case_473:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st474;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st470;
				}
			} else {
				goto st470;
			}
			{
				goto st0;
			}
			st474:
			p+= 1;
			if ( p == pe )
			goto _test_eof474;
			st_case_474:
			switch( ( (*( p))) ) {
				case 2: {
					goto st17;
				}
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 47: {
					goto ctr486;
				}
				case 48: {
					goto st475;
				}
				case 49: {
					goto st477;
				}
				case 50: {
					goto st479;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st478;
			}
			{
				goto st0;
			}
			st475:
			p+= 1;
			if ( p == pe )
			goto _test_eof475;
			st_case_475:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st476;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st470;
				}
			} else {
				goto st470;
			}
			{
				goto st0;
			}
			st476:
			p+= 1;
			if ( p == pe )
			goto _test_eof476;
			st_case_476:
			switch( ( (*( p))) ) {
				case 2: {
					goto st21;
				}
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st470;
				}
			} else {
				goto st470;
			}
			{
				goto st0;
			}
			st477:
			p+= 1;
			if ( p == pe )
			goto _test_eof477;
			st_case_477:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st476;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st478;
			}
			{
				goto st0;
			}
			st478:
			p+= 1;
			if ( p == pe )
			goto _test_eof478;
			st_case_478:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st476;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st475;
			}
			{
				goto st0;
			}
			st479:
			p+= 1;
			if ( p == pe )
			goto _test_eof479;
			st_case_479:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st476;
				}
				case 47: {
					goto ctr486;
				}
				case 53: {
					goto st480;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st475;
			}
			{
				goto st0;
			}
			st480:
			p+= 1;
			if ( p == pe )
			goto _test_eof480;
			st_case_480:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st476;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st475;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st470;
			}
			{
				goto st0;
			}
			st481:
			p+= 1;
			if ( p == pe )
			goto _test_eof481;
			st_case_481:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st474;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st482;
			}
			{
				goto st0;
			}
			st482:
			p+= 1;
			if ( p == pe )
			goto _test_eof482;
			st_case_482:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st474;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st473;
			}
			{
				goto st0;
			}
			st483:
			p+= 1;
			if ( p == pe )
			goto _test_eof483;
			st_case_483:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st474;
				}
				case 47: {
					goto ctr486;
				}
				case 53: {
					goto st484;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st473;
			}
			{
				goto st0;
			}
			st484:
			p+= 1;
			if ( p == pe )
			goto _test_eof484;
			st_case_484:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st474;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st473;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st470;
			}
			{
				goto st0;
			}
			ctr504:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st485;
			st485:
			p+= 1;
			if ( p == pe )
			goto _test_eof485;
			st_case_485:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st472;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st486;
			}
			{
				goto st0;
			}
			ctr506:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st486;
			st486:
			p+= 1;
			if ( p == pe )
			goto _test_eof486;
			st_case_486:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st472;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st471;
			}
			{
				goto st0;
			}
			ctr505:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st487;
			st487:
			p+= 1;
			if ( p == pe )
			goto _test_eof487;
			st_case_487:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st472;
				}
				case 47: {
					goto ctr486;
				}
				case 53: {
					goto st488;
				}
				case 58: {
					goto ctr487;
				}
				case 59: {
					goto st470;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st471;
			}
			{
				goto st0;
			}
			st488:
			p+= 1;
			if ( p == pe )
			goto _test_eof488;
			st_case_488:
			switch( ( (*( p))) ) {
				case 33: {
					goto st470;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st36;
				}
				case 46: {
					goto st472;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr487;
				}
				case 61: {
					goto st470;
				}
				case 63: {
					goto ctr488;
				}
				case 95: {
					goto st470;
				}
				case 126: {
					goto st470;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st471;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st470;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st470;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st470;
				}
			} else {
				goto st470;
			}
			{
				goto st0;
			}
			ctr484:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st38;
			st38:
			p+= 1;
			if ( p == pe )
			goto _test_eof38;
			st_case_38:
			switch( ( (*( p))) ) {
				case 58: {
					goto st146;
				}
				case 118: {
					goto st225;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st39;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st39;
				}
			} else {
				goto st39;
			}
			{
				goto st0;
			}
			st39:
			p+= 1;
			if ( p == pe )
			goto _test_eof39;
			st_case_39:
			if ( ( (*( p))) == 58 ) {
				goto st43;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st40;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st40;
				}
			} else {
				goto st40;
			}
			{
				goto st0;
			}
			st40:
			p+= 1;
			if ( p == pe )
			goto _test_eof40;
			st_case_40:
			if ( ( (*( p))) == 58 ) {
				goto st43;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st41;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st41;
				}
			} else {
				goto st41;
			}
			{
				goto st0;
			}
			st41:
			p+= 1;
			if ( p == pe )
			goto _test_eof41;
			st_case_41:
			if ( ( (*( p))) == 58 ) {
				goto st43;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st42;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st42;
				}
			} else {
				goto st42;
			}
			{
				goto st0;
			}
			st42:
			p+= 1;
			if ( p == pe )
			goto _test_eof42;
			st_case_42:
			if ( ( (*( p))) == 58 ) {
				goto st43;
			}
			{
				goto st0;
			}
			st43:
			p+= 1;
			if ( p == pe )
			goto _test_eof43;
			st_case_43:
			if ( ( (*( p))) == 58 ) {
				goto st141;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st44;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st44;
				}
			} else {
				goto st44;
			}
			{
				goto st0;
			}
			st44:
			p+= 1;
			if ( p == pe )
			goto _test_eof44;
			st_case_44:
			if ( ( (*( p))) == 58 ) {
				goto st48;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st45;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st45;
				}
			} else {
				goto st45;
			}
			{
				goto st0;
			}
			st45:
			p+= 1;
			if ( p == pe )
			goto _test_eof45;
			st_case_45:
			if ( ( (*( p))) == 58 ) {
				goto st48;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st46;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st46;
				}
			} else {
				goto st46;
			}
			{
				goto st0;
			}
			st46:
			p+= 1;
			if ( p == pe )
			goto _test_eof46;
			st_case_46:
			if ( ( (*( p))) == 58 ) {
				goto st48;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st47;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st47;
				}
			} else {
				goto st47;
			}
			{
				goto st0;
			}
			st47:
			p+= 1;
			if ( p == pe )
			goto _test_eof47;
			st_case_47:
			if ( ( (*( p))) == 58 ) {
				goto st48;
			}
			{
				goto st0;
			}
			st48:
			p+= 1;
			if ( p == pe )
			goto _test_eof48;
			st_case_48:
			if ( ( (*( p))) == 58 ) {
				goto st136;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st49;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st49;
				}
			} else {
				goto st49;
			}
			{
				goto st0;
			}
			st49:
			p+= 1;
			if ( p == pe )
			goto _test_eof49;
			st_case_49:
			if ( ( (*( p))) == 58 ) {
				goto st53;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st50;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st50;
				}
			} else {
				goto st50;
			}
			{
				goto st0;
			}
			st50:
			p+= 1;
			if ( p == pe )
			goto _test_eof50;
			st_case_50:
			if ( ( (*( p))) == 58 ) {
				goto st53;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st51;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st51;
				}
			} else {
				goto st51;
			}
			{
				goto st0;
			}
			st51:
			p+= 1;
			if ( p == pe )
			goto _test_eof51;
			st_case_51:
			if ( ( (*( p))) == 58 ) {
				goto st53;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st52;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st52;
				}
			} else {
				goto st52;
			}
			{
				goto st0;
			}
			st52:
			p+= 1;
			if ( p == pe )
			goto _test_eof52;
			st_case_52:
			if ( ( (*( p))) == 58 ) {
				goto st53;
			}
			{
				goto st0;
			}
			st53:
			p+= 1;
			if ( p == pe )
			goto _test_eof53;
			st_case_53:
			if ( ( (*( p))) == 58 ) {
				goto st131;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st54;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st54;
				}
			} else {
				goto st54;
			}
			{
				goto st0;
			}
			st54:
			p+= 1;
			if ( p == pe )
			goto _test_eof54;
			st_case_54:
			if ( ( (*( p))) == 58 ) {
				goto st58;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st55;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st55;
				}
			} else {
				goto st55;
			}
			{
				goto st0;
			}
			st55:
			p+= 1;
			if ( p == pe )
			goto _test_eof55;
			st_case_55:
			if ( ( (*( p))) == 58 ) {
				goto st58;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st56;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st56;
				}
			} else {
				goto st56;
			}
			{
				goto st0;
			}
			st56:
			p+= 1;
			if ( p == pe )
			goto _test_eof56;
			st_case_56:
			if ( ( (*( p))) == 58 ) {
				goto st58;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st57;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st57;
				}
			} else {
				goto st57;
			}
			{
				goto st0;
			}
			st57:
			p+= 1;
			if ( p == pe )
			goto _test_eof57;
			st_case_57:
			if ( ( (*( p))) == 58 ) {
				goto st58;
			}
			{
				goto st0;
			}
			st58:
			p+= 1;
			if ( p == pe )
			goto _test_eof58;
			st_case_58:
			if ( ( (*( p))) == 58 ) {
				goto st126;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st59;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st59;
				}
			} else {
				goto st59;
			}
			{
				goto st0;
			}
			st59:
			p+= 1;
			if ( p == pe )
			goto _test_eof59;
			st_case_59:
			if ( ( (*( p))) == 58 ) {
				goto st63;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st60;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st60;
				}
			} else {
				goto st60;
			}
			{
				goto st0;
			}
			st60:
			p+= 1;
			if ( p == pe )
			goto _test_eof60;
			st_case_60:
			if ( ( (*( p))) == 58 ) {
				goto st63;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st61;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st61;
				}
			} else {
				goto st61;
			}
			{
				goto st0;
			}
			st61:
			p+= 1;
			if ( p == pe )
			goto _test_eof61;
			st_case_61:
			if ( ( (*( p))) == 58 ) {
				goto st63;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st62;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st62;
				}
			} else {
				goto st62;
			}
			{
				goto st0;
			}
			st62:
			p+= 1;
			if ( p == pe )
			goto _test_eof62;
			st_case_62:
			if ( ( (*( p))) == 58 ) {
				goto st63;
			}
			{
				goto st0;
			}
			st63:
			p+= 1;
			if ( p == pe )
			goto _test_eof63;
			st_case_63:
			if ( ( (*( p))) == 58 ) {
				goto st113;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st64;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st64;
				}
			} else {
				goto st64;
			}
			{
				goto st0;
			}
			st64:
			p+= 1;
			if ( p == pe )
			goto _test_eof64;
			st_case_64:
			if ( ( (*( p))) == 58 ) {
				goto st68;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st65;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st65;
				}
			} else {
				goto st65;
			}
			{
				goto st0;
			}
			st65:
			p+= 1;
			if ( p == pe )
			goto _test_eof65;
			st_case_65:
			if ( ( (*( p))) == 58 ) {
				goto st68;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st66;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st66;
				}
			} else {
				goto st66;
			}
			{
				goto st0;
			}
			st66:
			p+= 1;
			if ( p == pe )
			goto _test_eof66;
			st_case_66:
			if ( ( (*( p))) == 58 ) {
				goto st68;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st67;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st67;
				}
			} else {
				goto st67;
			}
			{
				goto st0;
			}
			st67:
			p+= 1;
			if ( p == pe )
			goto _test_eof67;
			st_case_67:
			if ( ( (*( p))) == 58 ) {
				goto st68;
			}
			{
				goto st0;
			}
			st68:
			p+= 1;
			if ( p == pe )
			goto _test_eof68;
			st_case_68:
			switch( ( (*( p))) ) {
				case 2: {
					goto st69;
				}
				case 48: {
					goto st96;
				}
				case 49: {
					goto st104;
				}
				case 50: {
					goto st107;
				}
				case 58: {
					goto st111;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st110;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st112;
				}
			} else {
				goto st112;
			}
			{
				goto st0;
			}
			st69:
			p+= 1;
			if ( p == pe )
			goto _test_eof69;
			st_case_69:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st70;
			}
			{
				goto st0;
			}
			st70:
			p+= 1;
			if ( p == pe )
			goto _test_eof70;
			st_case_70:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st71;
			}
			{
				goto st0;
			}
			st71:
			p+= 1;
			if ( p == pe )
			goto _test_eof71;
			st_case_71:
			if ( ( (*( p))) == 46 ) {
				goto st72;
			}
			{
				goto st0;
			}
			st72:
			p+= 1;
			if ( p == pe )
			goto _test_eof72;
			st_case_72:
			switch( ( (*( p))) ) {
				case 2: {
					goto st73;
				}
				case 48: {
					goto st75;
				}
				case 49: {
					goto st92;
				}
				case 50: {
					goto st94;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st93;
			}
			{
				goto st0;
			}
			st73:
			p+= 1;
			if ( p == pe )
			goto _test_eof73;
			st_case_73:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st74;
			}
			{
				goto st0;
			}
			st74:
			p+= 1;
			if ( p == pe )
			goto _test_eof74;
			st_case_74:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st75;
			}
			{
				goto st0;
			}
			st75:
			p+= 1;
			if ( p == pe )
			goto _test_eof75;
			st_case_75:
			if ( ( (*( p))) == 46 ) {
				goto st76;
			}
			{
				goto st0;
			}
			st76:
			p+= 1;
			if ( p == pe )
			goto _test_eof76;
			st_case_76:
			switch( ( (*( p))) ) {
				case 2: {
					goto st77;
				}
				case 48: {
					goto st79;
				}
				case 49: {
					goto st88;
				}
				case 50: {
					goto st90;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st89;
			}
			{
				goto st0;
			}
			st77:
			p+= 1;
			if ( p == pe )
			goto _test_eof77;
			st_case_77:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st78;
			}
			{
				goto st0;
			}
			st78:
			p+= 1;
			if ( p == pe )
			goto _test_eof78;
			st_case_78:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st79;
			}
			{
				goto st0;
			}
			st79:
			p+= 1;
			if ( p == pe )
			goto _test_eof79;
			st_case_79:
			if ( ( (*( p))) == 46 ) {
				goto st80;
			}
			{
				goto st0;
			}
			st80:
			p+= 1;
			if ( p == pe )
			goto _test_eof80;
			st_case_80:
			switch( ( (*( p))) ) {
				case 2: {
					goto st81;
				}
				case 48: {
					goto st83;
				}
				case 49: {
					goto st84;
				}
				case 50: {
					goto st86;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st85;
			}
			{
				goto st0;
			}
			st81:
			p+= 1;
			if ( p == pe )
			goto _test_eof81;
			st_case_81:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st82;
			}
			{
				goto st0;
			}
			st82:
			p+= 1;
			if ( p == pe )
			goto _test_eof82;
			st_case_82:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st83;
			}
			{
				goto st0;
			}
			st83:
			p+= 1;
			if ( p == pe )
			goto _test_eof83;
			st_case_83:
			if ( ( (*( p))) == 93 ) {
				goto st460;
			}
			{
				goto st0;
			}
			st84:
			p+= 1;
			if ( p == pe )
			goto _test_eof84;
			st_case_84:
			if ( ( (*( p))) == 93 ) {
				goto st460;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st85;
			}
			{
				goto st0;
			}
			st85:
			p+= 1;
			if ( p == pe )
			goto _test_eof85;
			st_case_85:
			if ( ( (*( p))) == 93 ) {
				goto st460;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st83;
			}
			{
				goto st0;
			}
			st86:
			p+= 1;
			if ( p == pe )
			goto _test_eof86;
			st_case_86:
			switch( ( (*( p))) ) {
				case 53: {
					goto st87;
				}
				case 93: {
					goto st460;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st83;
			}
			{
				goto st0;
			}
			st87:
			p+= 1;
			if ( p == pe )
			goto _test_eof87;
			st_case_87:
			if ( ( (*( p))) == 93 ) {
				goto st460;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st83;
			}
			{
				goto st0;
			}
			st88:
			p+= 1;
			if ( p == pe )
			goto _test_eof88;
			st_case_88:
			if ( ( (*( p))) == 46 ) {
				goto st80;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st89;
			}
			{
				goto st0;
			}
			st89:
			p+= 1;
			if ( p == pe )
			goto _test_eof89;
			st_case_89:
			if ( ( (*( p))) == 46 ) {
				goto st80;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st79;
			}
			{
				goto st0;
			}
			st90:
			p+= 1;
			if ( p == pe )
			goto _test_eof90;
			st_case_90:
			switch( ( (*( p))) ) {
				case 46: {
					goto st80;
				}
				case 53: {
					goto st91;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st79;
			}
			{
				goto st0;
			}
			st91:
			p+= 1;
			if ( p == pe )
			goto _test_eof91;
			st_case_91:
			if ( ( (*( p))) == 46 ) {
				goto st80;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st79;
			}
			{
				goto st0;
			}
			st92:
			p+= 1;
			if ( p == pe )
			goto _test_eof92;
			st_case_92:
			if ( ( (*( p))) == 46 ) {
				goto st76;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st93;
			}
			{
				goto st0;
			}
			st93:
			p+= 1;
			if ( p == pe )
			goto _test_eof93;
			st_case_93:
			if ( ( (*( p))) == 46 ) {
				goto st76;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st75;
			}
			{
				goto st0;
			}
			st94:
			p+= 1;
			if ( p == pe )
			goto _test_eof94;
			st_case_94:
			switch( ( (*( p))) ) {
				case 46: {
					goto st76;
				}
				case 53: {
					goto st95;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st75;
			}
			{
				goto st0;
			}
			st95:
			p+= 1;
			if ( p == pe )
			goto _test_eof95;
			st_case_95:
			if ( ( (*( p))) == 46 ) {
				goto st76;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st75;
			}
			{
				goto st0;
			}
			st96:
			p+= 1;
			if ( p == pe )
			goto _test_eof96;
			st_case_96:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st100;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st97;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st97;
				}
			} else {
				goto st97;
			}
			{
				goto st0;
			}
			st97:
			p+= 1;
			if ( p == pe )
			goto _test_eof97;
			st_case_97:
			if ( ( (*( p))) == 58 ) {
				goto st100;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st98;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st98;
				}
			} else {
				goto st98;
			}
			{
				goto st0;
			}
			st98:
			p+= 1;
			if ( p == pe )
			goto _test_eof98;
			st_case_98:
			if ( ( (*( p))) == 58 ) {
				goto st100;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st99;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st99;
				}
			} else {
				goto st99;
			}
			{
				goto st0;
			}
			st99:
			p+= 1;
			if ( p == pe )
			goto _test_eof99;
			st_case_99:
			if ( ( (*( p))) == 58 ) {
				goto st100;
			}
			{
				goto st0;
			}
			st100:
			p+= 1;
			if ( p == pe )
			goto _test_eof100;
			st_case_100:
			if ( ( (*( p))) == 58 ) {
				goto st83;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st101;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st101;
				}
			} else {
				goto st101;
			}
			{
				goto st0;
			}
			st101:
			p+= 1;
			if ( p == pe )
			goto _test_eof101;
			st_case_101:
			if ( ( (*( p))) == 93 ) {
				goto st460;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st102;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st102;
				}
			} else {
				goto st102;
			}
			{
				goto st0;
			}
			st102:
			p+= 1;
			if ( p == pe )
			goto _test_eof102;
			st_case_102:
			if ( ( (*( p))) == 93 ) {
				goto st460;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st103;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st103;
				}
			} else {
				goto st103;
			}
			{
				goto st0;
			}
			st103:
			p+= 1;
			if ( p == pe )
			goto _test_eof103;
			st_case_103:
			if ( ( (*( p))) == 93 ) {
				goto st460;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st83;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st83;
				}
			} else {
				goto st83;
			}
			{
				goto st0;
			}
			st104:
			p+= 1;
			if ( p == pe )
			goto _test_eof104;
			st_case_104:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st100;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st105;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st97;
				}
			} else {
				goto st97;
			}
			{
				goto st0;
			}
			st105:
			p+= 1;
			if ( p == pe )
			goto _test_eof105;
			st_case_105:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st100;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st106;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st98;
				}
			} else {
				goto st98;
			}
			{
				goto st0;
			}
			st106:
			p+= 1;
			if ( p == pe )
			goto _test_eof106;
			st_case_106:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st100;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st99;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st99;
				}
			} else {
				goto st99;
			}
			{
				goto st0;
			}
			st107:
			p+= 1;
			if ( p == pe )
			goto _test_eof107;
			st_case_107:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 53: {
					goto st109;
				}
				case 58: {
					goto st100;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st108;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st97;
				}
			} else {
				goto st97;
			}
			{
				goto st0;
			}
			st108:
			p+= 1;
			if ( p == pe )
			goto _test_eof108;
			st_case_108:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st100;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st98;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st98;
				}
			} else {
				goto st98;
			}
			{
				goto st0;
			}
			st109:
			p+= 1;
			if ( p == pe )
			goto _test_eof109;
			st_case_109:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st100;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st106;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st98;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st98;
				}
			} else {
				goto st98;
			}
			{
				goto st0;
			}
			st110:
			p+= 1;
			if ( p == pe )
			goto _test_eof110;
			st_case_110:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st100;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st108;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st97;
				}
			} else {
				goto st97;
			}
			{
				goto st0;
			}
			st111:
			p+= 1;
			if ( p == pe )
			goto _test_eof111;
			st_case_111:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st101;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st101;
				}
			} else {
				goto st101;
			}
			{
				goto st0;
			}
			st112:
			p+= 1;
			if ( p == pe )
			goto _test_eof112;
			st_case_112:
			if ( ( (*( p))) == 58 ) {
				goto st100;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st97;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st97;
				}
			} else {
				goto st97;
			}
			{
				goto st0;
			}
			st113:
			p+= 1;
			if ( p == pe )
			goto _test_eof113;
			st_case_113:
			switch( ( (*( p))) ) {
				case 2: {
					goto st69;
				}
				case 48: {
					goto st114;
				}
				case 49: {
					goto st118;
				}
				case 50: {
					goto st121;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st124;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st125;
				}
			} else {
				goto st125;
			}
			{
				goto st0;
			}
			st114:
			p+= 1;
			if ( p == pe )
			goto _test_eof114;
			st_case_114:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st115;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st115;
				}
			} else {
				goto st115;
			}
			{
				goto st0;
			}
			st115:
			p+= 1;
			if ( p == pe )
			goto _test_eof115;
			st_case_115:
			if ( ( (*( p))) == 58 ) {
				goto st111;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st116;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st116;
				}
			} else {
				goto st116;
			}
			{
				goto st0;
			}
			st116:
			p+= 1;
			if ( p == pe )
			goto _test_eof116;
			st_case_116:
			if ( ( (*( p))) == 58 ) {
				goto st111;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st117;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st117;
				}
			} else {
				goto st117;
			}
			{
				goto st0;
			}
			st117:
			p+= 1;
			if ( p == pe )
			goto _test_eof117;
			st_case_117:
			if ( ( (*( p))) == 58 ) {
				goto st111;
			}
			{
				goto st0;
			}
			st118:
			p+= 1;
			if ( p == pe )
			goto _test_eof118;
			st_case_118:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st119;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st115;
				}
			} else {
				goto st115;
			}
			{
				goto st0;
			}
			st119:
			p+= 1;
			if ( p == pe )
			goto _test_eof119;
			st_case_119:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st120;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st116;
				}
			} else {
				goto st116;
			}
			{
				goto st0;
			}
			st120:
			p+= 1;
			if ( p == pe )
			goto _test_eof120;
			st_case_120:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st117;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st117;
				}
			} else {
				goto st117;
			}
			{
				goto st0;
			}
			st121:
			p+= 1;
			if ( p == pe )
			goto _test_eof121;
			st_case_121:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 53: {
					goto st123;
				}
				case 58: {
					goto st111;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st122;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st115;
				}
			} else {
				goto st115;
			}
			{
				goto st0;
			}
			st122:
			p+= 1;
			if ( p == pe )
			goto _test_eof122;
			st_case_122:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st116;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st116;
				}
			} else {
				goto st116;
			}
			{
				goto st0;
			}
			st123:
			p+= 1;
			if ( p == pe )
			goto _test_eof123;
			st_case_123:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st120;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st116;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st116;
				}
			} else {
				goto st116;
			}
			{
				goto st0;
			}
			st124:
			p+= 1;
			if ( p == pe )
			goto _test_eof124;
			st_case_124:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st122;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st115;
				}
			} else {
				goto st115;
			}
			{
				goto st0;
			}
			st125:
			p+= 1;
			if ( p == pe )
			goto _test_eof125;
			st_case_125:
			if ( ( (*( p))) == 58 ) {
				goto st111;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st115;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st115;
				}
			} else {
				goto st115;
			}
			{
				goto st0;
			}
			st126:
			p+= 1;
			if ( p == pe )
			goto _test_eof126;
			st_case_126:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st127;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st127;
				}
			} else {
				goto st127;
			}
			{
				goto st0;
			}
			st127:
			p+= 1;
			if ( p == pe )
			goto _test_eof127;
			st_case_127:
			if ( ( (*( p))) == 58 ) {
				goto st113;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st128;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st128;
				}
			} else {
				goto st128;
			}
			{
				goto st0;
			}
			st128:
			p+= 1;
			if ( p == pe )
			goto _test_eof128;
			st_case_128:
			if ( ( (*( p))) == 58 ) {
				goto st113;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st129;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st129;
				}
			} else {
				goto st129;
			}
			{
				goto st0;
			}
			st129:
			p+= 1;
			if ( p == pe )
			goto _test_eof129;
			st_case_129:
			if ( ( (*( p))) == 58 ) {
				goto st113;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st130;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st130;
				}
			} else {
				goto st130;
			}
			{
				goto st0;
			}
			st130:
			p+= 1;
			if ( p == pe )
			goto _test_eof130;
			st_case_130:
			if ( ( (*( p))) == 58 ) {
				goto st113;
			}
			{
				goto st0;
			}
			st131:
			p+= 1;
			if ( p == pe )
			goto _test_eof131;
			st_case_131:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st132;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st132;
				}
			} else {
				goto st132;
			}
			{
				goto st0;
			}
			st132:
			p+= 1;
			if ( p == pe )
			goto _test_eof132;
			st_case_132:
			if ( ( (*( p))) == 58 ) {
				goto st126;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st133;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st133;
				}
			} else {
				goto st133;
			}
			{
				goto st0;
			}
			st133:
			p+= 1;
			if ( p == pe )
			goto _test_eof133;
			st_case_133:
			if ( ( (*( p))) == 58 ) {
				goto st126;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st134;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st134;
				}
			} else {
				goto st134;
			}
			{
				goto st0;
			}
			st134:
			p+= 1;
			if ( p == pe )
			goto _test_eof134;
			st_case_134:
			if ( ( (*( p))) == 58 ) {
				goto st126;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st135;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st135;
				}
			} else {
				goto st135;
			}
			{
				goto st0;
			}
			st135:
			p+= 1;
			if ( p == pe )
			goto _test_eof135;
			st_case_135:
			if ( ( (*( p))) == 58 ) {
				goto st126;
			}
			{
				goto st0;
			}
			st136:
			p+= 1;
			if ( p == pe )
			goto _test_eof136;
			st_case_136:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st137;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st137;
				}
			} else {
				goto st137;
			}
			{
				goto st0;
			}
			st137:
			p+= 1;
			if ( p == pe )
			goto _test_eof137;
			st_case_137:
			if ( ( (*( p))) == 58 ) {
				goto st131;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st138;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st138;
				}
			} else {
				goto st138;
			}
			{
				goto st0;
			}
			st138:
			p+= 1;
			if ( p == pe )
			goto _test_eof138;
			st_case_138:
			if ( ( (*( p))) == 58 ) {
				goto st131;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st139;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st139;
				}
			} else {
				goto st139;
			}
			{
				goto st0;
			}
			st139:
			p+= 1;
			if ( p == pe )
			goto _test_eof139;
			st_case_139:
			if ( ( (*( p))) == 58 ) {
				goto st131;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st140;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st140;
				}
			} else {
				goto st140;
			}
			{
				goto st0;
			}
			st140:
			p+= 1;
			if ( p == pe )
			goto _test_eof140;
			st_case_140:
			if ( ( (*( p))) == 58 ) {
				goto st131;
			}
			{
				goto st0;
			}
			st141:
			p+= 1;
			if ( p == pe )
			goto _test_eof141;
			st_case_141:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st142;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st142;
				}
			} else {
				goto st142;
			}
			{
				goto st0;
			}
			st142:
			p+= 1;
			if ( p == pe )
			goto _test_eof142;
			st_case_142:
			if ( ( (*( p))) == 58 ) {
				goto st136;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st143;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st143;
				}
			} else {
				goto st143;
			}
			{
				goto st0;
			}
			st143:
			p+= 1;
			if ( p == pe )
			goto _test_eof143;
			st_case_143:
			if ( ( (*( p))) == 58 ) {
				goto st136;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st144;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st144;
				}
			} else {
				goto st144;
			}
			{
				goto st0;
			}
			st144:
			p+= 1;
			if ( p == pe )
			goto _test_eof144;
			st_case_144:
			if ( ( (*( p))) == 58 ) {
				goto st136;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st145;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st145;
				}
			} else {
				goto st145;
			}
			{
				goto st0;
			}
			st145:
			p+= 1;
			if ( p == pe )
			goto _test_eof145;
			st_case_145:
			if ( ( (*( p))) == 58 ) {
				goto st136;
			}
			{
				goto st0;
			}
			st146:
			p+= 1;
			if ( p == pe )
			goto _test_eof146;
			st_case_146:
			if ( ( (*( p))) == 58 ) {
				goto st147;
			}
			{
				goto st0;
			}
			st147:
			p+= 1;
			if ( p == pe )
			goto _test_eof147;
			st_case_147:
			switch( ( (*( p))) ) {
				case 2: {
					goto st69;
				}
				case 48: {
					goto st148;
				}
				case 49: {
					goto st217;
				}
				case 50: {
					goto st220;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st223;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st224;
				}
			} else {
				goto st224;
			}
			{
				goto st0;
			}
			st148:
			p+= 1;
			if ( p == pe )
			goto _test_eof148;
			st_case_148:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st149;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st149;
				}
			} else {
				goto st149;
			}
			{
				goto st0;
			}
			st149:
			p+= 1;
			if ( p == pe )
			goto _test_eof149;
			st_case_149:
			switch( ( (*( p))) ) {
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st150;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st150;
				}
			} else {
				goto st150;
			}
			{
				goto st0;
			}
			st150:
			p+= 1;
			if ( p == pe )
			goto _test_eof150;
			st_case_150:
			switch( ( (*( p))) ) {
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st151;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st151;
				}
			} else {
				goto st151;
			}
			{
				goto st0;
			}
			st151:
			p+= 1;
			if ( p == pe )
			goto _test_eof151;
			st_case_151:
			switch( ( (*( p))) ) {
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			{
				goto st0;
			}
			st152:
			p+= 1;
			if ( p == pe )
			goto _test_eof152;
			st_case_152:
			switch( ( (*( p))) ) {
				case 2: {
					goto st69;
				}
				case 48: {
					goto st153;
				}
				case 49: {
					goto st209;
				}
				case 50: {
					goto st212;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st215;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st216;
				}
			} else {
				goto st216;
			}
			{
				goto st0;
			}
			st153:
			p+= 1;
			if ( p == pe )
			goto _test_eof153;
			st_case_153:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st154;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st154;
				}
			} else {
				goto st154;
			}
			{
				goto st0;
			}
			st154:
			p+= 1;
			if ( p == pe )
			goto _test_eof154;
			st_case_154:
			switch( ( (*( p))) ) {
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st155;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st155;
				}
			} else {
				goto st155;
			}
			{
				goto st0;
			}
			st155:
			p+= 1;
			if ( p == pe )
			goto _test_eof155;
			st_case_155:
			switch( ( (*( p))) ) {
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st156;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st156;
				}
			} else {
				goto st156;
			}
			{
				goto st0;
			}
			st156:
			p+= 1;
			if ( p == pe )
			goto _test_eof156;
			st_case_156:
			switch( ( (*( p))) ) {
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			{
				goto st0;
			}
			st157:
			p+= 1;
			if ( p == pe )
			goto _test_eof157;
			st_case_157:
			switch( ( (*( p))) ) {
				case 2: {
					goto st69;
				}
				case 48: {
					goto st158;
				}
				case 49: {
					goto st201;
				}
				case 50: {
					goto st204;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st207;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st208;
				}
			} else {
				goto st208;
			}
			{
				goto st0;
			}
			st158:
			p+= 1;
			if ( p == pe )
			goto _test_eof158;
			st_case_158:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st159;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st159;
				}
			} else {
				goto st159;
			}
			{
				goto st0;
			}
			st159:
			p+= 1;
			if ( p == pe )
			goto _test_eof159;
			st_case_159:
			switch( ( (*( p))) ) {
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st160;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st160;
				}
			} else {
				goto st160;
			}
			{
				goto st0;
			}
			st160:
			p+= 1;
			if ( p == pe )
			goto _test_eof160;
			st_case_160:
			switch( ( (*( p))) ) {
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st161;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st161;
				}
			} else {
				goto st161;
			}
			{
				goto st0;
			}
			st161:
			p+= 1;
			if ( p == pe )
			goto _test_eof161;
			st_case_161:
			switch( ( (*( p))) ) {
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			{
				goto st0;
			}
			st162:
			p+= 1;
			if ( p == pe )
			goto _test_eof162;
			st_case_162:
			switch( ( (*( p))) ) {
				case 2: {
					goto st69;
				}
				case 48: {
					goto st163;
				}
				case 49: {
					goto st193;
				}
				case 50: {
					goto st196;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st199;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st200;
				}
			} else {
				goto st200;
			}
			{
				goto st0;
			}
			st163:
			p+= 1;
			if ( p == pe )
			goto _test_eof163;
			st_case_163:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st164;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st164;
				}
			} else {
				goto st164;
			}
			{
				goto st0;
			}
			st164:
			p+= 1;
			if ( p == pe )
			goto _test_eof164;
			st_case_164:
			switch( ( (*( p))) ) {
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st165;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st165;
				}
			} else {
				goto st165;
			}
			{
				goto st0;
			}
			st165:
			p+= 1;
			if ( p == pe )
			goto _test_eof165;
			st_case_165:
			switch( ( (*( p))) ) {
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st166;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st166;
				}
			} else {
				goto st166;
			}
			{
				goto st0;
			}
			st166:
			p+= 1;
			if ( p == pe )
			goto _test_eof166;
			st_case_166:
			switch( ( (*( p))) ) {
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			{
				goto st0;
			}
			st167:
			p+= 1;
			if ( p == pe )
			goto _test_eof167;
			st_case_167:
			switch( ( (*( p))) ) {
				case 2: {
					goto st69;
				}
				case 48: {
					goto st168;
				}
				case 49: {
					goto st185;
				}
				case 50: {
					goto st188;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st191;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st192;
				}
			} else {
				goto st192;
			}
			{
				goto st0;
			}
			st168:
			p+= 1;
			if ( p == pe )
			goto _test_eof168;
			st_case_168:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st169;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st169;
				}
			} else {
				goto st169;
			}
			{
				goto st0;
			}
			st169:
			p+= 1;
			if ( p == pe )
			goto _test_eof169;
			st_case_169:
			switch( ( (*( p))) ) {
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st170;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st170;
				}
			} else {
				goto st170;
			}
			{
				goto st0;
			}
			st170:
			p+= 1;
			if ( p == pe )
			goto _test_eof170;
			st_case_170:
			switch( ( (*( p))) ) {
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st171;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st171;
				}
			} else {
				goto st171;
			}
			{
				goto st0;
			}
			st171:
			p+= 1;
			if ( p == pe )
			goto _test_eof171;
			st_case_171:
			switch( ( (*( p))) ) {
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			{
				goto st0;
			}
			st172:
			p+= 1;
			if ( p == pe )
			goto _test_eof172;
			st_case_172:
			switch( ( (*( p))) ) {
				case 2: {
					goto st69;
				}
				case 48: {
					goto st173;
				}
				case 49: {
					goto st177;
				}
				case 50: {
					goto st180;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st183;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st184;
				}
			} else {
				goto st184;
			}
			{
				goto st0;
			}
			st173:
			p+= 1;
			if ( p == pe )
			goto _test_eof173;
			st_case_173:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st174;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st174;
				}
			} else {
				goto st174;
			}
			{
				goto st0;
			}
			st174:
			p+= 1;
			if ( p == pe )
			goto _test_eof174;
			st_case_174:
			switch( ( (*( p))) ) {
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st175;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st175;
				}
			} else {
				goto st175;
			}
			{
				goto st0;
			}
			st175:
			p+= 1;
			if ( p == pe )
			goto _test_eof175;
			st_case_175:
			switch( ( (*( p))) ) {
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st176;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st176;
				}
			} else {
				goto st176;
			}
			{
				goto st0;
			}
			st176:
			p+= 1;
			if ( p == pe )
			goto _test_eof176;
			st_case_176:
			switch( ( (*( p))) ) {
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			{
				goto st0;
			}
			st177:
			p+= 1;
			if ( p == pe )
			goto _test_eof177;
			st_case_177:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st178;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st174;
				}
			} else {
				goto st174;
			}
			{
				goto st0;
			}
			st178:
			p+= 1;
			if ( p == pe )
			goto _test_eof178;
			st_case_178:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st179;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st175;
				}
			} else {
				goto st175;
			}
			{
				goto st0;
			}
			st179:
			p+= 1;
			if ( p == pe )
			goto _test_eof179;
			st_case_179:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st176;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st176;
				}
			} else {
				goto st176;
			}
			{
				goto st0;
			}
			st180:
			p+= 1;
			if ( p == pe )
			goto _test_eof180;
			st_case_180:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 53: {
					goto st182;
				}
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st181;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st174;
				}
			} else {
				goto st174;
			}
			{
				goto st0;
			}
			st181:
			p+= 1;
			if ( p == pe )
			goto _test_eof181;
			st_case_181:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st175;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st175;
				}
			} else {
				goto st175;
			}
			{
				goto st0;
			}
			st182:
			p+= 1;
			if ( p == pe )
			goto _test_eof182;
			st_case_182:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st179;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st175;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st175;
				}
			} else {
				goto st175;
			}
			{
				goto st0;
			}
			st183:
			p+= 1;
			if ( p == pe )
			goto _test_eof183;
			st_case_183:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st181;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st174;
				}
			} else {
				goto st174;
			}
			{
				goto st0;
			}
			st184:
			p+= 1;
			if ( p == pe )
			goto _test_eof184;
			st_case_184:
			switch( ( (*( p))) ) {
				case 58: {
					goto st111;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st174;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st174;
				}
			} else {
				goto st174;
			}
			{
				goto st0;
			}
			st185:
			p+= 1;
			if ( p == pe )
			goto _test_eof185;
			st_case_185:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st186;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st169;
				}
			} else {
				goto st169;
			}
			{
				goto st0;
			}
			st186:
			p+= 1;
			if ( p == pe )
			goto _test_eof186;
			st_case_186:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st187;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st170;
				}
			} else {
				goto st170;
			}
			{
				goto st0;
			}
			st187:
			p+= 1;
			if ( p == pe )
			goto _test_eof187;
			st_case_187:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st171;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st171;
				}
			} else {
				goto st171;
			}
			{
				goto st0;
			}
			st188:
			p+= 1;
			if ( p == pe )
			goto _test_eof188;
			st_case_188:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 53: {
					goto st190;
				}
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st189;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st169;
				}
			} else {
				goto st169;
			}
			{
				goto st0;
			}
			st189:
			p+= 1;
			if ( p == pe )
			goto _test_eof189;
			st_case_189:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st170;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st170;
				}
			} else {
				goto st170;
			}
			{
				goto st0;
			}
			st190:
			p+= 1;
			if ( p == pe )
			goto _test_eof190;
			st_case_190:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st187;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st170;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st170;
				}
			} else {
				goto st170;
			}
			{
				goto st0;
			}
			st191:
			p+= 1;
			if ( p == pe )
			goto _test_eof191;
			st_case_191:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st189;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st169;
				}
			} else {
				goto st169;
			}
			{
				goto st0;
			}
			st192:
			p+= 1;
			if ( p == pe )
			goto _test_eof192;
			st_case_192:
			switch( ( (*( p))) ) {
				case 58: {
					goto st172;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st169;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st169;
				}
			} else {
				goto st169;
			}
			{
				goto st0;
			}
			st193:
			p+= 1;
			if ( p == pe )
			goto _test_eof193;
			st_case_193:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st194;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st164;
				}
			} else {
				goto st164;
			}
			{
				goto st0;
			}
			st194:
			p+= 1;
			if ( p == pe )
			goto _test_eof194;
			st_case_194:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st195;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st165;
				}
			} else {
				goto st165;
			}
			{
				goto st0;
			}
			st195:
			p+= 1;
			if ( p == pe )
			goto _test_eof195;
			st_case_195:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st166;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st166;
				}
			} else {
				goto st166;
			}
			{
				goto st0;
			}
			st196:
			p+= 1;
			if ( p == pe )
			goto _test_eof196;
			st_case_196:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 53: {
					goto st198;
				}
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st197;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st164;
				}
			} else {
				goto st164;
			}
			{
				goto st0;
			}
			st197:
			p+= 1;
			if ( p == pe )
			goto _test_eof197;
			st_case_197:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st165;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st165;
				}
			} else {
				goto st165;
			}
			{
				goto st0;
			}
			st198:
			p+= 1;
			if ( p == pe )
			goto _test_eof198;
			st_case_198:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st195;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st165;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st165;
				}
			} else {
				goto st165;
			}
			{
				goto st0;
			}
			st199:
			p+= 1;
			if ( p == pe )
			goto _test_eof199;
			st_case_199:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st197;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st164;
				}
			} else {
				goto st164;
			}
			{
				goto st0;
			}
			st200:
			p+= 1;
			if ( p == pe )
			goto _test_eof200;
			st_case_200:
			switch( ( (*( p))) ) {
				case 58: {
					goto st167;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st164;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st164;
				}
			} else {
				goto st164;
			}
			{
				goto st0;
			}
			st201:
			p+= 1;
			if ( p == pe )
			goto _test_eof201;
			st_case_201:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st202;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st159;
				}
			} else {
				goto st159;
			}
			{
				goto st0;
			}
			st202:
			p+= 1;
			if ( p == pe )
			goto _test_eof202;
			st_case_202:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st203;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st160;
				}
			} else {
				goto st160;
			}
			{
				goto st0;
			}
			st203:
			p+= 1;
			if ( p == pe )
			goto _test_eof203;
			st_case_203:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st161;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st161;
				}
			} else {
				goto st161;
			}
			{
				goto st0;
			}
			st204:
			p+= 1;
			if ( p == pe )
			goto _test_eof204;
			st_case_204:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 53: {
					goto st206;
				}
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st205;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st159;
				}
			} else {
				goto st159;
			}
			{
				goto st0;
			}
			st205:
			p+= 1;
			if ( p == pe )
			goto _test_eof205;
			st_case_205:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st160;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st160;
				}
			} else {
				goto st160;
			}
			{
				goto st0;
			}
			st206:
			p+= 1;
			if ( p == pe )
			goto _test_eof206;
			st_case_206:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st203;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st160;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st160;
				}
			} else {
				goto st160;
			}
			{
				goto st0;
			}
			st207:
			p+= 1;
			if ( p == pe )
			goto _test_eof207;
			st_case_207:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st205;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st159;
				}
			} else {
				goto st159;
			}
			{
				goto st0;
			}
			st208:
			p+= 1;
			if ( p == pe )
			goto _test_eof208;
			st_case_208:
			switch( ( (*( p))) ) {
				case 58: {
					goto st162;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st159;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st159;
				}
			} else {
				goto st159;
			}
			{
				goto st0;
			}
			st209:
			p+= 1;
			if ( p == pe )
			goto _test_eof209;
			st_case_209:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st210;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st154;
				}
			} else {
				goto st154;
			}
			{
				goto st0;
			}
			st210:
			p+= 1;
			if ( p == pe )
			goto _test_eof210;
			st_case_210:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st211;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st155;
				}
			} else {
				goto st155;
			}
			{
				goto st0;
			}
			st211:
			p+= 1;
			if ( p == pe )
			goto _test_eof211;
			st_case_211:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st156;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st156;
				}
			} else {
				goto st156;
			}
			{
				goto st0;
			}
			st212:
			p+= 1;
			if ( p == pe )
			goto _test_eof212;
			st_case_212:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 53: {
					goto st214;
				}
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st213;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st154;
				}
			} else {
				goto st154;
			}
			{
				goto st0;
			}
			st213:
			p+= 1;
			if ( p == pe )
			goto _test_eof213;
			st_case_213:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st155;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st155;
				}
			} else {
				goto st155;
			}
			{
				goto st0;
			}
			st214:
			p+= 1;
			if ( p == pe )
			goto _test_eof214;
			st_case_214:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st211;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st155;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st155;
				}
			} else {
				goto st155;
			}
			{
				goto st0;
			}
			st215:
			p+= 1;
			if ( p == pe )
			goto _test_eof215;
			st_case_215:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st213;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st154;
				}
			} else {
				goto st154;
			}
			{
				goto st0;
			}
			st216:
			p+= 1;
			if ( p == pe )
			goto _test_eof216;
			st_case_216:
			switch( ( (*( p))) ) {
				case 58: {
					goto st157;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st154;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st154;
				}
			} else {
				goto st154;
			}
			{
				goto st0;
			}
			st217:
			p+= 1;
			if ( p == pe )
			goto _test_eof217;
			st_case_217:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st218;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st149;
				}
			} else {
				goto st149;
			}
			{
				goto st0;
			}
			st218:
			p+= 1;
			if ( p == pe )
			goto _test_eof218;
			st_case_218:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st219;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st150;
				}
			} else {
				goto st150;
			}
			{
				goto st0;
			}
			st219:
			p+= 1;
			if ( p == pe )
			goto _test_eof219;
			st_case_219:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st151;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st151;
				}
			} else {
				goto st151;
			}
			{
				goto st0;
			}
			st220:
			p+= 1;
			if ( p == pe )
			goto _test_eof220;
			st_case_220:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 53: {
					goto st222;
				}
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st221;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st149;
				}
			} else {
				goto st149;
			}
			{
				goto st0;
			}
			st221:
			p+= 1;
			if ( p == pe )
			goto _test_eof221;
			st_case_221:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st150;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st150;
				}
			} else {
				goto st150;
			}
			{
				goto st0;
			}
			st222:
			p+= 1;
			if ( p == pe )
			goto _test_eof222;
			st_case_222:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st219;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st150;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st150;
				}
			} else {
				goto st150;
			}
			{
				goto st0;
			}
			st223:
			p+= 1;
			if ( p == pe )
			goto _test_eof223;
			st_case_223:
			switch( ( (*( p))) ) {
				case 46: {
					goto st72;
				}
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st221;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st149;
				}
			} else {
				goto st149;
			}
			{
				goto st0;
			}
			st224:
			p+= 1;
			if ( p == pe )
			goto _test_eof224;
			st_case_224:
			switch( ( (*( p))) ) {
				case 58: {
					goto st152;
				}
				case 93: {
					goto st460;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st149;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st149;
				}
			} else {
				goto st149;
			}
			{
				goto st0;
			}
			st225:
			p+= 1;
			if ( p == pe )
			goto _test_eof225;
			st_case_225:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st226;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st226;
				}
			} else {
				goto st226;
			}
			{
				goto st0;
			}
			st226:
			p+= 1;
			if ( p == pe )
			goto _test_eof226;
			st_case_226:
			if ( ( (*( p))) == 46 ) {
				goto st227;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st226;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st226;
				}
			} else {
				goto st226;
			}
			{
				goto st0;
			}
			st227:
			p+= 1;
			if ( p == pe )
			goto _test_eof227;
			st_case_227:
			switch( ( (*( p))) ) {
				case 33: {
					goto st228;
				}
				case 36: {
					goto st228;
				}
				case 61: {
					goto st228;
				}
				case 95: {
					goto st228;
				}
				case 126: {
					goto st228;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 38 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st228;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st228;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st228;
				}
			} else {
				goto st228;
			}
			{
				goto st0;
			}
			st228:
			p+= 1;
			if ( p == pe )
			goto _test_eof228;
			st_case_228:
			switch( ( (*( p))) ) {
				case 33: {
					goto st228;
				}
				case 36: {
					goto st228;
				}
				case 61: {
					goto st228;
				}
				case 93: {
					goto st460;
				}
				case 95: {
					goto st228;
				}
				case 126: {
					goto st228;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 38 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st228;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st228;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st228;
				}
			} else {
				goto st228;
			}
			{
				goto st0;
			}
			ctr500:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st489;
			st489:
			p+= 1;
			if ( p == pe )
			goto _test_eof489;
			st_case_489:
			switch( ( (*( p))) ) {
				case 33: {
					goto st33;
				}
				case 35: {
					goto ctr493;
				}
				case 37: {
					goto st34;
				}
				case 47: {
					goto ctr494;
				}
				case 61: {
					goto st33;
				}
				case 63: {
					goto ctr496;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st33;
				}
				case 126: {
					goto st33;
				}
			}
			if ( ( (*( p))) < 58 ) {
				if ( ( (*( p))) > 46 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st489;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st33;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st33;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st33;
				}
			} else {
				goto st33;
			}
			{
				goto st0;
			}
			ctr477:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st490;
			st490:
			p+= 1;
			if ( p == pe )
			goto _test_eof490;
			st_case_490:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st491;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st467;
				}
			} else {
				goto st467;
			}
			{
				goto st0;
			}
			st491:
			p+= 1;
			if ( p == pe )
			goto _test_eof491;
			st_case_491:
			switch( ( (*( p))) ) {
				case 2: {
					goto st13;
				}
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 47: {
					goto ctr486;
				}
				case 48: {
					goto st492;
				}
				case 49: {
					goto st500;
				}
				case 50: {
					goto st502;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st501;
			}
			{
				goto st0;
			}
			st492:
			p+= 1;
			if ( p == pe )
			goto _test_eof492;
			st_case_492:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st493;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st467;
				}
			} else {
				goto st467;
			}
			{
				goto st0;
			}
			st493:
			p+= 1;
			if ( p == pe )
			goto _test_eof493;
			st_case_493:
			switch( ( (*( p))) ) {
				case 2: {
					goto st17;
				}
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 47: {
					goto ctr486;
				}
				case 48: {
					goto st494;
				}
				case 49: {
					goto st496;
				}
				case 50: {
					goto st498;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st497;
			}
			{
				goto st0;
			}
			st494:
			p+= 1;
			if ( p == pe )
			goto _test_eof494;
			st_case_494:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st495;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st467;
				}
			} else {
				goto st467;
			}
			{
				goto st0;
			}
			st495:
			p+= 1;
			if ( p == pe )
			goto _test_eof495;
			st_case_495:
			switch( ( (*( p))) ) {
				case 2: {
					goto st21;
				}
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st467;
				}
			} else {
				goto st467;
			}
			{
				goto st0;
			}
			st496:
			p+= 1;
			if ( p == pe )
			goto _test_eof496;
			st_case_496:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st495;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st497;
			}
			{
				goto st0;
			}
			st497:
			p+= 1;
			if ( p == pe )
			goto _test_eof497;
			st_case_497:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st495;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st494;
			}
			{
				goto st0;
			}
			st498:
			p+= 1;
			if ( p == pe )
			goto _test_eof498;
			st_case_498:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st495;
				}
				case 47: {
					goto ctr486;
				}
				case 53: {
					goto st499;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st494;
			}
			{
				goto st0;
			}
			st499:
			p+= 1;
			if ( p == pe )
			goto _test_eof499;
			st_case_499:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st495;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st494;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st467;
			}
			{
				goto st0;
			}
			st500:
			p+= 1;
			if ( p == pe )
			goto _test_eof500;
			st_case_500:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st493;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st501;
			}
			{
				goto st0;
			}
			st501:
			p+= 1;
			if ( p == pe )
			goto _test_eof501;
			st_case_501:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st493;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st492;
			}
			{
				goto st0;
			}
			st502:
			p+= 1;
			if ( p == pe )
			goto _test_eof502;
			st_case_502:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st493;
				}
				case 47: {
					goto ctr486;
				}
				case 53: {
					goto st503;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st492;
			}
			{
				goto st0;
			}
			st503:
			p+= 1;
			if ( p == pe )
			goto _test_eof503;
			st_case_503:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st493;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st492;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st467;
			}
			{
				goto st0;
			}
			ctr478:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st504;
			st504:
			p+= 1;
			if ( p == pe )
			goto _test_eof504;
			st_case_504:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st491;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st505;
			}
			{
				goto st0;
			}
			ctr480:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st505;
			st505:
			p+= 1;
			if ( p == pe )
			goto _test_eof505;
			st_case_505:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st491;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st490;
			}
			{
				goto st0;
			}
			ctr479:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st506;
			st506:
			p+= 1;
			if ( p == pe )
			goto _test_eof506;
			st_case_506:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st491;
				}
				case 47: {
					goto ctr486;
				}
				case 53: {
					goto st507;
				}
				case 58: {
					goto ctr499;
				}
				case 59: {
					goto st467;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st490;
			}
			{
				goto st0;
			}
			st507:
			p+= 1;
			if ( p == pe )
			goto _test_eof507;
			st_case_507:
			switch( ( (*( p))) ) {
				case 33: {
					goto st467;
				}
				case 35: {
					goto ctr485;
				}
				case 37: {
					goto st31;
				}
				case 46: {
					goto st491;
				}
				case 47: {
					goto ctr486;
				}
				case 58: {
					goto ctr499;
				}
				case 61: {
					goto st467;
				}
				case 63: {
					goto ctr488;
				}
				case 64: {
					goto ctr38;
				}
				case 95: {
					goto st467;
				}
				case 126: {
					goto st467;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st490;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st467;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st467;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st467;
				}
			} else {
				goto st467;
			}
			{
				goto st0;
			}
			ctr461:
			{
				#line 16 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st508;
			st508:
			p+= 1;
			if ( p == pe )
			goto _test_eof508;
			st_case_508:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto st453;
				}
				case 37: {
					goto st3;
				}
				case 43: {
					goto st508;
				}
				case 47: {
					goto st455;
				}
				case 58: {
					goto ctr543;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 63: {
					goto st456;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( ( (*( p))) > 32 ) {
					if ( 45 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto st508;
					}
				} else if ( ( (*( p))) >= 0 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( ( (*( p))) < 97 ) {
					if ( ( (*( p))) <= 94 ) {
						goto st0;
					}
				} else if ( ( (*( p))) > 122 ) {
					if ( ( (*( p))) <= 125 ) {
						goto st0;
					}
				} else {
					goto st508;
				}
			} else {
				goto st508;
			}
			{
				goto st452;
			}
			ctr543:
			{
				#line 19 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				uri->setScheme(std::string(mark, p - mark));
				mark = NULL;
			}
			
			goto st509;
			st509:
			p+= 1;
			if ( p == pe )
			goto _test_eof509;
			st_case_509:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto st453;
				}
				case 37: {
					goto st5;
				}
				case 47: {
					goto st510;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 63: {
					goto st456;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 91 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 94 ) {
				if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto st455;
			}
			st510:
			p+= 1;
			if ( p == pe )
			goto _test_eof510;
			st_case_510:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto st453;
				}
				case 37: {
					goto st5;
				}
				case 47: {
					goto st511;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 63: {
					goto st456;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 91 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 94 ) {
				if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto st455;
			}
			st511:
			p+= 1;
			if ( p == pe )
			goto _test_eof511;
			st_case_511:
			switch( ( (*( p))) ) {
				case 2: {
					goto ctr546;
				}
				case 33: {
					goto ctr547;
				}
				case 35: {
					goto ctr548;
				}
				case 37: {
					goto ctr549;
				}
				case 47: {
					goto ctr550;
				}
				case 48: {
					goto ctr551;
				}
				case 49: {
					goto ctr552;
				}
				case 50: {
					goto ctr553;
				}
				case 58: {
					goto ctr555;
				}
				case 59: {
					goto ctr547;
				}
				case 61: {
					goto ctr547;
				}
				case 63: {
					goto ctr556;
				}
				case 64: {
					goto ctr557;
				}
				case 91: {
					goto ctr558;
				}
				case 95: {
					goto ctr547;
				}
				case 126: {
					goto ctr547;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto ctr547;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto ctr547;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto ctr547;
				}
			} else {
				goto ctr554;
			}
			{
				goto st0;
			}
			ctr546:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st229;
			st229:
			p+= 1;
			if ( p == pe )
			goto _test_eof229;
			st_case_229:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st230;
			}
			{
				goto st0;
			}
			st230:
			p+= 1;
			if ( p == pe )
			goto _test_eof230;
			st_case_230:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st231;
			}
			{
				goto st0;
			}
			st231:
			p+= 1;
			if ( p == pe )
			goto _test_eof231;
			st_case_231:
			if ( ( (*( p))) == 46 ) {
				goto st232;
			}
			{
				goto st0;
			}
			st232:
			p+= 1;
			if ( p == pe )
			goto _test_eof232;
			st_case_232:
			switch( ( (*( p))) ) {
				case 2: {
					goto st233;
				}
				case 48: {
					goto st235;
				}
				case 49: {
					goto st249;
				}
				case 50: {
					goto st251;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st250;
			}
			{
				goto st0;
			}
			st233:
			p+= 1;
			if ( p == pe )
			goto _test_eof233;
			st_case_233:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st234;
			}
			{
				goto st0;
			}
			st234:
			p+= 1;
			if ( p == pe )
			goto _test_eof234;
			st_case_234:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st235;
			}
			{
				goto st0;
			}
			st235:
			p+= 1;
			if ( p == pe )
			goto _test_eof235;
			st_case_235:
			if ( ( (*( p))) == 46 ) {
				goto st236;
			}
			{
				goto st0;
			}
			st236:
			p+= 1;
			if ( p == pe )
			goto _test_eof236;
			st_case_236:
			switch( ( (*( p))) ) {
				case 2: {
					goto st237;
				}
				case 48: {
					goto st239;
				}
				case 49: {
					goto st245;
				}
				case 50: {
					goto st247;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st246;
			}
			{
				goto st0;
			}
			st237:
			p+= 1;
			if ( p == pe )
			goto _test_eof237;
			st_case_237:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st238;
			}
			{
				goto st0;
			}
			st238:
			p+= 1;
			if ( p == pe )
			goto _test_eof238;
			st_case_238:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st239;
			}
			{
				goto st0;
			}
			st239:
			p+= 1;
			if ( p == pe )
			goto _test_eof239;
			st_case_239:
			if ( ( (*( p))) == 46 ) {
				goto st240;
			}
			{
				goto st0;
			}
			st240:
			p+= 1;
			if ( p == pe )
			goto _test_eof240;
			st_case_240:
			switch( ( (*( p))) ) {
				case 2: {
					goto st241;
				}
				case 48: {
					goto st512;
				}
				case 49: {
					goto st516;
				}
				case 50: {
					goto st518;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st517;
			}
			{
				goto st0;
			}
			st241:
			p+= 1;
			if ( p == pe )
			goto _test_eof241;
			st_case_241:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st242;
			}
			{
				goto st0;
			}
			st242:
			p+= 1;
			if ( p == pe )
			goto _test_eof242;
			st_case_242:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st512;
			}
			{
				goto st0;
			}
			st512:
			p+= 1;
			if ( p == pe )
			goto _test_eof512;
			st_case_512:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr559;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 63: {
					goto ctr562;
				}
			}
			{
				goto st0;
			}
			ctr550:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st513;
			ctr567:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			
			goto st513;
			ctr560:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st513;
			ctr571:
			{
				#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (p != mark) {
					uri->setPort(atoi(mark));
				}
				mark = NULL;
			}
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st513;
			st513:
			p+= 1;
			if ( p == pe )
			goto _test_eof513;
			st_case_513:
			switch( ( (*( p))) ) {
				case 34: {
					goto st0;
				}
				case 35: {
					goto ctr563;
				}
				case 37: {
					goto st243;
				}
				case 60: {
					goto st0;
				}
				case 62: {
					goto st0;
				}
				case 63: {
					goto ctr565;
				}
				case 96: {
					goto st0;
				}
				case 127: {
					goto st0;
				}
			}
			if ( ( (*( p))) < 91 ) {
				if ( 0 <= ( (*( p))) && ( (*( p))) <= 32 ) {
					goto st0;
				}
			} else if ( ( (*( p))) > 94 ) {
				if ( 123 <= ( (*( p))) && ( (*( p))) <= 125 ) {
					goto st0;
				}
			} else {
				goto st0;
			}
			{
				goto st513;
			}
			st243:
			p+= 1;
			if ( p == pe )
			goto _test_eof243;
			st_case_243:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st244;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st244;
				}
			} else {
				goto st244;
			}
			{
				goto st0;
			}
			st244:
			p+= 1;
			if ( p == pe )
			goto _test_eof244;
			st_case_244:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st513;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st513;
				}
			} else {
				goto st513;
			}
			{
				goto st0;
			}
			ctr584:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st514;
			ctr561:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st514;
			st514:
			p+= 1;
			if ( p == pe )
			goto _test_eof514;
			st_case_514:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr566;
				}
				case 47: {
					goto ctr567;
				}
				case 63: {
					goto ctr569;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto ctr568;
			}
			{
				goto st0;
			}
			ctr568:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st515;
			st515:
			p+= 1;
			if ( p == pe )
			goto _test_eof515;
			st_case_515:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr570;
				}
				case 47: {
					goto ctr571;
				}
				case 63: {
					goto ctr573;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st515;
			}
			{
				goto st0;
			}
			st516:
			p+= 1;
			if ( p == pe )
			goto _test_eof516;
			st_case_516:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr559;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 63: {
					goto ctr562;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st517;
			}
			{
				goto st0;
			}
			st517:
			p+= 1;
			if ( p == pe )
			goto _test_eof517;
			st_case_517:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr559;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 63: {
					goto ctr562;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st512;
			}
			{
				goto st0;
			}
			st518:
			p+= 1;
			if ( p == pe )
			goto _test_eof518;
			st_case_518:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr559;
				}
				case 47: {
					goto ctr560;
				}
				case 53: {
					goto st519;
				}
				case 58: {
					goto ctr561;
				}
				case 63: {
					goto ctr562;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st512;
			}
			{
				goto st0;
			}
			st519:
			p+= 1;
			if ( p == pe )
			goto _test_eof519;
			st_case_519:
			switch( ( (*( p))) ) {
				case 35: {
					goto ctr559;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 63: {
					goto ctr562;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st512;
			}
			{
				goto st0;
			}
			st245:
			p+= 1;
			if ( p == pe )
			goto _test_eof245;
			st_case_245:
			if ( ( (*( p))) == 46 ) {
				goto st240;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st246;
			}
			{
				goto st0;
			}
			st246:
			p+= 1;
			if ( p == pe )
			goto _test_eof246;
			st_case_246:
			if ( ( (*( p))) == 46 ) {
				goto st240;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st239;
			}
			{
				goto st0;
			}
			st247:
			p+= 1;
			if ( p == pe )
			goto _test_eof247;
			st_case_247:
			switch( ( (*( p))) ) {
				case 46: {
					goto st240;
				}
				case 53: {
					goto st248;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st239;
			}
			{
				goto st0;
			}
			st248:
			p+= 1;
			if ( p == pe )
			goto _test_eof248;
			st_case_248:
			if ( ( (*( p))) == 46 ) {
				goto st240;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st239;
			}
			{
				goto st0;
			}
			st249:
			p+= 1;
			if ( p == pe )
			goto _test_eof249;
			st_case_249:
			if ( ( (*( p))) == 46 ) {
				goto st236;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st250;
			}
			{
				goto st0;
			}
			st250:
			p+= 1;
			if ( p == pe )
			goto _test_eof250;
			st_case_250:
			if ( ( (*( p))) == 46 ) {
				goto st236;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st235;
			}
			{
				goto st0;
			}
			st251:
			p+= 1;
			if ( p == pe )
			goto _test_eof251;
			st_case_251:
			switch( ( (*( p))) ) {
				case 46: {
					goto st236;
				}
				case 53: {
					goto st252;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st235;
			}
			{
				goto st0;
			}
			st252:
			p+= 1;
			if ( p == pe )
			goto _test_eof252;
			st_case_252:
			if ( ( (*( p))) == 46 ) {
				goto st236;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st235;
			}
			{
				goto st0;
			}
			ctr547:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st520;
			st520:
			p+= 1;
			if ( p == pe )
			goto _test_eof520;
			st_case_520:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st520;
				}
			} else {
				goto st520;
			}
			{
				goto st0;
			}
			ctr549:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st253;
			st253:
			p+= 1;
			if ( p == pe )
			goto _test_eof253;
			st_case_253:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st254;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st254;
				}
			} else {
				goto st254;
			}
			{
				goto st0;
			}
			st254:
			p+= 1;
			if ( p == pe )
			goto _test_eof254;
			st_case_254:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st520;
				}
			} else {
				goto st520;
			}
			{
				goto st0;
			}
			ctr555:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st521;
			ctr576:
			{
				#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if (mark != NULL) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setHost(std::string(mark, p - mark));
				}
			}
			
			goto st521;
			st521:
			p+= 1;
			if ( p == pe )
			goto _test_eof521;
			st_case_521:
			switch( ( (*( p))) ) {
				case 33: {
					goto st255;
				}
				case 35: {
					goto ctr566;
				}
				case 37: {
					goto st256;
				}
				case 47: {
					goto ctr567;
				}
				case 61: {
					goto st255;
				}
				case 63: {
					goto ctr569;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st255;
				}
				case 126: {
					goto st255;
				}
			}
			if ( ( (*( p))) < 58 ) {
				if ( ( (*( p))) > 46 ) {
					if ( 48 <= ( (*( p))) ) {
						goto ctr577;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st255;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st255;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st255;
				}
			} else {
				goto st255;
			}
			{
				goto st0;
			}
			st255:
			p+= 1;
			if ( p == pe )
			goto _test_eof255;
			st_case_255:
			switch( ( (*( p))) ) {
				case 33: {
					goto st255;
				}
				case 37: {
					goto st256;
				}
				case 61: {
					goto st255;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st255;
				}
				case 126: {
					goto st255;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st255;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st255;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st255;
				}
			} else {
				goto st255;
			}
			{
				goto st0;
			}
			st256:
			p+= 1;
			if ( p == pe )
			goto _test_eof256;
			st_case_256:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st257;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st257;
				}
			} else {
				goto st257;
			}
			{
				goto st0;
			}
			st257:
			p+= 1;
			if ( p == pe )
			goto _test_eof257;
			st_case_257:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st255;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st255;
				}
			} else {
				goto st255;
			}
			{
				goto st0;
			}
			ctr263:
			{
				#line 34 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if(mark) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setUserinfo(std::string(mark, p - mark));
				}
				mark = NULL;
			}
			
			goto st522;
			ctr557:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			{
				#line 34 "/home/lighthouse/workspace/stone/src/uri.rl"
				
				if(mark) {
					//std::cout << std::string(mark, fpc - mark) << std::endl;
					uri->setUserinfo(std::string(mark, p - mark));
				}
				mark = NULL;
			}
			
			goto st522;
			st522:
			p+= 1;
			if ( p == pe )
			goto _test_eof522;
			st_case_522:
			switch( ( (*( p))) ) {
				case 2: {
					goto ctr546;
				}
				case 33: {
					goto ctr578;
				}
				case 35: {
					goto ctr548;
				}
				case 37: {
					goto ctr579;
				}
				case 47: {
					goto ctr550;
				}
				case 48: {
					goto ctr580;
				}
				case 49: {
					goto ctr581;
				}
				case 50: {
					goto ctr582;
				}
				case 58: {
					goto ctr584;
				}
				case 59: {
					goto ctr578;
				}
				case 61: {
					goto ctr578;
				}
				case 63: {
					goto ctr556;
				}
				case 91: {
					goto ctr558;
				}
				case 95: {
					goto ctr578;
				}
				case 126: {
					goto ctr578;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto ctr578;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto ctr578;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto ctr578;
				}
			} else {
				goto ctr583;
			}
			{
				goto st0;
			}
			ctr578:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st523;
			st523:
			p+= 1;
			if ( p == pe )
			goto _test_eof523;
			st_case_523:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st523;
				}
			} else {
				goto st523;
			}
			{
				goto st0;
			}
			ctr579:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st258;
			st258:
			p+= 1;
			if ( p == pe )
			goto _test_eof258;
			st_case_258:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st259;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st259;
				}
			} else {
				goto st259;
			}
			{
				goto st0;
			}
			st259:
			p+= 1;
			if ( p == pe )
			goto _test_eof259;
			st_case_259:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st523;
				}
			} else {
				goto st523;
			}
			{
				goto st0;
			}
			ctr580:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st524;
			st524:
			p+= 1;
			if ( p == pe )
			goto _test_eof524;
			st_case_524:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st525;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st523;
				}
			} else {
				goto st523;
			}
			{
				goto st0;
			}
			st525:
			p+= 1;
			if ( p == pe )
			goto _test_eof525;
			st_case_525:
			switch( ( (*( p))) ) {
				case 2: {
					goto st233;
				}
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 47: {
					goto ctr560;
				}
				case 48: {
					goto st526;
				}
				case 49: {
					goto st534;
				}
				case 50: {
					goto st536;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st535;
			}
			{
				goto st0;
			}
			st526:
			p+= 1;
			if ( p == pe )
			goto _test_eof526;
			st_case_526:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st527;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st523;
				}
			} else {
				goto st523;
			}
			{
				goto st0;
			}
			st527:
			p+= 1;
			if ( p == pe )
			goto _test_eof527;
			st_case_527:
			switch( ( (*( p))) ) {
				case 2: {
					goto st237;
				}
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 47: {
					goto ctr560;
				}
				case 48: {
					goto st528;
				}
				case 49: {
					goto st530;
				}
				case 50: {
					goto st532;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st531;
			}
			{
				goto st0;
			}
			st528:
			p+= 1;
			if ( p == pe )
			goto _test_eof528;
			st_case_528:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st529;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st523;
				}
			} else {
				goto st523;
			}
			{
				goto st0;
			}
			st529:
			p+= 1;
			if ( p == pe )
			goto _test_eof529;
			st_case_529:
			switch( ( (*( p))) ) {
				case 2: {
					goto st241;
				}
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st523;
				}
			} else {
				goto st523;
			}
			{
				goto st0;
			}
			st530:
			p+= 1;
			if ( p == pe )
			goto _test_eof530;
			st_case_530:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st529;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st531;
			}
			{
				goto st0;
			}
			st531:
			p+= 1;
			if ( p == pe )
			goto _test_eof531;
			st_case_531:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st529;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st528;
			}
			{
				goto st0;
			}
			st532:
			p+= 1;
			if ( p == pe )
			goto _test_eof532;
			st_case_532:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st529;
				}
				case 47: {
					goto ctr560;
				}
				case 53: {
					goto st533;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st528;
			}
			{
				goto st0;
			}
			st533:
			p+= 1;
			if ( p == pe )
			goto _test_eof533;
			st_case_533:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st529;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st528;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st523;
			}
			{
				goto st0;
			}
			st534:
			p+= 1;
			if ( p == pe )
			goto _test_eof534;
			st_case_534:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st527;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st535;
			}
			{
				goto st0;
			}
			st535:
			p+= 1;
			if ( p == pe )
			goto _test_eof535;
			st_case_535:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st527;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st526;
			}
			{
				goto st0;
			}
			st536:
			p+= 1;
			if ( p == pe )
			goto _test_eof536;
			st_case_536:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st527;
				}
				case 47: {
					goto ctr560;
				}
				case 53: {
					goto st537;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st526;
			}
			{
				goto st0;
			}
			st537:
			p+= 1;
			if ( p == pe )
			goto _test_eof537;
			st_case_537:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st527;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st526;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st523;
			}
			{
				goto st0;
			}
			ctr581:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st538;
			st538:
			p+= 1;
			if ( p == pe )
			goto _test_eof538;
			st_case_538:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st525;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st539;
			}
			{
				goto st0;
			}
			ctr583:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st539;
			st539:
			p+= 1;
			if ( p == pe )
			goto _test_eof539;
			st_case_539:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st525;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st524;
			}
			{
				goto st0;
			}
			ctr582:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st540;
			st540:
			p+= 1;
			if ( p == pe )
			goto _test_eof540;
			st_case_540:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st525;
				}
				case 47: {
					goto ctr560;
				}
				case 53: {
					goto st541;
				}
				case 58: {
					goto ctr561;
				}
				case 59: {
					goto st523;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st524;
			}
			{
				goto st0;
			}
			st541:
			p+= 1;
			if ( p == pe )
			goto _test_eof541;
			st_case_541:
			switch( ( (*( p))) ) {
				case 33: {
					goto st523;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st258;
				}
				case 46: {
					goto st525;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr561;
				}
				case 61: {
					goto st523;
				}
				case 63: {
					goto ctr562;
				}
				case 95: {
					goto st523;
				}
				case 126: {
					goto st523;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st524;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st523;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st523;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st523;
				}
			} else {
				goto st523;
			}
			{
				goto st0;
			}
			ctr558:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st260;
			st260:
			p+= 1;
			if ( p == pe )
			goto _test_eof260;
			st_case_260:
			switch( ( (*( p))) ) {
				case 58: {
					goto st368;
				}
				case 118: {
					goto st447;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st261;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st261;
				}
			} else {
				goto st261;
			}
			{
				goto st0;
			}
			st261:
			p+= 1;
			if ( p == pe )
			goto _test_eof261;
			st_case_261:
			if ( ( (*( p))) == 58 ) {
				goto st265;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st262;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st262;
				}
			} else {
				goto st262;
			}
			{
				goto st0;
			}
			st262:
			p+= 1;
			if ( p == pe )
			goto _test_eof262;
			st_case_262:
			if ( ( (*( p))) == 58 ) {
				goto st265;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st263;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st263;
				}
			} else {
				goto st263;
			}
			{
				goto st0;
			}
			st263:
			p+= 1;
			if ( p == pe )
			goto _test_eof263;
			st_case_263:
			if ( ( (*( p))) == 58 ) {
				goto st265;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st264;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st264;
				}
			} else {
				goto st264;
			}
			{
				goto st0;
			}
			st264:
			p+= 1;
			if ( p == pe )
			goto _test_eof264;
			st_case_264:
			if ( ( (*( p))) == 58 ) {
				goto st265;
			}
			{
				goto st0;
			}
			st265:
			p+= 1;
			if ( p == pe )
			goto _test_eof265;
			st_case_265:
			if ( ( (*( p))) == 58 ) {
				goto st363;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st266;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st266;
				}
			} else {
				goto st266;
			}
			{
				goto st0;
			}
			st266:
			p+= 1;
			if ( p == pe )
			goto _test_eof266;
			st_case_266:
			if ( ( (*( p))) == 58 ) {
				goto st270;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st267;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st267;
				}
			} else {
				goto st267;
			}
			{
				goto st0;
			}
			st267:
			p+= 1;
			if ( p == pe )
			goto _test_eof267;
			st_case_267:
			if ( ( (*( p))) == 58 ) {
				goto st270;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st268;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st268;
				}
			} else {
				goto st268;
			}
			{
				goto st0;
			}
			st268:
			p+= 1;
			if ( p == pe )
			goto _test_eof268;
			st_case_268:
			if ( ( (*( p))) == 58 ) {
				goto st270;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st269;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st269;
				}
			} else {
				goto st269;
			}
			{
				goto st0;
			}
			st269:
			p+= 1;
			if ( p == pe )
			goto _test_eof269;
			st_case_269:
			if ( ( (*( p))) == 58 ) {
				goto st270;
			}
			{
				goto st0;
			}
			st270:
			p+= 1;
			if ( p == pe )
			goto _test_eof270;
			st_case_270:
			if ( ( (*( p))) == 58 ) {
				goto st358;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st271;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st271;
				}
			} else {
				goto st271;
			}
			{
				goto st0;
			}
			st271:
			p+= 1;
			if ( p == pe )
			goto _test_eof271;
			st_case_271:
			if ( ( (*( p))) == 58 ) {
				goto st275;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st272;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st272;
				}
			} else {
				goto st272;
			}
			{
				goto st0;
			}
			st272:
			p+= 1;
			if ( p == pe )
			goto _test_eof272;
			st_case_272:
			if ( ( (*( p))) == 58 ) {
				goto st275;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st273;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st273;
				}
			} else {
				goto st273;
			}
			{
				goto st0;
			}
			st273:
			p+= 1;
			if ( p == pe )
			goto _test_eof273;
			st_case_273:
			if ( ( (*( p))) == 58 ) {
				goto st275;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st274;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st274;
				}
			} else {
				goto st274;
			}
			{
				goto st0;
			}
			st274:
			p+= 1;
			if ( p == pe )
			goto _test_eof274;
			st_case_274:
			if ( ( (*( p))) == 58 ) {
				goto st275;
			}
			{
				goto st0;
			}
			st275:
			p+= 1;
			if ( p == pe )
			goto _test_eof275;
			st_case_275:
			if ( ( (*( p))) == 58 ) {
				goto st353;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st276;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st276;
				}
			} else {
				goto st276;
			}
			{
				goto st0;
			}
			st276:
			p+= 1;
			if ( p == pe )
			goto _test_eof276;
			st_case_276:
			if ( ( (*( p))) == 58 ) {
				goto st280;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st277;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st277;
				}
			} else {
				goto st277;
			}
			{
				goto st0;
			}
			st277:
			p+= 1;
			if ( p == pe )
			goto _test_eof277;
			st_case_277:
			if ( ( (*( p))) == 58 ) {
				goto st280;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st278;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st278;
				}
			} else {
				goto st278;
			}
			{
				goto st0;
			}
			st278:
			p+= 1;
			if ( p == pe )
			goto _test_eof278;
			st_case_278:
			if ( ( (*( p))) == 58 ) {
				goto st280;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st279;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st279;
				}
			} else {
				goto st279;
			}
			{
				goto st0;
			}
			st279:
			p+= 1;
			if ( p == pe )
			goto _test_eof279;
			st_case_279:
			if ( ( (*( p))) == 58 ) {
				goto st280;
			}
			{
				goto st0;
			}
			st280:
			p+= 1;
			if ( p == pe )
			goto _test_eof280;
			st_case_280:
			if ( ( (*( p))) == 58 ) {
				goto st348;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st281;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st281;
				}
			} else {
				goto st281;
			}
			{
				goto st0;
			}
			st281:
			p+= 1;
			if ( p == pe )
			goto _test_eof281;
			st_case_281:
			if ( ( (*( p))) == 58 ) {
				goto st285;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st282;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st282;
				}
			} else {
				goto st282;
			}
			{
				goto st0;
			}
			st282:
			p+= 1;
			if ( p == pe )
			goto _test_eof282;
			st_case_282:
			if ( ( (*( p))) == 58 ) {
				goto st285;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st283;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st283;
				}
			} else {
				goto st283;
			}
			{
				goto st0;
			}
			st283:
			p+= 1;
			if ( p == pe )
			goto _test_eof283;
			st_case_283:
			if ( ( (*( p))) == 58 ) {
				goto st285;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st284;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st284;
				}
			} else {
				goto st284;
			}
			{
				goto st0;
			}
			st284:
			p+= 1;
			if ( p == pe )
			goto _test_eof284;
			st_case_284:
			if ( ( (*( p))) == 58 ) {
				goto st285;
			}
			{
				goto st0;
			}
			st285:
			p+= 1;
			if ( p == pe )
			goto _test_eof285;
			st_case_285:
			if ( ( (*( p))) == 58 ) {
				goto st335;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st286;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st286;
				}
			} else {
				goto st286;
			}
			{
				goto st0;
			}
			st286:
			p+= 1;
			if ( p == pe )
			goto _test_eof286;
			st_case_286:
			if ( ( (*( p))) == 58 ) {
				goto st290;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st287;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st287;
				}
			} else {
				goto st287;
			}
			{
				goto st0;
			}
			st287:
			p+= 1;
			if ( p == pe )
			goto _test_eof287;
			st_case_287:
			if ( ( (*( p))) == 58 ) {
				goto st290;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st288;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st288;
				}
			} else {
				goto st288;
			}
			{
				goto st0;
			}
			st288:
			p+= 1;
			if ( p == pe )
			goto _test_eof288;
			st_case_288:
			if ( ( (*( p))) == 58 ) {
				goto st290;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st289;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st289;
				}
			} else {
				goto st289;
			}
			{
				goto st0;
			}
			st289:
			p+= 1;
			if ( p == pe )
			goto _test_eof289;
			st_case_289:
			if ( ( (*( p))) == 58 ) {
				goto st290;
			}
			{
				goto st0;
			}
			st290:
			p+= 1;
			if ( p == pe )
			goto _test_eof290;
			st_case_290:
			switch( ( (*( p))) ) {
				case 2: {
					goto st291;
				}
				case 48: {
					goto st318;
				}
				case 49: {
					goto st326;
				}
				case 50: {
					goto st329;
				}
				case 58: {
					goto st333;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st332;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st334;
				}
			} else {
				goto st334;
			}
			{
				goto st0;
			}
			st291:
			p+= 1;
			if ( p == pe )
			goto _test_eof291;
			st_case_291:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st292;
			}
			{
				goto st0;
			}
			st292:
			p+= 1;
			if ( p == pe )
			goto _test_eof292;
			st_case_292:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st293;
			}
			{
				goto st0;
			}
			st293:
			p+= 1;
			if ( p == pe )
			goto _test_eof293;
			st_case_293:
			if ( ( (*( p))) == 46 ) {
				goto st294;
			}
			{
				goto st0;
			}
			st294:
			p+= 1;
			if ( p == pe )
			goto _test_eof294;
			st_case_294:
			switch( ( (*( p))) ) {
				case 2: {
					goto st295;
				}
				case 48: {
					goto st297;
				}
				case 49: {
					goto st314;
				}
				case 50: {
					goto st316;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st315;
			}
			{
				goto st0;
			}
			st295:
			p+= 1;
			if ( p == pe )
			goto _test_eof295;
			st_case_295:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st296;
			}
			{
				goto st0;
			}
			st296:
			p+= 1;
			if ( p == pe )
			goto _test_eof296;
			st_case_296:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st297;
			}
			{
				goto st0;
			}
			st297:
			p+= 1;
			if ( p == pe )
			goto _test_eof297;
			st_case_297:
			if ( ( (*( p))) == 46 ) {
				goto st298;
			}
			{
				goto st0;
			}
			st298:
			p+= 1;
			if ( p == pe )
			goto _test_eof298;
			st_case_298:
			switch( ( (*( p))) ) {
				case 2: {
					goto st299;
				}
				case 48: {
					goto st301;
				}
				case 49: {
					goto st310;
				}
				case 50: {
					goto st312;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st311;
			}
			{
				goto st0;
			}
			st299:
			p+= 1;
			if ( p == pe )
			goto _test_eof299;
			st_case_299:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st300;
			}
			{
				goto st0;
			}
			st300:
			p+= 1;
			if ( p == pe )
			goto _test_eof300;
			st_case_300:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st301;
			}
			{
				goto st0;
			}
			st301:
			p+= 1;
			if ( p == pe )
			goto _test_eof301;
			st_case_301:
			if ( ( (*( p))) == 46 ) {
				goto st302;
			}
			{
				goto st0;
			}
			st302:
			p+= 1;
			if ( p == pe )
			goto _test_eof302;
			st_case_302:
			switch( ( (*( p))) ) {
				case 2: {
					goto st303;
				}
				case 48: {
					goto st305;
				}
				case 49: {
					goto st306;
				}
				case 50: {
					goto st308;
				}
			}
			if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st307;
			}
			{
				goto st0;
			}
			st303:
			p+= 1;
			if ( p == pe )
			goto _test_eof303;
			st_case_303:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 52 ) {
				goto st304;
			}
			{
				goto st0;
			}
			st304:
			p+= 1;
			if ( p == pe )
			goto _test_eof304;
			st_case_304:
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st305;
			}
			{
				goto st0;
			}
			st305:
			p+= 1;
			if ( p == pe )
			goto _test_eof305;
			st_case_305:
			if ( ( (*( p))) == 93 ) {
				goto st512;
			}
			{
				goto st0;
			}
			st306:
			p+= 1;
			if ( p == pe )
			goto _test_eof306;
			st_case_306:
			if ( ( (*( p))) == 93 ) {
				goto st512;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st307;
			}
			{
				goto st0;
			}
			st307:
			p+= 1;
			if ( p == pe )
			goto _test_eof307;
			st_case_307:
			if ( ( (*( p))) == 93 ) {
				goto st512;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st305;
			}
			{
				goto st0;
			}
			st308:
			p+= 1;
			if ( p == pe )
			goto _test_eof308;
			st_case_308:
			switch( ( (*( p))) ) {
				case 53: {
					goto st309;
				}
				case 93: {
					goto st512;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st305;
			}
			{
				goto st0;
			}
			st309:
			p+= 1;
			if ( p == pe )
			goto _test_eof309;
			st_case_309:
			if ( ( (*( p))) == 93 ) {
				goto st512;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st305;
			}
			{
				goto st0;
			}
			st310:
			p+= 1;
			if ( p == pe )
			goto _test_eof310;
			st_case_310:
			if ( ( (*( p))) == 46 ) {
				goto st302;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st311;
			}
			{
				goto st0;
			}
			st311:
			p+= 1;
			if ( p == pe )
			goto _test_eof311;
			st_case_311:
			if ( ( (*( p))) == 46 ) {
				goto st302;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st301;
			}
			{
				goto st0;
			}
			st312:
			p+= 1;
			if ( p == pe )
			goto _test_eof312;
			st_case_312:
			switch( ( (*( p))) ) {
				case 46: {
					goto st302;
				}
				case 53: {
					goto st313;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st301;
			}
			{
				goto st0;
			}
			st313:
			p+= 1;
			if ( p == pe )
			goto _test_eof313;
			st_case_313:
			if ( ( (*( p))) == 46 ) {
				goto st302;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st301;
			}
			{
				goto st0;
			}
			st314:
			p+= 1;
			if ( p == pe )
			goto _test_eof314;
			st_case_314:
			if ( ( (*( p))) == 46 ) {
				goto st298;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st315;
			}
			{
				goto st0;
			}
			st315:
			p+= 1;
			if ( p == pe )
			goto _test_eof315;
			st_case_315:
			if ( ( (*( p))) == 46 ) {
				goto st298;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st297;
			}
			{
				goto st0;
			}
			st316:
			p+= 1;
			if ( p == pe )
			goto _test_eof316;
			st_case_316:
			switch( ( (*( p))) ) {
				case 46: {
					goto st298;
				}
				case 53: {
					goto st317;
				}
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto st297;
			}
			{
				goto st0;
			}
			st317:
			p+= 1;
			if ( p == pe )
			goto _test_eof317;
			st_case_317:
			if ( ( (*( p))) == 46 ) {
				goto st298;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 53 ) {
				goto st297;
			}
			{
				goto st0;
			}
			st318:
			p+= 1;
			if ( p == pe )
			goto _test_eof318;
			st_case_318:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st322;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st319;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st319;
				}
			} else {
				goto st319;
			}
			{
				goto st0;
			}
			st319:
			p+= 1;
			if ( p == pe )
			goto _test_eof319;
			st_case_319:
			if ( ( (*( p))) == 58 ) {
				goto st322;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st320;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st320;
				}
			} else {
				goto st320;
			}
			{
				goto st0;
			}
			st320:
			p+= 1;
			if ( p == pe )
			goto _test_eof320;
			st_case_320:
			if ( ( (*( p))) == 58 ) {
				goto st322;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st321;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st321;
				}
			} else {
				goto st321;
			}
			{
				goto st0;
			}
			st321:
			p+= 1;
			if ( p == pe )
			goto _test_eof321;
			st_case_321:
			if ( ( (*( p))) == 58 ) {
				goto st322;
			}
			{
				goto st0;
			}
			st322:
			p+= 1;
			if ( p == pe )
			goto _test_eof322;
			st_case_322:
			if ( ( (*( p))) == 58 ) {
				goto st305;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st323;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st323;
				}
			} else {
				goto st323;
			}
			{
				goto st0;
			}
			st323:
			p+= 1;
			if ( p == pe )
			goto _test_eof323;
			st_case_323:
			if ( ( (*( p))) == 93 ) {
				goto st512;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st324;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st324;
				}
			} else {
				goto st324;
			}
			{
				goto st0;
			}
			st324:
			p+= 1;
			if ( p == pe )
			goto _test_eof324;
			st_case_324:
			if ( ( (*( p))) == 93 ) {
				goto st512;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st325;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st325;
				}
			} else {
				goto st325;
			}
			{
				goto st0;
			}
			st325:
			p+= 1;
			if ( p == pe )
			goto _test_eof325;
			st_case_325:
			if ( ( (*( p))) == 93 ) {
				goto st512;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st305;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st305;
				}
			} else {
				goto st305;
			}
			{
				goto st0;
			}
			st326:
			p+= 1;
			if ( p == pe )
			goto _test_eof326;
			st_case_326:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st322;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st327;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st319;
				}
			} else {
				goto st319;
			}
			{
				goto st0;
			}
			st327:
			p+= 1;
			if ( p == pe )
			goto _test_eof327;
			st_case_327:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st322;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st328;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st320;
				}
			} else {
				goto st320;
			}
			{
				goto st0;
			}
			st328:
			p+= 1;
			if ( p == pe )
			goto _test_eof328;
			st_case_328:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st322;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st321;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st321;
				}
			} else {
				goto st321;
			}
			{
				goto st0;
			}
			st329:
			p+= 1;
			if ( p == pe )
			goto _test_eof329;
			st_case_329:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 53: {
					goto st331;
				}
				case 58: {
					goto st322;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st330;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st319;
				}
			} else {
				goto st319;
			}
			{
				goto st0;
			}
			st330:
			p+= 1;
			if ( p == pe )
			goto _test_eof330;
			st_case_330:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st322;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st320;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st320;
				}
			} else {
				goto st320;
			}
			{
				goto st0;
			}
			st331:
			p+= 1;
			if ( p == pe )
			goto _test_eof331;
			st_case_331:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st322;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st328;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st320;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st320;
				}
			} else {
				goto st320;
			}
			{
				goto st0;
			}
			st332:
			p+= 1;
			if ( p == pe )
			goto _test_eof332;
			st_case_332:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st322;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st330;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st319;
				}
			} else {
				goto st319;
			}
			{
				goto st0;
			}
			st333:
			p+= 1;
			if ( p == pe )
			goto _test_eof333;
			st_case_333:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st323;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st323;
				}
			} else {
				goto st323;
			}
			{
				goto st0;
			}
			st334:
			p+= 1;
			if ( p == pe )
			goto _test_eof334;
			st_case_334:
			if ( ( (*( p))) == 58 ) {
				goto st322;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st319;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st319;
				}
			} else {
				goto st319;
			}
			{
				goto st0;
			}
			st335:
			p+= 1;
			if ( p == pe )
			goto _test_eof335;
			st_case_335:
			switch( ( (*( p))) ) {
				case 2: {
					goto st291;
				}
				case 48: {
					goto st336;
				}
				case 49: {
					goto st340;
				}
				case 50: {
					goto st343;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st346;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st347;
				}
			} else {
				goto st347;
			}
			{
				goto st0;
			}
			st336:
			p+= 1;
			if ( p == pe )
			goto _test_eof336;
			st_case_336:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st337;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st337;
				}
			} else {
				goto st337;
			}
			{
				goto st0;
			}
			st337:
			p+= 1;
			if ( p == pe )
			goto _test_eof337;
			st_case_337:
			if ( ( (*( p))) == 58 ) {
				goto st333;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st338;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st338;
				}
			} else {
				goto st338;
			}
			{
				goto st0;
			}
			st338:
			p+= 1;
			if ( p == pe )
			goto _test_eof338;
			st_case_338:
			if ( ( (*( p))) == 58 ) {
				goto st333;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st339;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st339;
				}
			} else {
				goto st339;
			}
			{
				goto st0;
			}
			st339:
			p+= 1;
			if ( p == pe )
			goto _test_eof339;
			st_case_339:
			if ( ( (*( p))) == 58 ) {
				goto st333;
			}
			{
				goto st0;
			}
			st340:
			p+= 1;
			if ( p == pe )
			goto _test_eof340;
			st_case_340:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st341;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st337;
				}
			} else {
				goto st337;
			}
			{
				goto st0;
			}
			st341:
			p+= 1;
			if ( p == pe )
			goto _test_eof341;
			st_case_341:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st342;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st338;
				}
			} else {
				goto st338;
			}
			{
				goto st0;
			}
			st342:
			p+= 1;
			if ( p == pe )
			goto _test_eof342;
			st_case_342:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st339;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st339;
				}
			} else {
				goto st339;
			}
			{
				goto st0;
			}
			st343:
			p+= 1;
			if ( p == pe )
			goto _test_eof343;
			st_case_343:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 53: {
					goto st345;
				}
				case 58: {
					goto st333;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st344;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st337;
				}
			} else {
				goto st337;
			}
			{
				goto st0;
			}
			st344:
			p+= 1;
			if ( p == pe )
			goto _test_eof344;
			st_case_344:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st338;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st338;
				}
			} else {
				goto st338;
			}
			{
				goto st0;
			}
			st345:
			p+= 1;
			if ( p == pe )
			goto _test_eof345;
			st_case_345:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st342;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st338;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st338;
				}
			} else {
				goto st338;
			}
			{
				goto st0;
			}
			st346:
			p+= 1;
			if ( p == pe )
			goto _test_eof346;
			st_case_346:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st344;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st337;
				}
			} else {
				goto st337;
			}
			{
				goto st0;
			}
			st347:
			p+= 1;
			if ( p == pe )
			goto _test_eof347;
			st_case_347:
			if ( ( (*( p))) == 58 ) {
				goto st333;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st337;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st337;
				}
			} else {
				goto st337;
			}
			{
				goto st0;
			}
			st348:
			p+= 1;
			if ( p == pe )
			goto _test_eof348;
			st_case_348:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st349;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st349;
				}
			} else {
				goto st349;
			}
			{
				goto st0;
			}
			st349:
			p+= 1;
			if ( p == pe )
			goto _test_eof349;
			st_case_349:
			if ( ( (*( p))) == 58 ) {
				goto st335;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st350;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st350;
				}
			} else {
				goto st350;
			}
			{
				goto st0;
			}
			st350:
			p+= 1;
			if ( p == pe )
			goto _test_eof350;
			st_case_350:
			if ( ( (*( p))) == 58 ) {
				goto st335;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st351;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st351;
				}
			} else {
				goto st351;
			}
			{
				goto st0;
			}
			st351:
			p+= 1;
			if ( p == pe )
			goto _test_eof351;
			st_case_351:
			if ( ( (*( p))) == 58 ) {
				goto st335;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st352;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st352;
				}
			} else {
				goto st352;
			}
			{
				goto st0;
			}
			st352:
			p+= 1;
			if ( p == pe )
			goto _test_eof352;
			st_case_352:
			if ( ( (*( p))) == 58 ) {
				goto st335;
			}
			{
				goto st0;
			}
			st353:
			p+= 1;
			if ( p == pe )
			goto _test_eof353;
			st_case_353:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st354;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st354;
				}
			} else {
				goto st354;
			}
			{
				goto st0;
			}
			st354:
			p+= 1;
			if ( p == pe )
			goto _test_eof354;
			st_case_354:
			if ( ( (*( p))) == 58 ) {
				goto st348;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st355;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st355;
				}
			} else {
				goto st355;
			}
			{
				goto st0;
			}
			st355:
			p+= 1;
			if ( p == pe )
			goto _test_eof355;
			st_case_355:
			if ( ( (*( p))) == 58 ) {
				goto st348;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st356;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st356;
				}
			} else {
				goto st356;
			}
			{
				goto st0;
			}
			st356:
			p+= 1;
			if ( p == pe )
			goto _test_eof356;
			st_case_356:
			if ( ( (*( p))) == 58 ) {
				goto st348;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st357;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st357;
				}
			} else {
				goto st357;
			}
			{
				goto st0;
			}
			st357:
			p+= 1;
			if ( p == pe )
			goto _test_eof357;
			st_case_357:
			if ( ( (*( p))) == 58 ) {
				goto st348;
			}
			{
				goto st0;
			}
			st358:
			p+= 1;
			if ( p == pe )
			goto _test_eof358;
			st_case_358:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st359;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st359;
				}
			} else {
				goto st359;
			}
			{
				goto st0;
			}
			st359:
			p+= 1;
			if ( p == pe )
			goto _test_eof359;
			st_case_359:
			if ( ( (*( p))) == 58 ) {
				goto st353;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st360;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st360;
				}
			} else {
				goto st360;
			}
			{
				goto st0;
			}
			st360:
			p+= 1;
			if ( p == pe )
			goto _test_eof360;
			st_case_360:
			if ( ( (*( p))) == 58 ) {
				goto st353;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st361;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st361;
				}
			} else {
				goto st361;
			}
			{
				goto st0;
			}
			st361:
			p+= 1;
			if ( p == pe )
			goto _test_eof361;
			st_case_361:
			if ( ( (*( p))) == 58 ) {
				goto st353;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st362;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st362;
				}
			} else {
				goto st362;
			}
			{
				goto st0;
			}
			st362:
			p+= 1;
			if ( p == pe )
			goto _test_eof362;
			st_case_362:
			if ( ( (*( p))) == 58 ) {
				goto st353;
			}
			{
				goto st0;
			}
			st363:
			p+= 1;
			if ( p == pe )
			goto _test_eof363;
			st_case_363:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st364;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st364;
				}
			} else {
				goto st364;
			}
			{
				goto st0;
			}
			st364:
			p+= 1;
			if ( p == pe )
			goto _test_eof364;
			st_case_364:
			if ( ( (*( p))) == 58 ) {
				goto st358;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st365;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st365;
				}
			} else {
				goto st365;
			}
			{
				goto st0;
			}
			st365:
			p+= 1;
			if ( p == pe )
			goto _test_eof365;
			st_case_365:
			if ( ( (*( p))) == 58 ) {
				goto st358;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st366;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st366;
				}
			} else {
				goto st366;
			}
			{
				goto st0;
			}
			st366:
			p+= 1;
			if ( p == pe )
			goto _test_eof366;
			st_case_366:
			if ( ( (*( p))) == 58 ) {
				goto st358;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st367;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st367;
				}
			} else {
				goto st367;
			}
			{
				goto st0;
			}
			st367:
			p+= 1;
			if ( p == pe )
			goto _test_eof367;
			st_case_367:
			if ( ( (*( p))) == 58 ) {
				goto st358;
			}
			{
				goto st0;
			}
			st368:
			p+= 1;
			if ( p == pe )
			goto _test_eof368;
			st_case_368:
			if ( ( (*( p))) == 58 ) {
				goto st369;
			}
			{
				goto st0;
			}
			st369:
			p+= 1;
			if ( p == pe )
			goto _test_eof369;
			st_case_369:
			switch( ( (*( p))) ) {
				case 2: {
					goto st291;
				}
				case 48: {
					goto st370;
				}
				case 49: {
					goto st439;
				}
				case 50: {
					goto st442;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st445;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st446;
				}
			} else {
				goto st446;
			}
			{
				goto st0;
			}
			st370:
			p+= 1;
			if ( p == pe )
			goto _test_eof370;
			st_case_370:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st371;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st371;
				}
			} else {
				goto st371;
			}
			{
				goto st0;
			}
			st371:
			p+= 1;
			if ( p == pe )
			goto _test_eof371;
			st_case_371:
			switch( ( (*( p))) ) {
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st372;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st372;
				}
			} else {
				goto st372;
			}
			{
				goto st0;
			}
			st372:
			p+= 1;
			if ( p == pe )
			goto _test_eof372;
			st_case_372:
			switch( ( (*( p))) ) {
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st373;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st373;
				}
			} else {
				goto st373;
			}
			{
				goto st0;
			}
			st373:
			p+= 1;
			if ( p == pe )
			goto _test_eof373;
			st_case_373:
			switch( ( (*( p))) ) {
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			{
				goto st0;
			}
			st374:
			p+= 1;
			if ( p == pe )
			goto _test_eof374;
			st_case_374:
			switch( ( (*( p))) ) {
				case 2: {
					goto st291;
				}
				case 48: {
					goto st375;
				}
				case 49: {
					goto st431;
				}
				case 50: {
					goto st434;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st437;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st438;
				}
			} else {
				goto st438;
			}
			{
				goto st0;
			}
			st375:
			p+= 1;
			if ( p == pe )
			goto _test_eof375;
			st_case_375:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st376;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st376;
				}
			} else {
				goto st376;
			}
			{
				goto st0;
			}
			st376:
			p+= 1;
			if ( p == pe )
			goto _test_eof376;
			st_case_376:
			switch( ( (*( p))) ) {
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st377;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st377;
				}
			} else {
				goto st377;
			}
			{
				goto st0;
			}
			st377:
			p+= 1;
			if ( p == pe )
			goto _test_eof377;
			st_case_377:
			switch( ( (*( p))) ) {
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st378;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st378;
				}
			} else {
				goto st378;
			}
			{
				goto st0;
			}
			st378:
			p+= 1;
			if ( p == pe )
			goto _test_eof378;
			st_case_378:
			switch( ( (*( p))) ) {
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			{
				goto st0;
			}
			st379:
			p+= 1;
			if ( p == pe )
			goto _test_eof379;
			st_case_379:
			switch( ( (*( p))) ) {
				case 2: {
					goto st291;
				}
				case 48: {
					goto st380;
				}
				case 49: {
					goto st423;
				}
				case 50: {
					goto st426;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st429;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st430;
				}
			} else {
				goto st430;
			}
			{
				goto st0;
			}
			st380:
			p+= 1;
			if ( p == pe )
			goto _test_eof380;
			st_case_380:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st381;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st381;
				}
			} else {
				goto st381;
			}
			{
				goto st0;
			}
			st381:
			p+= 1;
			if ( p == pe )
			goto _test_eof381;
			st_case_381:
			switch( ( (*( p))) ) {
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st382;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st382;
				}
			} else {
				goto st382;
			}
			{
				goto st0;
			}
			st382:
			p+= 1;
			if ( p == pe )
			goto _test_eof382;
			st_case_382:
			switch( ( (*( p))) ) {
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st383;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st383;
				}
			} else {
				goto st383;
			}
			{
				goto st0;
			}
			st383:
			p+= 1;
			if ( p == pe )
			goto _test_eof383;
			st_case_383:
			switch( ( (*( p))) ) {
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			{
				goto st0;
			}
			st384:
			p+= 1;
			if ( p == pe )
			goto _test_eof384;
			st_case_384:
			switch( ( (*( p))) ) {
				case 2: {
					goto st291;
				}
				case 48: {
					goto st385;
				}
				case 49: {
					goto st415;
				}
				case 50: {
					goto st418;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st421;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st422;
				}
			} else {
				goto st422;
			}
			{
				goto st0;
			}
			st385:
			p+= 1;
			if ( p == pe )
			goto _test_eof385;
			st_case_385:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st386;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st386;
				}
			} else {
				goto st386;
			}
			{
				goto st0;
			}
			st386:
			p+= 1;
			if ( p == pe )
			goto _test_eof386;
			st_case_386:
			switch( ( (*( p))) ) {
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st387;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st387;
				}
			} else {
				goto st387;
			}
			{
				goto st0;
			}
			st387:
			p+= 1;
			if ( p == pe )
			goto _test_eof387;
			st_case_387:
			switch( ( (*( p))) ) {
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st388;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st388;
				}
			} else {
				goto st388;
			}
			{
				goto st0;
			}
			st388:
			p+= 1;
			if ( p == pe )
			goto _test_eof388;
			st_case_388:
			switch( ( (*( p))) ) {
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			{
				goto st0;
			}
			st389:
			p+= 1;
			if ( p == pe )
			goto _test_eof389;
			st_case_389:
			switch( ( (*( p))) ) {
				case 2: {
					goto st291;
				}
				case 48: {
					goto st390;
				}
				case 49: {
					goto st407;
				}
				case 50: {
					goto st410;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st413;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st414;
				}
			} else {
				goto st414;
			}
			{
				goto st0;
			}
			st390:
			p+= 1;
			if ( p == pe )
			goto _test_eof390;
			st_case_390:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st391;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st391;
				}
			} else {
				goto st391;
			}
			{
				goto st0;
			}
			st391:
			p+= 1;
			if ( p == pe )
			goto _test_eof391;
			st_case_391:
			switch( ( (*( p))) ) {
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st392;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st392;
				}
			} else {
				goto st392;
			}
			{
				goto st0;
			}
			st392:
			p+= 1;
			if ( p == pe )
			goto _test_eof392;
			st_case_392:
			switch( ( (*( p))) ) {
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st393;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st393;
				}
			} else {
				goto st393;
			}
			{
				goto st0;
			}
			st393:
			p+= 1;
			if ( p == pe )
			goto _test_eof393;
			st_case_393:
			switch( ( (*( p))) ) {
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			{
				goto st0;
			}
			st394:
			p+= 1;
			if ( p == pe )
			goto _test_eof394;
			st_case_394:
			switch( ( (*( p))) ) {
				case 2: {
					goto st291;
				}
				case 48: {
					goto st395;
				}
				case 49: {
					goto st399;
				}
				case 50: {
					goto st402;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 51 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st405;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st406;
				}
			} else {
				goto st406;
			}
			{
				goto st0;
			}
			st395:
			p+= 1;
			if ( p == pe )
			goto _test_eof395;
			st_case_395:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st396;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st396;
				}
			} else {
				goto st396;
			}
			{
				goto st0;
			}
			st396:
			p+= 1;
			if ( p == pe )
			goto _test_eof396;
			st_case_396:
			switch( ( (*( p))) ) {
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st397;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st397;
				}
			} else {
				goto st397;
			}
			{
				goto st0;
			}
			st397:
			p+= 1;
			if ( p == pe )
			goto _test_eof397;
			st_case_397:
			switch( ( (*( p))) ) {
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st398;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st398;
				}
			} else {
				goto st398;
			}
			{
				goto st0;
			}
			st398:
			p+= 1;
			if ( p == pe )
			goto _test_eof398;
			st_case_398:
			switch( ( (*( p))) ) {
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			{
				goto st0;
			}
			st399:
			p+= 1;
			if ( p == pe )
			goto _test_eof399;
			st_case_399:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st400;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st396;
				}
			} else {
				goto st396;
			}
			{
				goto st0;
			}
			st400:
			p+= 1;
			if ( p == pe )
			goto _test_eof400;
			st_case_400:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st401;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st397;
				}
			} else {
				goto st397;
			}
			{
				goto st0;
			}
			st401:
			p+= 1;
			if ( p == pe )
			goto _test_eof401;
			st_case_401:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st398;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st398;
				}
			} else {
				goto st398;
			}
			{
				goto st0;
			}
			st402:
			p+= 1;
			if ( p == pe )
			goto _test_eof402;
			st_case_402:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 53: {
					goto st404;
				}
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st403;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st396;
				}
			} else {
				goto st396;
			}
			{
				goto st0;
			}
			st403:
			p+= 1;
			if ( p == pe )
			goto _test_eof403;
			st_case_403:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st397;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st397;
				}
			} else {
				goto st397;
			}
			{
				goto st0;
			}
			st404:
			p+= 1;
			if ( p == pe )
			goto _test_eof404;
			st_case_404:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st401;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st397;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st397;
				}
			} else {
				goto st397;
			}
			{
				goto st0;
			}
			st405:
			p+= 1;
			if ( p == pe )
			goto _test_eof405;
			st_case_405:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st403;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st396;
				}
			} else {
				goto st396;
			}
			{
				goto st0;
			}
			st406:
			p+= 1;
			if ( p == pe )
			goto _test_eof406;
			st_case_406:
			switch( ( (*( p))) ) {
				case 58: {
					goto st333;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st396;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st396;
				}
			} else {
				goto st396;
			}
			{
				goto st0;
			}
			st407:
			p+= 1;
			if ( p == pe )
			goto _test_eof407;
			st_case_407:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st408;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st391;
				}
			} else {
				goto st391;
			}
			{
				goto st0;
			}
			st408:
			p+= 1;
			if ( p == pe )
			goto _test_eof408;
			st_case_408:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st409;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st392;
				}
			} else {
				goto st392;
			}
			{
				goto st0;
			}
			st409:
			p+= 1;
			if ( p == pe )
			goto _test_eof409;
			st_case_409:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st393;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st393;
				}
			} else {
				goto st393;
			}
			{
				goto st0;
			}
			st410:
			p+= 1;
			if ( p == pe )
			goto _test_eof410;
			st_case_410:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 53: {
					goto st412;
				}
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st411;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st391;
				}
			} else {
				goto st391;
			}
			{
				goto st0;
			}
			st411:
			p+= 1;
			if ( p == pe )
			goto _test_eof411;
			st_case_411:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st392;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st392;
				}
			} else {
				goto st392;
			}
			{
				goto st0;
			}
			st412:
			p+= 1;
			if ( p == pe )
			goto _test_eof412;
			st_case_412:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st409;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st392;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st392;
				}
			} else {
				goto st392;
			}
			{
				goto st0;
			}
			st413:
			p+= 1;
			if ( p == pe )
			goto _test_eof413;
			st_case_413:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st411;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st391;
				}
			} else {
				goto st391;
			}
			{
				goto st0;
			}
			st414:
			p+= 1;
			if ( p == pe )
			goto _test_eof414;
			st_case_414:
			switch( ( (*( p))) ) {
				case 58: {
					goto st394;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st391;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st391;
				}
			} else {
				goto st391;
			}
			{
				goto st0;
			}
			st415:
			p+= 1;
			if ( p == pe )
			goto _test_eof415;
			st_case_415:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st416;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st386;
				}
			} else {
				goto st386;
			}
			{
				goto st0;
			}
			st416:
			p+= 1;
			if ( p == pe )
			goto _test_eof416;
			st_case_416:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st417;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st387;
				}
			} else {
				goto st387;
			}
			{
				goto st0;
			}
			st417:
			p+= 1;
			if ( p == pe )
			goto _test_eof417;
			st_case_417:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st388;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st388;
				}
			} else {
				goto st388;
			}
			{
				goto st0;
			}
			st418:
			p+= 1;
			if ( p == pe )
			goto _test_eof418;
			st_case_418:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 53: {
					goto st420;
				}
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st419;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st386;
				}
			} else {
				goto st386;
			}
			{
				goto st0;
			}
			st419:
			p+= 1;
			if ( p == pe )
			goto _test_eof419;
			st_case_419:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st387;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st387;
				}
			} else {
				goto st387;
			}
			{
				goto st0;
			}
			st420:
			p+= 1;
			if ( p == pe )
			goto _test_eof420;
			st_case_420:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st417;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st387;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st387;
				}
			} else {
				goto st387;
			}
			{
				goto st0;
			}
			st421:
			p+= 1;
			if ( p == pe )
			goto _test_eof421;
			st_case_421:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st419;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st386;
				}
			} else {
				goto st386;
			}
			{
				goto st0;
			}
			st422:
			p+= 1;
			if ( p == pe )
			goto _test_eof422;
			st_case_422:
			switch( ( (*( p))) ) {
				case 58: {
					goto st389;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st386;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st386;
				}
			} else {
				goto st386;
			}
			{
				goto st0;
			}
			st423:
			p+= 1;
			if ( p == pe )
			goto _test_eof423;
			st_case_423:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st424;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st381;
				}
			} else {
				goto st381;
			}
			{
				goto st0;
			}
			st424:
			p+= 1;
			if ( p == pe )
			goto _test_eof424;
			st_case_424:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st425;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st382;
				}
			} else {
				goto st382;
			}
			{
				goto st0;
			}
			st425:
			p+= 1;
			if ( p == pe )
			goto _test_eof425;
			st_case_425:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st383;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st383;
				}
			} else {
				goto st383;
			}
			{
				goto st0;
			}
			st426:
			p+= 1;
			if ( p == pe )
			goto _test_eof426;
			st_case_426:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 53: {
					goto st428;
				}
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st427;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st381;
				}
			} else {
				goto st381;
			}
			{
				goto st0;
			}
			st427:
			p+= 1;
			if ( p == pe )
			goto _test_eof427;
			st_case_427:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st382;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st382;
				}
			} else {
				goto st382;
			}
			{
				goto st0;
			}
			st428:
			p+= 1;
			if ( p == pe )
			goto _test_eof428;
			st_case_428:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st425;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st382;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st382;
				}
			} else {
				goto st382;
			}
			{
				goto st0;
			}
			st429:
			p+= 1;
			if ( p == pe )
			goto _test_eof429;
			st_case_429:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st427;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st381;
				}
			} else {
				goto st381;
			}
			{
				goto st0;
			}
			st430:
			p+= 1;
			if ( p == pe )
			goto _test_eof430;
			st_case_430:
			switch( ( (*( p))) ) {
				case 58: {
					goto st384;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st381;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st381;
				}
			} else {
				goto st381;
			}
			{
				goto st0;
			}
			st431:
			p+= 1;
			if ( p == pe )
			goto _test_eof431;
			st_case_431:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st432;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st376;
				}
			} else {
				goto st376;
			}
			{
				goto st0;
			}
			st432:
			p+= 1;
			if ( p == pe )
			goto _test_eof432;
			st_case_432:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st433;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st377;
				}
			} else {
				goto st377;
			}
			{
				goto st0;
			}
			st433:
			p+= 1;
			if ( p == pe )
			goto _test_eof433;
			st_case_433:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st378;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st378;
				}
			} else {
				goto st378;
			}
			{
				goto st0;
			}
			st434:
			p+= 1;
			if ( p == pe )
			goto _test_eof434;
			st_case_434:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 53: {
					goto st436;
				}
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st435;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st376;
				}
			} else {
				goto st376;
			}
			{
				goto st0;
			}
			st435:
			p+= 1;
			if ( p == pe )
			goto _test_eof435;
			st_case_435:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st377;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st377;
				}
			} else {
				goto st377;
			}
			{
				goto st0;
			}
			st436:
			p+= 1;
			if ( p == pe )
			goto _test_eof436;
			st_case_436:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st433;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st377;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st377;
				}
			} else {
				goto st377;
			}
			{
				goto st0;
			}
			st437:
			p+= 1;
			if ( p == pe )
			goto _test_eof437;
			st_case_437:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st435;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st376;
				}
			} else {
				goto st376;
			}
			{
				goto st0;
			}
			st438:
			p+= 1;
			if ( p == pe )
			goto _test_eof438;
			st_case_438:
			switch( ( (*( p))) ) {
				case 58: {
					goto st379;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st376;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st376;
				}
			} else {
				goto st376;
			}
			{
				goto st0;
			}
			st439:
			p+= 1;
			if ( p == pe )
			goto _test_eof439;
			st_case_439:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st440;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st371;
				}
			} else {
				goto st371;
			}
			{
				goto st0;
			}
			st440:
			p+= 1;
			if ( p == pe )
			goto _test_eof440;
			st_case_440:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st441;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st372;
				}
			} else {
				goto st372;
			}
			{
				goto st0;
			}
			st441:
			p+= 1;
			if ( p == pe )
			goto _test_eof441;
			st_case_441:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st373;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st373;
				}
			} else {
				goto st373;
			}
			{
				goto st0;
			}
			st442:
			p+= 1;
			if ( p == pe )
			goto _test_eof442;
			st_case_442:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 53: {
					goto st444;
				}
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st443;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st371;
				}
			} else {
				goto st371;
			}
			{
				goto st0;
			}
			st443:
			p+= 1;
			if ( p == pe )
			goto _test_eof443;
			st_case_443:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st372;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st372;
				}
			} else {
				goto st372;
			}
			{
				goto st0;
			}
			st444:
			p+= 1;
			if ( p == pe )
			goto _test_eof444;
			st_case_444:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( 48 <= ( (*( p))) ) {
					goto st441;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 70 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
						goto st372;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st372;
				}
			} else {
				goto st372;
			}
			{
				goto st0;
			}
			st445:
			p+= 1;
			if ( p == pe )
			goto _test_eof445;
			st_case_445:
			switch( ( (*( p))) ) {
				case 46: {
					goto st294;
				}
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st443;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st371;
				}
			} else {
				goto st371;
			}
			{
				goto st0;
			}
			st446:
			p+= 1;
			if ( p == pe )
			goto _test_eof446;
			st_case_446:
			switch( ( (*( p))) ) {
				case 58: {
					goto st374;
				}
				case 93: {
					goto st512;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st371;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st371;
				}
			} else {
				goto st371;
			}
			{
				goto st0;
			}
			st447:
			p+= 1;
			if ( p == pe )
			goto _test_eof447;
			st_case_447:
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st448;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st448;
				}
			} else {
				goto st448;
			}
			{
				goto st0;
			}
			st448:
			p+= 1;
			if ( p == pe )
			goto _test_eof448;
			st_case_448:
			if ( ( (*( p))) == 46 ) {
				goto st449;
			}
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto st448;
				}
			} else if ( ( (*( p))) > 70 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 102 ) {
					goto st448;
				}
			} else {
				goto st448;
			}
			{
				goto st0;
			}
			st449:
			p+= 1;
			if ( p == pe )
			goto _test_eof449;
			st_case_449:
			switch( ( (*( p))) ) {
				case 33: {
					goto st450;
				}
				case 36: {
					goto st450;
				}
				case 61: {
					goto st450;
				}
				case 95: {
					goto st450;
				}
				case 126: {
					goto st450;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 38 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st450;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st450;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st450;
				}
			} else {
				goto st450;
			}
			{
				goto st0;
			}
			st450:
			p+= 1;
			if ( p == pe )
			goto _test_eof450;
			st_case_450:
			switch( ( (*( p))) ) {
				case 33: {
					goto st450;
				}
				case 36: {
					goto st450;
				}
				case 61: {
					goto st450;
				}
				case 93: {
					goto st512;
				}
				case 95: {
					goto st450;
				}
				case 126: {
					goto st450;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 38 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st450;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st450;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st450;
				}
			} else {
				goto st450;
			}
			{
				goto st0;
			}
			ctr577:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st542;
			st542:
			p+= 1;
			if ( p == pe )
			goto _test_eof542;
			st_case_542:
			switch( ( (*( p))) ) {
				case 33: {
					goto st255;
				}
				case 35: {
					goto ctr570;
				}
				case 37: {
					goto st256;
				}
				case 47: {
					goto ctr571;
				}
				case 61: {
					goto st255;
				}
				case 63: {
					goto ctr573;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st255;
				}
				case 126: {
					goto st255;
				}
			}
			if ( ( (*( p))) < 58 ) {
				if ( ( (*( p))) > 46 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st542;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st255;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st255;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st255;
				}
			} else {
				goto st255;
			}
			{
				goto st0;
			}
			ctr551:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st543;
			st543:
			p+= 1;
			if ( p == pe )
			goto _test_eof543;
			st_case_543:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st544;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st520;
				}
			} else {
				goto st520;
			}
			{
				goto st0;
			}
			st544:
			p+= 1;
			if ( p == pe )
			goto _test_eof544;
			st_case_544:
			switch( ( (*( p))) ) {
				case 2: {
					goto st233;
				}
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 47: {
					goto ctr560;
				}
				case 48: {
					goto st545;
				}
				case 49: {
					goto st553;
				}
				case 50: {
					goto st555;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st554;
			}
			{
				goto st0;
			}
			st545:
			p+= 1;
			if ( p == pe )
			goto _test_eof545;
			st_case_545:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st546;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st520;
				}
			} else {
				goto st520;
			}
			{
				goto st0;
			}
			st546:
			p+= 1;
			if ( p == pe )
			goto _test_eof546;
			st_case_546:
			switch( ( (*( p))) ) {
				case 2: {
					goto st237;
				}
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 47: {
					goto ctr560;
				}
				case 48: {
					goto st547;
				}
				case 49: {
					goto st549;
				}
				case 50: {
					goto st551;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 51 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 46 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st550;
			}
			{
				goto st0;
			}
			st547:
			p+= 1;
			if ( p == pe )
			goto _test_eof547;
			st_case_547:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st548;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st520;
				}
			} else {
				goto st520;
			}
			{
				goto st0;
			}
			st548:
			p+= 1;
			if ( p == pe )
			goto _test_eof548;
			st_case_548:
			switch( ( (*( p))) ) {
				case 2: {
					goto st241;
				}
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 65 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 59 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st520;
				}
			} else {
				goto st520;
			}
			{
				goto st0;
			}
			st549:
			p+= 1;
			if ( p == pe )
			goto _test_eof549;
			st_case_549:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st548;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st550;
			}
			{
				goto st0;
			}
			st550:
			p+= 1;
			if ( p == pe )
			goto _test_eof550;
			st_case_550:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st548;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st547;
			}
			{
				goto st0;
			}
			st551:
			p+= 1;
			if ( p == pe )
			goto _test_eof551;
			st_case_551:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st548;
				}
				case 47: {
					goto ctr560;
				}
				case 53: {
					goto st552;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st547;
			}
			{
				goto st0;
			}
			st552:
			p+= 1;
			if ( p == pe )
			goto _test_eof552;
			st_case_552:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st548;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st547;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st520;
			}
			{
				goto st0;
			}
			st553:
			p+= 1;
			if ( p == pe )
			goto _test_eof553;
			st_case_553:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st546;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st554;
			}
			{
				goto st0;
			}
			st554:
			p+= 1;
			if ( p == pe )
			goto _test_eof554;
			st_case_554:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st546;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st545;
			}
			{
				goto st0;
			}
			st555:
			p+= 1;
			if ( p == pe )
			goto _test_eof555;
			st_case_555:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st546;
				}
				case 47: {
					goto ctr560;
				}
				case 53: {
					goto st556;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st545;
			}
			{
				goto st0;
			}
			st556:
			p+= 1;
			if ( p == pe )
			goto _test_eof556;
			st_case_556:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st546;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st545;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st520;
			}
			{
				goto st0;
			}
			ctr552:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st557;
			st557:
			p+= 1;
			if ( p == pe )
			goto _test_eof557;
			st_case_557:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st544;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st558;
			}
			{
				goto st0;
			}
			ctr554:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st558;
			st558:
			p+= 1;
			if ( p == pe )
			goto _test_eof558;
			st_case_558:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st544;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st543;
			}
			{
				goto st0;
			}
			ctr553:
			{
				#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
				mark = p; }
			
			goto st559;
			st559:
			p+= 1;
			if ( p == pe )
			goto _test_eof559;
			st_case_559:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st544;
				}
				case 47: {
					goto ctr560;
				}
				case 53: {
					goto st560;
				}
				case 58: {
					goto ctr576;
				}
				case 59: {
					goto st520;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 48 ) {
				if ( 36 <= ( (*( p))) && ( (*( p))) <= 45 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 57 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st543;
			}
			{
				goto st0;
			}
			st560:
			p+= 1;
			if ( p == pe )
			goto _test_eof560;
			st_case_560:
			switch( ( (*( p))) ) {
				case 33: {
					goto st520;
				}
				case 35: {
					goto ctr559;
				}
				case 37: {
					goto st253;
				}
				case 46: {
					goto st544;
				}
				case 47: {
					goto ctr560;
				}
				case 58: {
					goto ctr576;
				}
				case 61: {
					goto st520;
				}
				case 63: {
					goto ctr562;
				}
				case 64: {
					goto ctr263;
				}
				case 95: {
					goto st520;
				}
				case 126: {
					goto st520;
				}
			}
			if ( ( (*( p))) < 54 ) {
				if ( ( (*( p))) > 45 ) {
					if ( 48 <= ( (*( p))) ) {
						goto st543;
					}
				} else if ( ( (*( p))) >= 36 ) {
					goto st520;
				}
			} else if ( ( (*( p))) > 59 ) {
				if ( ( (*( p))) > 90 ) {
					if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
						goto st520;
					}
				} else if ( ( (*( p))) >= 65 ) {
					goto st520;
				}
			} else {
				goto st520;
			}
			{
				goto st0;
			}
			st_out:
			_test_eof452: cs = 452; goto _test_eof; 
			_test_eof453: cs = 453; goto _test_eof; 
			_test_eof454: cs = 454; goto _test_eof; 
			_test_eof1: cs = 1; goto _test_eof; 
			_test_eof2: cs = 2; goto _test_eof; 
			_test_eof3: cs = 3; goto _test_eof; 
			_test_eof4: cs = 4; goto _test_eof; 
			_test_eof455: cs = 455; goto _test_eof; 
			_test_eof5: cs = 5; goto _test_eof; 
			_test_eof6: cs = 6; goto _test_eof; 
			_test_eof456: cs = 456; goto _test_eof; 
			_test_eof457: cs = 457; goto _test_eof; 
			_test_eof7: cs = 7; goto _test_eof; 
			_test_eof8: cs = 8; goto _test_eof; 
			_test_eof458: cs = 458; goto _test_eof; 
			_test_eof459: cs = 459; goto _test_eof; 
			_test_eof9: cs = 9; goto _test_eof; 
			_test_eof10: cs = 10; goto _test_eof; 
			_test_eof11: cs = 11; goto _test_eof; 
			_test_eof12: cs = 12; goto _test_eof; 
			_test_eof13: cs = 13; goto _test_eof; 
			_test_eof14: cs = 14; goto _test_eof; 
			_test_eof15: cs = 15; goto _test_eof; 
			_test_eof16: cs = 16; goto _test_eof; 
			_test_eof17: cs = 17; goto _test_eof; 
			_test_eof18: cs = 18; goto _test_eof; 
			_test_eof19: cs = 19; goto _test_eof; 
			_test_eof20: cs = 20; goto _test_eof; 
			_test_eof21: cs = 21; goto _test_eof; 
			_test_eof22: cs = 22; goto _test_eof; 
			_test_eof460: cs = 460; goto _test_eof; 
			_test_eof461: cs = 461; goto _test_eof; 
			_test_eof462: cs = 462; goto _test_eof; 
			_test_eof463: cs = 463; goto _test_eof; 
			_test_eof464: cs = 464; goto _test_eof; 
			_test_eof465: cs = 465; goto _test_eof; 
			_test_eof466: cs = 466; goto _test_eof; 
			_test_eof23: cs = 23; goto _test_eof; 
			_test_eof24: cs = 24; goto _test_eof; 
			_test_eof25: cs = 25; goto _test_eof; 
			_test_eof26: cs = 26; goto _test_eof; 
			_test_eof27: cs = 27; goto _test_eof; 
			_test_eof28: cs = 28; goto _test_eof; 
			_test_eof29: cs = 29; goto _test_eof; 
			_test_eof30: cs = 30; goto _test_eof; 
			_test_eof467: cs = 467; goto _test_eof; 
			_test_eof31: cs = 31; goto _test_eof; 
			_test_eof32: cs = 32; goto _test_eof; 
			_test_eof468: cs = 468; goto _test_eof; 
			_test_eof33: cs = 33; goto _test_eof; 
			_test_eof34: cs = 34; goto _test_eof; 
			_test_eof35: cs = 35; goto _test_eof; 
			_test_eof469: cs = 469; goto _test_eof; 
			_test_eof470: cs = 470; goto _test_eof; 
			_test_eof36: cs = 36; goto _test_eof; 
			_test_eof37: cs = 37; goto _test_eof; 
			_test_eof471: cs = 471; goto _test_eof; 
			_test_eof472: cs = 472; goto _test_eof; 
			_test_eof473: cs = 473; goto _test_eof; 
			_test_eof474: cs = 474; goto _test_eof; 
			_test_eof475: cs = 475; goto _test_eof; 
			_test_eof476: cs = 476; goto _test_eof; 
			_test_eof477: cs = 477; goto _test_eof; 
			_test_eof478: cs = 478; goto _test_eof; 
			_test_eof479: cs = 479; goto _test_eof; 
			_test_eof480: cs = 480; goto _test_eof; 
			_test_eof481: cs = 481; goto _test_eof; 
			_test_eof482: cs = 482; goto _test_eof; 
			_test_eof483: cs = 483; goto _test_eof; 
			_test_eof484: cs = 484; goto _test_eof; 
			_test_eof485: cs = 485; goto _test_eof; 
			_test_eof486: cs = 486; goto _test_eof; 
			_test_eof487: cs = 487; goto _test_eof; 
			_test_eof488: cs = 488; goto _test_eof; 
			_test_eof38: cs = 38; goto _test_eof; 
			_test_eof39: cs = 39; goto _test_eof; 
			_test_eof40: cs = 40; goto _test_eof; 
			_test_eof41: cs = 41; goto _test_eof; 
			_test_eof42: cs = 42; goto _test_eof; 
			_test_eof43: cs = 43; goto _test_eof; 
			_test_eof44: cs = 44; goto _test_eof; 
			_test_eof45: cs = 45; goto _test_eof; 
			_test_eof46: cs = 46; goto _test_eof; 
			_test_eof47: cs = 47; goto _test_eof; 
			_test_eof48: cs = 48; goto _test_eof; 
			_test_eof49: cs = 49; goto _test_eof; 
			_test_eof50: cs = 50; goto _test_eof; 
			_test_eof51: cs = 51; goto _test_eof; 
			_test_eof52: cs = 52; goto _test_eof; 
			_test_eof53: cs = 53; goto _test_eof; 
			_test_eof54: cs = 54; goto _test_eof; 
			_test_eof55: cs = 55; goto _test_eof; 
			_test_eof56: cs = 56; goto _test_eof; 
			_test_eof57: cs = 57; goto _test_eof; 
			_test_eof58: cs = 58; goto _test_eof; 
			_test_eof59: cs = 59; goto _test_eof; 
			_test_eof60: cs = 60; goto _test_eof; 
			_test_eof61: cs = 61; goto _test_eof; 
			_test_eof62: cs = 62; goto _test_eof; 
			_test_eof63: cs = 63; goto _test_eof; 
			_test_eof64: cs = 64; goto _test_eof; 
			_test_eof65: cs = 65; goto _test_eof; 
			_test_eof66: cs = 66; goto _test_eof; 
			_test_eof67: cs = 67; goto _test_eof; 
			_test_eof68: cs = 68; goto _test_eof; 
			_test_eof69: cs = 69; goto _test_eof; 
			_test_eof70: cs = 70; goto _test_eof; 
			_test_eof71: cs = 71; goto _test_eof; 
			_test_eof72: cs = 72; goto _test_eof; 
			_test_eof73: cs = 73; goto _test_eof; 
			_test_eof74: cs = 74; goto _test_eof; 
			_test_eof75: cs = 75; goto _test_eof; 
			_test_eof76: cs = 76; goto _test_eof; 
			_test_eof77: cs = 77; goto _test_eof; 
			_test_eof78: cs = 78; goto _test_eof; 
			_test_eof79: cs = 79; goto _test_eof; 
			_test_eof80: cs = 80; goto _test_eof; 
			_test_eof81: cs = 81; goto _test_eof; 
			_test_eof82: cs = 82; goto _test_eof; 
			_test_eof83: cs = 83; goto _test_eof; 
			_test_eof84: cs = 84; goto _test_eof; 
			_test_eof85: cs = 85; goto _test_eof; 
			_test_eof86: cs = 86; goto _test_eof; 
			_test_eof87: cs = 87; goto _test_eof; 
			_test_eof88: cs = 88; goto _test_eof; 
			_test_eof89: cs = 89; goto _test_eof; 
			_test_eof90: cs = 90; goto _test_eof; 
			_test_eof91: cs = 91; goto _test_eof; 
			_test_eof92: cs = 92; goto _test_eof; 
			_test_eof93: cs = 93; goto _test_eof; 
			_test_eof94: cs = 94; goto _test_eof; 
			_test_eof95: cs = 95; goto _test_eof; 
			_test_eof96: cs = 96; goto _test_eof; 
			_test_eof97: cs = 97; goto _test_eof; 
			_test_eof98: cs = 98; goto _test_eof; 
			_test_eof99: cs = 99; goto _test_eof; 
			_test_eof100: cs = 100; goto _test_eof; 
			_test_eof101: cs = 101; goto _test_eof; 
			_test_eof102: cs = 102; goto _test_eof; 
			_test_eof103: cs = 103; goto _test_eof; 
			_test_eof104: cs = 104; goto _test_eof; 
			_test_eof105: cs = 105; goto _test_eof; 
			_test_eof106: cs = 106; goto _test_eof; 
			_test_eof107: cs = 107; goto _test_eof; 
			_test_eof108: cs = 108; goto _test_eof; 
			_test_eof109: cs = 109; goto _test_eof; 
			_test_eof110: cs = 110; goto _test_eof; 
			_test_eof111: cs = 111; goto _test_eof; 
			_test_eof112: cs = 112; goto _test_eof; 
			_test_eof113: cs = 113; goto _test_eof; 
			_test_eof114: cs = 114; goto _test_eof; 
			_test_eof115: cs = 115; goto _test_eof; 
			_test_eof116: cs = 116; goto _test_eof; 
			_test_eof117: cs = 117; goto _test_eof; 
			_test_eof118: cs = 118; goto _test_eof; 
			_test_eof119: cs = 119; goto _test_eof; 
			_test_eof120: cs = 120; goto _test_eof; 
			_test_eof121: cs = 121; goto _test_eof; 
			_test_eof122: cs = 122; goto _test_eof; 
			_test_eof123: cs = 123; goto _test_eof; 
			_test_eof124: cs = 124; goto _test_eof; 
			_test_eof125: cs = 125; goto _test_eof; 
			_test_eof126: cs = 126; goto _test_eof; 
			_test_eof127: cs = 127; goto _test_eof; 
			_test_eof128: cs = 128; goto _test_eof; 
			_test_eof129: cs = 129; goto _test_eof; 
			_test_eof130: cs = 130; goto _test_eof; 
			_test_eof131: cs = 131; goto _test_eof; 
			_test_eof132: cs = 132; goto _test_eof; 
			_test_eof133: cs = 133; goto _test_eof; 
			_test_eof134: cs = 134; goto _test_eof; 
			_test_eof135: cs = 135; goto _test_eof; 
			_test_eof136: cs = 136; goto _test_eof; 
			_test_eof137: cs = 137; goto _test_eof; 
			_test_eof138: cs = 138; goto _test_eof; 
			_test_eof139: cs = 139; goto _test_eof; 
			_test_eof140: cs = 140; goto _test_eof; 
			_test_eof141: cs = 141; goto _test_eof; 
			_test_eof142: cs = 142; goto _test_eof; 
			_test_eof143: cs = 143; goto _test_eof; 
			_test_eof144: cs = 144; goto _test_eof; 
			_test_eof145: cs = 145; goto _test_eof; 
			_test_eof146: cs = 146; goto _test_eof; 
			_test_eof147: cs = 147; goto _test_eof; 
			_test_eof148: cs = 148; goto _test_eof; 
			_test_eof149: cs = 149; goto _test_eof; 
			_test_eof150: cs = 150; goto _test_eof; 
			_test_eof151: cs = 151; goto _test_eof; 
			_test_eof152: cs = 152; goto _test_eof; 
			_test_eof153: cs = 153; goto _test_eof; 
			_test_eof154: cs = 154; goto _test_eof; 
			_test_eof155: cs = 155; goto _test_eof; 
			_test_eof156: cs = 156; goto _test_eof; 
			_test_eof157: cs = 157; goto _test_eof; 
			_test_eof158: cs = 158; goto _test_eof; 
			_test_eof159: cs = 159; goto _test_eof; 
			_test_eof160: cs = 160; goto _test_eof; 
			_test_eof161: cs = 161; goto _test_eof; 
			_test_eof162: cs = 162; goto _test_eof; 
			_test_eof163: cs = 163; goto _test_eof; 
			_test_eof164: cs = 164; goto _test_eof; 
			_test_eof165: cs = 165; goto _test_eof; 
			_test_eof166: cs = 166; goto _test_eof; 
			_test_eof167: cs = 167; goto _test_eof; 
			_test_eof168: cs = 168; goto _test_eof; 
			_test_eof169: cs = 169; goto _test_eof; 
			_test_eof170: cs = 170; goto _test_eof; 
			_test_eof171: cs = 171; goto _test_eof; 
			_test_eof172: cs = 172; goto _test_eof; 
			_test_eof173: cs = 173; goto _test_eof; 
			_test_eof174: cs = 174; goto _test_eof; 
			_test_eof175: cs = 175; goto _test_eof; 
			_test_eof176: cs = 176; goto _test_eof; 
			_test_eof177: cs = 177; goto _test_eof; 
			_test_eof178: cs = 178; goto _test_eof; 
			_test_eof179: cs = 179; goto _test_eof; 
			_test_eof180: cs = 180; goto _test_eof; 
			_test_eof181: cs = 181; goto _test_eof; 
			_test_eof182: cs = 182; goto _test_eof; 
			_test_eof183: cs = 183; goto _test_eof; 
			_test_eof184: cs = 184; goto _test_eof; 
			_test_eof185: cs = 185; goto _test_eof; 
			_test_eof186: cs = 186; goto _test_eof; 
			_test_eof187: cs = 187; goto _test_eof; 
			_test_eof188: cs = 188; goto _test_eof; 
			_test_eof189: cs = 189; goto _test_eof; 
			_test_eof190: cs = 190; goto _test_eof; 
			_test_eof191: cs = 191; goto _test_eof; 
			_test_eof192: cs = 192; goto _test_eof; 
			_test_eof193: cs = 193; goto _test_eof; 
			_test_eof194: cs = 194; goto _test_eof; 
			_test_eof195: cs = 195; goto _test_eof; 
			_test_eof196: cs = 196; goto _test_eof; 
			_test_eof197: cs = 197; goto _test_eof; 
			_test_eof198: cs = 198; goto _test_eof; 
			_test_eof199: cs = 199; goto _test_eof; 
			_test_eof200: cs = 200; goto _test_eof; 
			_test_eof201: cs = 201; goto _test_eof; 
			_test_eof202: cs = 202; goto _test_eof; 
			_test_eof203: cs = 203; goto _test_eof; 
			_test_eof204: cs = 204; goto _test_eof; 
			_test_eof205: cs = 205; goto _test_eof; 
			_test_eof206: cs = 206; goto _test_eof; 
			_test_eof207: cs = 207; goto _test_eof; 
			_test_eof208: cs = 208; goto _test_eof; 
			_test_eof209: cs = 209; goto _test_eof; 
			_test_eof210: cs = 210; goto _test_eof; 
			_test_eof211: cs = 211; goto _test_eof; 
			_test_eof212: cs = 212; goto _test_eof; 
			_test_eof213: cs = 213; goto _test_eof; 
			_test_eof214: cs = 214; goto _test_eof; 
			_test_eof215: cs = 215; goto _test_eof; 
			_test_eof216: cs = 216; goto _test_eof; 
			_test_eof217: cs = 217; goto _test_eof; 
			_test_eof218: cs = 218; goto _test_eof; 
			_test_eof219: cs = 219; goto _test_eof; 
			_test_eof220: cs = 220; goto _test_eof; 
			_test_eof221: cs = 221; goto _test_eof; 
			_test_eof222: cs = 222; goto _test_eof; 
			_test_eof223: cs = 223; goto _test_eof; 
			_test_eof224: cs = 224; goto _test_eof; 
			_test_eof225: cs = 225; goto _test_eof; 
			_test_eof226: cs = 226; goto _test_eof; 
			_test_eof227: cs = 227; goto _test_eof; 
			_test_eof228: cs = 228; goto _test_eof; 
			_test_eof489: cs = 489; goto _test_eof; 
			_test_eof490: cs = 490; goto _test_eof; 
			_test_eof491: cs = 491; goto _test_eof; 
			_test_eof492: cs = 492; goto _test_eof; 
			_test_eof493: cs = 493; goto _test_eof; 
			_test_eof494: cs = 494; goto _test_eof; 
			_test_eof495: cs = 495; goto _test_eof; 
			_test_eof496: cs = 496; goto _test_eof; 
			_test_eof497: cs = 497; goto _test_eof; 
			_test_eof498: cs = 498; goto _test_eof; 
			_test_eof499: cs = 499; goto _test_eof; 
			_test_eof500: cs = 500; goto _test_eof; 
			_test_eof501: cs = 501; goto _test_eof; 
			_test_eof502: cs = 502; goto _test_eof; 
			_test_eof503: cs = 503; goto _test_eof; 
			_test_eof504: cs = 504; goto _test_eof; 
			_test_eof505: cs = 505; goto _test_eof; 
			_test_eof506: cs = 506; goto _test_eof; 
			_test_eof507: cs = 507; goto _test_eof; 
			_test_eof508: cs = 508; goto _test_eof; 
			_test_eof509: cs = 509; goto _test_eof; 
			_test_eof510: cs = 510; goto _test_eof; 
			_test_eof511: cs = 511; goto _test_eof; 
			_test_eof229: cs = 229; goto _test_eof; 
			_test_eof230: cs = 230; goto _test_eof; 
			_test_eof231: cs = 231; goto _test_eof; 
			_test_eof232: cs = 232; goto _test_eof; 
			_test_eof233: cs = 233; goto _test_eof; 
			_test_eof234: cs = 234; goto _test_eof; 
			_test_eof235: cs = 235; goto _test_eof; 
			_test_eof236: cs = 236; goto _test_eof; 
			_test_eof237: cs = 237; goto _test_eof; 
			_test_eof238: cs = 238; goto _test_eof; 
			_test_eof239: cs = 239; goto _test_eof; 
			_test_eof240: cs = 240; goto _test_eof; 
			_test_eof241: cs = 241; goto _test_eof; 
			_test_eof242: cs = 242; goto _test_eof; 
			_test_eof512: cs = 512; goto _test_eof; 
			_test_eof513: cs = 513; goto _test_eof; 
			_test_eof243: cs = 243; goto _test_eof; 
			_test_eof244: cs = 244; goto _test_eof; 
			_test_eof514: cs = 514; goto _test_eof; 
			_test_eof515: cs = 515; goto _test_eof; 
			_test_eof516: cs = 516; goto _test_eof; 
			_test_eof517: cs = 517; goto _test_eof; 
			_test_eof518: cs = 518; goto _test_eof; 
			_test_eof519: cs = 519; goto _test_eof; 
			_test_eof245: cs = 245; goto _test_eof; 
			_test_eof246: cs = 246; goto _test_eof; 
			_test_eof247: cs = 247; goto _test_eof; 
			_test_eof248: cs = 248; goto _test_eof; 
			_test_eof249: cs = 249; goto _test_eof; 
			_test_eof250: cs = 250; goto _test_eof; 
			_test_eof251: cs = 251; goto _test_eof; 
			_test_eof252: cs = 252; goto _test_eof; 
			_test_eof520: cs = 520; goto _test_eof; 
			_test_eof253: cs = 253; goto _test_eof; 
			_test_eof254: cs = 254; goto _test_eof; 
			_test_eof521: cs = 521; goto _test_eof; 
			_test_eof255: cs = 255; goto _test_eof; 
			_test_eof256: cs = 256; goto _test_eof; 
			_test_eof257: cs = 257; goto _test_eof; 
			_test_eof522: cs = 522; goto _test_eof; 
			_test_eof523: cs = 523; goto _test_eof; 
			_test_eof258: cs = 258; goto _test_eof; 
			_test_eof259: cs = 259; goto _test_eof; 
			_test_eof524: cs = 524; goto _test_eof; 
			_test_eof525: cs = 525; goto _test_eof; 
			_test_eof526: cs = 526; goto _test_eof; 
			_test_eof527: cs = 527; goto _test_eof; 
			_test_eof528: cs = 528; goto _test_eof; 
			_test_eof529: cs = 529; goto _test_eof; 
			_test_eof530: cs = 530; goto _test_eof; 
			_test_eof531: cs = 531; goto _test_eof; 
			_test_eof532: cs = 532; goto _test_eof; 
			_test_eof533: cs = 533; goto _test_eof; 
			_test_eof534: cs = 534; goto _test_eof; 
			_test_eof535: cs = 535; goto _test_eof; 
			_test_eof536: cs = 536; goto _test_eof; 
			_test_eof537: cs = 537; goto _test_eof; 
			_test_eof538: cs = 538; goto _test_eof; 
			_test_eof539: cs = 539; goto _test_eof; 
			_test_eof540: cs = 540; goto _test_eof; 
			_test_eof541: cs = 541; goto _test_eof; 
			_test_eof260: cs = 260; goto _test_eof; 
			_test_eof261: cs = 261; goto _test_eof; 
			_test_eof262: cs = 262; goto _test_eof; 
			_test_eof263: cs = 263; goto _test_eof; 
			_test_eof264: cs = 264; goto _test_eof; 
			_test_eof265: cs = 265; goto _test_eof; 
			_test_eof266: cs = 266; goto _test_eof; 
			_test_eof267: cs = 267; goto _test_eof; 
			_test_eof268: cs = 268; goto _test_eof; 
			_test_eof269: cs = 269; goto _test_eof; 
			_test_eof270: cs = 270; goto _test_eof; 
			_test_eof271: cs = 271; goto _test_eof; 
			_test_eof272: cs = 272; goto _test_eof; 
			_test_eof273: cs = 273; goto _test_eof; 
			_test_eof274: cs = 274; goto _test_eof; 
			_test_eof275: cs = 275; goto _test_eof; 
			_test_eof276: cs = 276; goto _test_eof; 
			_test_eof277: cs = 277; goto _test_eof; 
			_test_eof278: cs = 278; goto _test_eof; 
			_test_eof279: cs = 279; goto _test_eof; 
			_test_eof280: cs = 280; goto _test_eof; 
			_test_eof281: cs = 281; goto _test_eof; 
			_test_eof282: cs = 282; goto _test_eof; 
			_test_eof283: cs = 283; goto _test_eof; 
			_test_eof284: cs = 284; goto _test_eof; 
			_test_eof285: cs = 285; goto _test_eof; 
			_test_eof286: cs = 286; goto _test_eof; 
			_test_eof287: cs = 287; goto _test_eof; 
			_test_eof288: cs = 288; goto _test_eof; 
			_test_eof289: cs = 289; goto _test_eof; 
			_test_eof290: cs = 290; goto _test_eof; 
			_test_eof291: cs = 291; goto _test_eof; 
			_test_eof292: cs = 292; goto _test_eof; 
			_test_eof293: cs = 293; goto _test_eof; 
			_test_eof294: cs = 294; goto _test_eof; 
			_test_eof295: cs = 295; goto _test_eof; 
			_test_eof296: cs = 296; goto _test_eof; 
			_test_eof297: cs = 297; goto _test_eof; 
			_test_eof298: cs = 298; goto _test_eof; 
			_test_eof299: cs = 299; goto _test_eof; 
			_test_eof300: cs = 300; goto _test_eof; 
			_test_eof301: cs = 301; goto _test_eof; 
			_test_eof302: cs = 302; goto _test_eof; 
			_test_eof303: cs = 303; goto _test_eof; 
			_test_eof304: cs = 304; goto _test_eof; 
			_test_eof305: cs = 305; goto _test_eof; 
			_test_eof306: cs = 306; goto _test_eof; 
			_test_eof307: cs = 307; goto _test_eof; 
			_test_eof308: cs = 308; goto _test_eof; 
			_test_eof309: cs = 309; goto _test_eof; 
			_test_eof310: cs = 310; goto _test_eof; 
			_test_eof311: cs = 311; goto _test_eof; 
			_test_eof312: cs = 312; goto _test_eof; 
			_test_eof313: cs = 313; goto _test_eof; 
			_test_eof314: cs = 314; goto _test_eof; 
			_test_eof315: cs = 315; goto _test_eof; 
			_test_eof316: cs = 316; goto _test_eof; 
			_test_eof317: cs = 317; goto _test_eof; 
			_test_eof318: cs = 318; goto _test_eof; 
			_test_eof319: cs = 319; goto _test_eof; 
			_test_eof320: cs = 320; goto _test_eof; 
			_test_eof321: cs = 321; goto _test_eof; 
			_test_eof322: cs = 322; goto _test_eof; 
			_test_eof323: cs = 323; goto _test_eof; 
			_test_eof324: cs = 324; goto _test_eof; 
			_test_eof325: cs = 325; goto _test_eof; 
			_test_eof326: cs = 326; goto _test_eof; 
			_test_eof327: cs = 327; goto _test_eof; 
			_test_eof328: cs = 328; goto _test_eof; 
			_test_eof329: cs = 329; goto _test_eof; 
			_test_eof330: cs = 330; goto _test_eof; 
			_test_eof331: cs = 331; goto _test_eof; 
			_test_eof332: cs = 332; goto _test_eof; 
			_test_eof333: cs = 333; goto _test_eof; 
			_test_eof334: cs = 334; goto _test_eof; 
			_test_eof335: cs = 335; goto _test_eof; 
			_test_eof336: cs = 336; goto _test_eof; 
			_test_eof337: cs = 337; goto _test_eof; 
			_test_eof338: cs = 338; goto _test_eof; 
			_test_eof339: cs = 339; goto _test_eof; 
			_test_eof340: cs = 340; goto _test_eof; 
			_test_eof341: cs = 341; goto _test_eof; 
			_test_eof342: cs = 342; goto _test_eof; 
			_test_eof343: cs = 343; goto _test_eof; 
			_test_eof344: cs = 344; goto _test_eof; 
			_test_eof345: cs = 345; goto _test_eof; 
			_test_eof346: cs = 346; goto _test_eof; 
			_test_eof347: cs = 347; goto _test_eof; 
			_test_eof348: cs = 348; goto _test_eof; 
			_test_eof349: cs = 349; goto _test_eof; 
			_test_eof350: cs = 350; goto _test_eof; 
			_test_eof351: cs = 351; goto _test_eof; 
			_test_eof352: cs = 352; goto _test_eof; 
			_test_eof353: cs = 353; goto _test_eof; 
			_test_eof354: cs = 354; goto _test_eof; 
			_test_eof355: cs = 355; goto _test_eof; 
			_test_eof356: cs = 356; goto _test_eof; 
			_test_eof357: cs = 357; goto _test_eof; 
			_test_eof358: cs = 358; goto _test_eof; 
			_test_eof359: cs = 359; goto _test_eof; 
			_test_eof360: cs = 360; goto _test_eof; 
			_test_eof361: cs = 361; goto _test_eof; 
			_test_eof362: cs = 362; goto _test_eof; 
			_test_eof363: cs = 363; goto _test_eof; 
			_test_eof364: cs = 364; goto _test_eof; 
			_test_eof365: cs = 365; goto _test_eof; 
			_test_eof366: cs = 366; goto _test_eof; 
			_test_eof367: cs = 367; goto _test_eof; 
			_test_eof368: cs = 368; goto _test_eof; 
			_test_eof369: cs = 369; goto _test_eof; 
			_test_eof370: cs = 370; goto _test_eof; 
			_test_eof371: cs = 371; goto _test_eof; 
			_test_eof372: cs = 372; goto _test_eof; 
			_test_eof373: cs = 373; goto _test_eof; 
			_test_eof374: cs = 374; goto _test_eof; 
			_test_eof375: cs = 375; goto _test_eof; 
			_test_eof376: cs = 376; goto _test_eof; 
			_test_eof377: cs = 377; goto _test_eof; 
			_test_eof378: cs = 378; goto _test_eof; 
			_test_eof379: cs = 379; goto _test_eof; 
			_test_eof380: cs = 380; goto _test_eof; 
			_test_eof381: cs = 381; goto _test_eof; 
			_test_eof382: cs = 382; goto _test_eof; 
			_test_eof383: cs = 383; goto _test_eof; 
			_test_eof384: cs = 384; goto _test_eof; 
			_test_eof385: cs = 385; goto _test_eof; 
			_test_eof386: cs = 386; goto _test_eof; 
			_test_eof387: cs = 387; goto _test_eof; 
			_test_eof388: cs = 388; goto _test_eof; 
			_test_eof389: cs = 389; goto _test_eof; 
			_test_eof390: cs = 390; goto _test_eof; 
			_test_eof391: cs = 391; goto _test_eof; 
			_test_eof392: cs = 392; goto _test_eof; 
			_test_eof393: cs = 393; goto _test_eof; 
			_test_eof394: cs = 394; goto _test_eof; 
			_test_eof395: cs = 395; goto _test_eof; 
			_test_eof396: cs = 396; goto _test_eof; 
			_test_eof397: cs = 397; goto _test_eof; 
			_test_eof398: cs = 398; goto _test_eof; 
			_test_eof399: cs = 399; goto _test_eof; 
			_test_eof400: cs = 400; goto _test_eof; 
			_test_eof401: cs = 401; goto _test_eof; 
			_test_eof402: cs = 402; goto _test_eof; 
			_test_eof403: cs = 403; goto _test_eof; 
			_test_eof404: cs = 404; goto _test_eof; 
			_test_eof405: cs = 405; goto _test_eof; 
			_test_eof406: cs = 406; goto _test_eof; 
			_test_eof407: cs = 407; goto _test_eof; 
			_test_eof408: cs = 408; goto _test_eof; 
			_test_eof409: cs = 409; goto _test_eof; 
			_test_eof410: cs = 410; goto _test_eof; 
			_test_eof411: cs = 411; goto _test_eof; 
			_test_eof412: cs = 412; goto _test_eof; 
			_test_eof413: cs = 413; goto _test_eof; 
			_test_eof414: cs = 414; goto _test_eof; 
			_test_eof415: cs = 415; goto _test_eof; 
			_test_eof416: cs = 416; goto _test_eof; 
			_test_eof417: cs = 417; goto _test_eof; 
			_test_eof418: cs = 418; goto _test_eof; 
			_test_eof419: cs = 419; goto _test_eof; 
			_test_eof420: cs = 420; goto _test_eof; 
			_test_eof421: cs = 421; goto _test_eof; 
			_test_eof422: cs = 422; goto _test_eof; 
			_test_eof423: cs = 423; goto _test_eof; 
			_test_eof424: cs = 424; goto _test_eof; 
			_test_eof425: cs = 425; goto _test_eof; 
			_test_eof426: cs = 426; goto _test_eof; 
			_test_eof427: cs = 427; goto _test_eof; 
			_test_eof428: cs = 428; goto _test_eof; 
			_test_eof429: cs = 429; goto _test_eof; 
			_test_eof430: cs = 430; goto _test_eof; 
			_test_eof431: cs = 431; goto _test_eof; 
			_test_eof432: cs = 432; goto _test_eof; 
			_test_eof433: cs = 433; goto _test_eof; 
			_test_eof434: cs = 434; goto _test_eof; 
			_test_eof435: cs = 435; goto _test_eof; 
			_test_eof436: cs = 436; goto _test_eof; 
			_test_eof437: cs = 437; goto _test_eof; 
			_test_eof438: cs = 438; goto _test_eof; 
			_test_eof439: cs = 439; goto _test_eof; 
			_test_eof440: cs = 440; goto _test_eof; 
			_test_eof441: cs = 441; goto _test_eof; 
			_test_eof442: cs = 442; goto _test_eof; 
			_test_eof443: cs = 443; goto _test_eof; 
			_test_eof444: cs = 444; goto _test_eof; 
			_test_eof445: cs = 445; goto _test_eof; 
			_test_eof446: cs = 446; goto _test_eof; 
			_test_eof447: cs = 447; goto _test_eof; 
			_test_eof448: cs = 448; goto _test_eof; 
			_test_eof449: cs = 449; goto _test_eof; 
			_test_eof450: cs = 450; goto _test_eof; 
			_test_eof542: cs = 542; goto _test_eof; 
			_test_eof543: cs = 543; goto _test_eof; 
			_test_eof544: cs = 544; goto _test_eof; 
			_test_eof545: cs = 545; goto _test_eof; 
			_test_eof546: cs = 546; goto _test_eof; 
			_test_eof547: cs = 547; goto _test_eof; 
			_test_eof548: cs = 548; goto _test_eof; 
			_test_eof549: cs = 549; goto _test_eof; 
			_test_eof550: cs = 550; goto _test_eof; 
			_test_eof551: cs = 551; goto _test_eof; 
			_test_eof552: cs = 552; goto _test_eof; 
			_test_eof553: cs = 553; goto _test_eof; 
			_test_eof554: cs = 554; goto _test_eof; 
			_test_eof555: cs = 555; goto _test_eof; 
			_test_eof556: cs = 556; goto _test_eof; 
			_test_eof557: cs = 557; goto _test_eof; 
			_test_eof558: cs = 558; goto _test_eof; 
			_test_eof559: cs = 559; goto _test_eof; 
			_test_eof560: cs = 560; goto _test_eof; 
			
			_test_eof: {}
			if ( p == eof )
			{
				switch ( cs ) {
					case 462: 
					
					case 489: 
					{
						#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						if (p != mark) {
							uri->setPort(atoi(mark));
						}
						mark = NULL;
					}
					break;
					case 460: 
					
					case 463: 
					
					case 464: 
					
					case 465: 
					
					case 466: 
					
					case 467: 
					
					case 470: 
					
					case 471: 
					
					case 472: 
					
					case 473: 
					
					case 474: 
					
					case 475: 
					
					case 476: 
					
					case 477: 
					
					case 478: 
					
					case 479: 
					
					case 480: 
					
					case 481: 
					
					case 482: 
					
					case 483: 
					
					case 484: 
					
					case 485: 
					
					case 486: 
					
					case 487: 
					
					case 488: 
					
					case 490: 
					
					case 491: 
					
					case 492: 
					
					case 493: 
					
					case 494: 
					
					case 495: 
					
					case 496: 
					
					case 497: 
					
					case 498: 
					
					case 499: 
					
					case 500: 
					
					case 501: 
					
					case 502: 
					
					case 503: 
					
					case 504: 
					
					case 505: 
					
					case 506: 
					
					case 507: 
					{
						#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						if (mark != NULL) {
							//std::cout << std::string(mark, fpc - mark) << std::endl;
							uri->setHost(std::string(mark, p - mark));
						}
					}
					break;
					case 513: 
					{
						#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						//std::cout << std::string(mark, fpc - mark) << std::endl;
						uri->setPath(std::string(mark, p - mark));
						mark = NULL;
					}
					break;
					case 457: 
					{
						#line 103 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						//std::cout << std::string(mark, fpc - mark) << std::endl;
						uri->setQuery(std::string(mark, p - mark));
						mark = NULL;
					}
					break;
					case 454: 
					{
						#line 109 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						//std::cout << std::string(mark, fpc - mark) << std::endl;
						uri->setFragment(std::string(mark, p - mark));
						mark = NULL;
					}
					break;
					case 456: 
					{
						#line 16 "/home/lighthouse/workspace/stone/src/uri.rl"
						mark = p; }	{
						#line 103 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						//std::cout << std::string(mark, fpc - mark) << std::endl;
						uri->setQuery(std::string(mark, p - mark));
						mark = NULL;
					}
					break;
					case 453: 
					{
						#line 16 "/home/lighthouse/workspace/stone/src/uri.rl"
						mark = p; }	{
						#line 109 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						//std::cout << std::string(mark, fpc - mark) << std::endl;
						uri->setFragment(std::string(mark, p - mark));
						mark = NULL;
					}
					break;
					case 461: 
					
					case 468: 
					{
						#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
						mark = p; }	{
						#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						if (p != mark) {
							uri->setPort(atoi(mark));
						}
						mark = NULL;
					}
					break;
					case 459: 
					
					case 469: 
					{
						#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
						mark = p; }	{
						#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						if (mark != NULL) {
							//std::cout << std::string(mark, fpc - mark) << std::endl;
							uri->setHost(std::string(mark, p - mark));
						}
					}
					break;
					case 514: 
					
					case 521: 
					{
						#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
						mark = p; }	{
						#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						if (p != mark) {
							uri->setPort(atoi(mark));
						}
						mark = NULL;
					}	{
						#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						//std::cout << std::string(mark, fpc - mark) << std::endl;
						uri->setPath(std::string(mark, p - mark));
						mark = NULL;
					}
					break;
					case 511: 
					
					case 522: 
					{
						#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
						mark = p; }	{
						#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						if (mark != NULL) {
							//std::cout << std::string(mark, fpc - mark) << std::endl;
							uri->setHost(std::string(mark, p - mark));
						}
					}	{
						#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						//std::cout << std::string(mark, fpc - mark) << std::endl;
						uri->setPath(std::string(mark, p - mark));
						mark = NULL;
					}
					break;
					case 515: 
					
					case 542: 
					{
						#line 27 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						if (p != mark) {
							uri->setPort(atoi(mark));
						}
						mark = NULL;
					}	{
						#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
						mark = p; }	{
						#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						//std::cout << std::string(mark, fpc - mark) << std::endl;
						uri->setPath(std::string(mark, p - mark));
						mark = NULL;
					}
					break;
					case 512: 
					
					case 516: 
					
					case 517: 
					
					case 518: 
					
					case 519: 
					
					case 520: 
					
					case 523: 
					
					case 524: 
					
					case 525: 
					
					case 526: 
					
					case 527: 
					
					case 528: 
					
					case 529: 
					
					case 530: 
					
					case 531: 
					
					case 532: 
					
					case 533: 
					
					case 534: 
					
					case 535: 
					
					case 536: 
					
					case 537: 
					
					case 538: 
					
					case 539: 
					
					case 540: 
					
					case 541: 
					
					case 543: 
					
					case 544: 
					
					case 545: 
					
					case 546: 
					
					case 547: 
					
					case 548: 
					
					case 549: 
					
					case 550: 
					
					case 551: 
					
					case 552: 
					
					case 553: 
					
					case 554: 
					
					case 555: 
					
					case 556: 
					
					case 557: 
					
					case 558: 
					
					case 559: 
					
					case 560: 
					{
						#line 42 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						if (mark != NULL) {
							//std::cout << std::string(mark, fpc - mark) << std::endl;
							uri->setHost(std::string(mark, p - mark));
						}
					}	{
						#line 17 "/home/lighthouse/workspace/stone/src/uri.rl"
						mark = p; }	{
						#line 77 "/home/lighthouse/workspace/stone/src/uri.rl"
						
						//std::cout << std::string(mark, fpc - mark) << std::endl;
						uri->setPath(std::string(mark, p - mark));
						mark = NULL;
					}
					break;
				}
			}
			
			_out: {}
		}
		
		#line 143 "/home/lighthouse/workspace/stone/src/uri.rl"
		
		if(cs == uri_parser_error) {
			return nullptr;
		} else if(cs >= uri_parser_first_final) {
			return uri;
		}
		return nullptr;
	}
	
	Uri::Uri()
	:m_port(0) {
	}
	
	bool Uri::isDefaultPort() const {
		if(m_port == 0) {
			return true;
		}
		if(m_scheme == "http"
		|| m_scheme == "ws") {
			return m_port == 80;
		} else if(m_scheme == "https"
		|| m_scheme == "wss") {
			return m_port == 443;
		}
		return false;
	}
	
	const std::string& Uri::getPath() const {
		static std::string s_default_path = "/";
		return m_path.empty() ? s_default_path : m_path;
	}
	
	int32_t Uri::getPort() const {
		if(m_port) {
			return m_port;
		}
		if(m_scheme == "http"
		|| m_scheme == "ws") {
			return 80;
		} else if(m_scheme == "https"
		|| m_scheme == "wss") {
			return 443;
		}
		return m_port;
	}
	
	std::ostream& Uri::dump(std::ostream& os) const {
		os << m_scheme << "://"
		<< m_userinfo
		<< (m_userinfo.empty() ? "" : "@")
		<< m_host
		<< (isDefaultPort() ? "" : ":" + std::to_string(m_port))
		<< getPath()
		<< (m_query.empty() ? "" : "?")
		<< m_query
		<< (m_fragment.empty() ? "" : "#")
		<< m_fragment;
		return os;
	}
	
	std::string Uri::toString() const {
		std::stringstream ss;
		dump(ss);
		return ss.str();
	}
	
	Address::ptr Uri::createAddress() const {
		auto addr = Address::LookupAnyIPAddress(m_host);
		if(addr) {
			addr->setPort(getPort());
		}
		return addr;
	}
	
}
