#include <stdio.h>
#include "init.h"

unsigned long long int seed = 0ULL;

void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

const long int tf_0_var_2 = -1979527450031419668L;
unsigned long long int tf_0_var_4 = 8678657248933937785ULL;
const unsigned long long int tf_0_var_6 = 793821245291632231ULL;
const unsigned long long int tf_0_var_8 = 14514760208545996676ULL;
const unsigned long long int tf_0_var_10 = 1719106888524589476ULL;
const long int tf_0_var_12 = 3305268262460676724L;
unsigned long long int tf_0_var_14 = 2630229402932298573ULL;
const long int tf_0_var_16 = -6753638023230797200L;
const long int tf_0_var_18 = -3132243133764569570L;
const unsigned long long int tf_0_var_20 = 6713238710125223397ULL;
long int tf_0_var_22 = -1396992980362259139L;
const unsigned long int tf_0_var_24 = 12083678331329325905UL;
const unsigned long int tf_0_var_26 = 17962382741302018043UL;
unsigned long int tf_0_var_28 = 17597458950548392632UL;
const unsigned long long int tf_0_var_30 = 2259757936337435712ULL;
const long int tf_0_var_32 = 1497793670297020420L;
const unsigned long int tf_0_var_34 = 10727389337268944752UL;
long int tf_0_var_36 = -5883256210888249409L;
long int tf_0_var_38 = -3124464904885983472L;
unsigned long long int tf_0_var_40 = 16575560017606073789ULL;
unsigned long int tf_0_var_42 = 12019897541122957035UL;
const long int tf_0_var_44 = 5615780775298518833L;
const long int tf_0_var_46 = 7741471461940636706L;
unsigned long long int tf_0_var_48 = 12108807534313531292ULL;
long int tf_0_var_50 = -8507085693635238301L;
const unsigned long int tf_0_var_52 = 17315809859792617702UL;
unsigned long int tf_0_var_54 = 6604329486512434177UL;
unsigned long long int tf_0_var_56 = 9845581437857007979ULL;
const long int tf_0_var_58 = -2625732948785660854L;
unsigned long long int tf_0_var_60 = 5477195887156044766ULL;
const unsigned long long int tf_0_var_62 = 648122245929696925ULL;
unsigned long int tf_0_var_64 = 8725344359817345917UL;
const long int tf_0_var_66 = -8953261488496430055L;
unsigned long long int tf_0_var_68 = 8005068442370668890ULL;
unsigned long int tf_0_var_70 = 11750720712945929367UL;
long int tf_0_var_72 = -3103106244935144471L;
unsigned long int tf_0_var_74 = 7671628836858097621UL;
const long int tf_0_var_76 = 3709344198631038516L;
const unsigned long int tf_0_var_78 = 2605334118387233616UL;
const long int tf_0_var_80 = -4446352463944928636L;
const unsigned long int tf_0_var_82 = 705193778985994517UL;
unsigned long long int tf_0_var_84 = 5273878741447571767ULL;
const long int tf_0_var_86 = -8115467212031617350L;
const unsigned long long int tf_0_var_88 = 2665901566120858146ULL;
unsigned long int tf_0_var_90 = 5035196922585992608UL;
long int tf_0_var_92 = 1657053420426140421L;
const long int tf_0_var_94 = -4287926236913336263L;
unsigned long int tf_0_var_96 = 17536157182386244914UL;
unsigned long long int tf_0_var_98 = 12324372742490675187ULL;
long int tf_0_var_100 = 2838273635238369038L;
const unsigned long int tf_0_var_102 = 11305819573265896042UL;


unsigned long int tf_0_var_104 = 8089986385973226885UL;
unsigned long long int tf_0_var_106 = 11200811032511891342ULL;
unsigned long int tf_0_var_108 = 11305581522641616802UL;
unsigned long int tf_0_var_110 = 3650315366998980029UL;
unsigned long long int tf_0_var_112 = 15083998533026963263ULL;
unsigned long int tf_0_var_114 = 6571392390983102836UL;
unsigned long long int tf_0_var_116 = 4892457525869260370ULL;
long int tf_0_var_118 = 3544006714503050208L;
long int tf_0_var_120 = -5040359118559665435L;
unsigned long long int tf_0_var_122 = 9557241681048479738ULL;
long int tf_0_var_124 = 5047520338089695982L;
unsigned long int tf_0_var_126 = 1466458639361980408UL;
unsigned long int tf_0_var_128 = 8391097982383459671UL;
long int tf_0_var_130 = -3915564513295849820L;
long int tf_0_var_132 = -1918916868358377458L;
unsigned long int tf_0_var_134 = 14946445810096501877UL;
unsigned long int tf_0_var_136 = 15873069687769724299UL;
long int tf_0_var_138 = 2330943552194250537L;
unsigned long long int tf_0_var_140 = 6685531083157246032ULL;
unsigned long long int tf_0_var_142 = 1846868505698396209ULL;
unsigned long long int tf_0_var_144 = 4748315609957942490ULL;
unsigned long int tf_0_var_146 = 103856571359383442UL;
unsigned long int tf_0_var_148 = 935277177918566514UL;
unsigned long int tf_0_var_150 = 11928617798040216740UL;


long int tf_0_var_224 = -1791851947510248812L;
unsigned long int tf_0_var_232 = 11767169922971865295UL;
long int tf_0_var_278 = -422110025975989215L;
long int tf_0_var_310 = 67454478566747968L;
long int tf_0_var_432 = -4696795841154832113L;
unsigned long int tf_0_var_434 = 734881805879871140UL;
long int tf_0_var_450 = -4456380236223946028L;
unsigned long long int tf_0_var_592 = 10987456839732937120ULL;
unsigned long int tf_0_var_680 = 7390543677584526412UL;
unsigned long int tf_0_var_746 = 3153014069695230522UL;
unsigned long long int tf_0_var_802 = 5162761106893328232ULL;
long int tf_0_var_818 = -307057964425347881L;


tf_0_struct_1 tf_0_struct_obj_1;


tf_0_struct_1 tf_0_struct_obj_2;
tf_0_struct_1 tf_0_struct_obj_3;
tf_0_struct_1 tf_0_struct_obj_4;
tf_0_struct_1 tf_0_struct_obj_5;
tf_0_struct_1 tf_0_struct_obj_6;


tf_0_struct_1 tf_0_struct_obj_7;
tf_0_struct_1 tf_0_struct_obj_8;
tf_0_struct_1 tf_0_struct_obj_9;
tf_0_struct_1 tf_0_struct_obj_10;
tf_0_struct_1 tf_0_struct_obj_11;
tf_0_struct_1 tf_0_struct_obj_12;
tf_0_struct_1 tf_0_struct_obj_13;








const long int * tf_0_ptr_1 = &(tf_0_var_86);
unsigned long long int * tf_0_ptr_2 = &(tf_0_struct_obj_1.member_1_3);
const long int * * tf_0_ptr_3 = &(tf_0_ptr_1);
unsigned long long int * tf_0_ptr_4 = &(tf_0_var_84);
const unsigned long int * tf_0_ptr_5 = &(tf_0_var_78);
long int * tf_0_ptr_6 = &(tf_0_var_22);
const unsigned long long int * tf_0_ptr_7 = &(tf_0_var_10);


long int * tf_0_ptr_8 = &(tf_0_struct_obj_2.member_1_1);
long int * tf_0_ptr_9 = &(tf_0_struct_obj_5.member_1_1);


unsigned long long int * tf_0_ptr_10 = &(tf_0_struct_obj_12.member_1_3);
long int * tf_0_ptr_11 = &(tf_0_struct_obj_10.member_1_2);
unsigned long long int * tf_0_ptr_12 = &(tf_0_struct_obj_10.member_1_0);
long int * tf_0_ptr_13 = &(tf_0_struct_obj_10.member_1_2);
unsigned long long int * * tf_0_ptr_14 = &(tf_0_ptr_10);
unsigned long long int * tf_0_ptr_15 = &(tf_0_struct_obj_9.member_1_3);
long int * tf_0_ptr_16 = &(tf_0_struct_obj_7.member_1_1);
unsigned long long int * * tf_0_ptr_17 = &(tf_0_ptr_12);
unsigned long long int * tf_0_ptr_18 = &(tf_0_struct_obj_9.member_1_3);
unsigned long long int * tf_0_ptr_19 = &(tf_0_struct_obj_12.member_1_0);


unsigned long long int tf_0_struct_1::member_1_0 = 14335615812623277007ULL;
long int tf_0_struct_1::member_1_1 = 3182084475055500334L;



void tf_0_init () {
    tf_0_struct_obj_1.member_1_2 = (long int) (-4236195131962350299L);
    tf_0_struct_obj_1.member_1_3 = (unsigned long long int) (12313838156368384625ULL);
    tf_0_struct_obj_1.member_1_4 = (long int) (-640261L);
    tf_0_struct_obj_1.member_1_5 = (unsigned long long int) (2568565ULL);
    tf_0_struct_obj_1.member_1_6 = (unsigned long long int) (12785488828219474857ULL);
    tf_0_struct_obj_2.member_1_2 = (long int) (5382908247249615932L);
    tf_0_struct_obj_2.member_1_3 = (unsigned long long int) (11245145292707334051ULL);
    tf_0_struct_obj_2.member_1_4 = (long int) (64027L);
    tf_0_struct_obj_2.member_1_5 = (unsigned long long int) (6261833ULL);
    tf_0_struct_obj_2.member_1_6 = (unsigned long long int) (8878665732320280878ULL);
    tf_0_struct_obj_3.member_1_2 = (long int) (3112880253082767543L);
    tf_0_struct_obj_3.member_1_3 = (unsigned long long int) (10417943585967292192ULL);
    tf_0_struct_obj_3.member_1_4 = (long int) (-2019463L);
    tf_0_struct_obj_3.member_1_5 = (unsigned long long int) (91639391ULL);
    tf_0_struct_obj_3.member_1_6 = (unsigned long long int) (10182712692322253133ULL);
    tf_0_struct_obj_4.member_1_2 = (long int) (1985938550762741582L);
    tf_0_struct_obj_4.member_1_3 = (unsigned long long int) (4900701184761968975ULL);
    tf_0_struct_obj_4.member_1_4 = (long int) (98317L);
    tf_0_struct_obj_4.member_1_5 = (unsigned long long int) (132003412ULL);
    tf_0_struct_obj_4.member_1_6 = (unsigned long long int) (1040627226134195619ULL);
    tf_0_struct_obj_5.member_1_2 = (long int) (-3215993206540555734L);
    tf_0_struct_obj_5.member_1_3 = (unsigned long long int) (17377802345397224001ULL);
    tf_0_struct_obj_5.member_1_4 = (long int) (289971L);
    tf_0_struct_obj_5.member_1_5 = (unsigned long long int) (110429154ULL);
    tf_0_struct_obj_5.member_1_6 = (unsigned long long int) (3842240433475861297ULL);
    tf_0_struct_obj_6.member_1_2 = (long int) (8040505282175875637L);
    tf_0_struct_obj_6.member_1_3 = (unsigned long long int) (11959629837382535282ULL);
    tf_0_struct_obj_6.member_1_4 = (long int) (-922309L);
    tf_0_struct_obj_6.member_1_5 = (unsigned long long int) (68182143ULL);
    tf_0_struct_obj_6.member_1_6 = (unsigned long long int) (12085254792653192480ULL);
    tf_0_struct_obj_7.member_1_2 = (long int) (6882741597408509054L);
    tf_0_struct_obj_7.member_1_3 = (unsigned long long int) (11491094327011319242ULL);
    tf_0_struct_obj_7.member_1_4 = (long int) (-1390952L);
    tf_0_struct_obj_7.member_1_5 = (unsigned long long int) (9134575ULL);
    tf_0_struct_obj_7.member_1_6 = (unsigned long long int) (2226516489966318166ULL);
    tf_0_struct_obj_8.member_1_2 = (long int) (-3394443879923376873L);
    tf_0_struct_obj_8.member_1_3 = (unsigned long long int) (12273631520815317996ULL);
    tf_0_struct_obj_8.member_1_4 = (long int) (1926892L);
    tf_0_struct_obj_8.member_1_5 = (unsigned long long int) (10692506ULL);
    tf_0_struct_obj_8.member_1_6 = (unsigned long long int) (111868891817629538ULL);
    tf_0_struct_obj_9.member_1_2 = (long int) (58081910688515171L);
    tf_0_struct_obj_9.member_1_3 = (unsigned long long int) (12465619143263651920ULL);
    tf_0_struct_obj_9.member_1_4 = (long int) (1242391L);
    tf_0_struct_obj_9.member_1_5 = (unsigned long long int) (106952845ULL);
    tf_0_struct_obj_9.member_1_6 = (unsigned long long int) (7674860157936609241ULL);
    tf_0_struct_obj_10.member_1_2 = (long int) (4879110458397100764L);
    tf_0_struct_obj_10.member_1_3 = (unsigned long long int) (13188255634357635039ULL);
    tf_0_struct_obj_10.member_1_4 = (long int) (856938L);
    tf_0_struct_obj_10.member_1_5 = (unsigned long long int) (19317940ULL);
    tf_0_struct_obj_10.member_1_6 = (unsigned long long int) (17082873519000545175ULL);
    tf_0_struct_obj_11.member_1_2 = (long int) (5451850165125707091L);
    tf_0_struct_obj_11.member_1_3 = (unsigned long long int) (4553040990852036469ULL);
    tf_0_struct_obj_11.member_1_4 = (long int) (1620593L);
    tf_0_struct_obj_11.member_1_5 = (unsigned long long int) (20753905ULL);
    tf_0_struct_obj_11.member_1_6 = (unsigned long long int) (4888091195403619754ULL);
    tf_0_struct_obj_12.member_1_2 = (long int) (-2749174377673853496L);
    tf_0_struct_obj_12.member_1_3 = (unsigned long long int) (5237845749362459893ULL);
    tf_0_struct_obj_12.member_1_4 = (long int) (-1832516L);
    tf_0_struct_obj_12.member_1_5 = (unsigned long long int) (121651603ULL);
    tf_0_struct_obj_12.member_1_6 = (unsigned long long int) (9519798760727940493ULL);
    tf_0_struct_obj_13.member_1_2 = (long int) (-7998349947332269923L);
    tf_0_struct_obj_13.member_1_3 = (unsigned long long int) (11382233620173018465ULL);
    tf_0_struct_obj_13.member_1_4 = (long int) (506482L);
    tf_0_struct_obj_13.member_1_5 = (unsigned long long int) (104720663ULL);
    tf_0_struct_obj_13.member_1_6 = (unsigned long long int) (9062834475689285457ULL);
}

void tf_0_checksum () {
    hash(&seed, tf_0_struct_1::member_1_0);
    hash(&seed, tf_0_struct_1::member_1_1);

    hash(&seed, tf_0_var_104);
    hash(&seed, tf_0_var_106);
    hash(&seed, tf_0_var_108);
    hash(&seed, tf_0_var_110);
    hash(&seed, tf_0_var_112);
    hash(&seed, tf_0_var_114);
    hash(&seed, tf_0_var_116);
    hash(&seed, tf_0_var_118);
    hash(&seed, tf_0_var_120);
    hash(&seed, tf_0_var_122);
    hash(&seed, tf_0_var_124);
    hash(&seed, tf_0_var_126);
    hash(&seed, tf_0_var_128);
    hash(&seed, tf_0_var_130);
    hash(&seed, tf_0_var_132);
    hash(&seed, tf_0_var_134);
    hash(&seed, tf_0_var_136);
    hash(&seed, tf_0_var_138);
    hash(&seed, tf_0_var_140);
    hash(&seed, tf_0_var_142);
    hash(&seed, tf_0_var_144);
    hash(&seed, tf_0_var_146);
    hash(&seed, tf_0_var_148);
    hash(&seed, tf_0_var_150);
    hash(&seed, tf_0_var_224);
    hash(&seed, tf_0_var_232);
    hash(&seed, tf_0_var_278);
    hash(&seed, tf_0_var_310);
    hash(&seed, tf_0_var_432);
    hash(&seed, tf_0_var_434);
    hash(&seed, tf_0_var_450);
    hash(&seed, tf_0_var_592);
    hash(&seed, tf_0_var_680);
    hash(&seed, tf_0_var_746);
    hash(&seed, tf_0_var_802);
    hash(&seed, tf_0_var_818);
    hash(&seed, tf_0_struct_obj_2.member_1_2);
    hash(&seed, tf_0_struct_obj_2.member_1_3);
    hash(&seed, tf_0_struct_obj_2.member_1_4);
    hash(&seed, tf_0_struct_obj_2.member_1_5);
    hash(&seed, tf_0_struct_obj_2.member_1_6);
    hash(&seed, tf_0_struct_obj_3.member_1_2);
    hash(&seed, tf_0_struct_obj_3.member_1_3);
    hash(&seed, tf_0_struct_obj_3.member_1_4);
    hash(&seed, tf_0_struct_obj_3.member_1_5);
    hash(&seed, tf_0_struct_obj_3.member_1_6);
    hash(&seed, tf_0_struct_obj_4.member_1_2);
    hash(&seed, tf_0_struct_obj_4.member_1_3);
    hash(&seed, tf_0_struct_obj_4.member_1_4);
    hash(&seed, tf_0_struct_obj_4.member_1_5);
    hash(&seed, tf_0_struct_obj_4.member_1_6);
    hash(&seed, tf_0_struct_obj_5.member_1_2);
    hash(&seed, tf_0_struct_obj_5.member_1_3);
    hash(&seed, tf_0_struct_obj_5.member_1_4);
    hash(&seed, tf_0_struct_obj_5.member_1_5);
    hash(&seed, tf_0_struct_obj_5.member_1_6);
    hash(&seed, tf_0_struct_obj_6.member_1_2);
    hash(&seed, tf_0_struct_obj_6.member_1_3);
    hash(&seed, tf_0_struct_obj_6.member_1_4);
    hash(&seed, tf_0_struct_obj_6.member_1_5);
    hash(&seed, tf_0_struct_obj_6.member_1_6);
    hash(&seed, tf_0_struct_obj_7.member_1_2);
    hash(&seed, tf_0_struct_obj_7.member_1_3);
    hash(&seed, tf_0_struct_obj_7.member_1_4);
    hash(&seed, tf_0_struct_obj_7.member_1_5);
    hash(&seed, tf_0_struct_obj_7.member_1_6);
    hash(&seed, tf_0_struct_obj_8.member_1_2);
    hash(&seed, tf_0_struct_obj_8.member_1_3);
    hash(&seed, tf_0_struct_obj_8.member_1_4);
    hash(&seed, tf_0_struct_obj_8.member_1_5);
    hash(&seed, tf_0_struct_obj_8.member_1_6);
    hash(&seed, tf_0_struct_obj_9.member_1_2);
    hash(&seed, tf_0_struct_obj_9.member_1_3);
    hash(&seed, tf_0_struct_obj_9.member_1_4);
    hash(&seed, tf_0_struct_obj_9.member_1_5);
    hash(&seed, tf_0_struct_obj_9.member_1_6);
    hash(&seed, tf_0_struct_obj_10.member_1_2);
    hash(&seed, tf_0_struct_obj_10.member_1_3);
    hash(&seed, tf_0_struct_obj_10.member_1_4);
    hash(&seed, tf_0_struct_obj_10.member_1_5);
    hash(&seed, tf_0_struct_obj_10.member_1_6);
    hash(&seed, tf_0_struct_obj_11.member_1_2);
    hash(&seed, tf_0_struct_obj_11.member_1_3);
    hash(&seed, tf_0_struct_obj_11.member_1_4);
    hash(&seed, tf_0_struct_obj_11.member_1_5);
    hash(&seed, tf_0_struct_obj_11.member_1_6);
    hash(&seed, tf_0_struct_obj_12.member_1_2);
    hash(&seed, tf_0_struct_obj_12.member_1_3);
    hash(&seed, tf_0_struct_obj_12.member_1_4);
    hash(&seed, tf_0_struct_obj_12.member_1_5);
    hash(&seed, tf_0_struct_obj_12.member_1_6);
    hash(&seed, tf_0_struct_obj_13.member_1_2);
    hash(&seed, tf_0_struct_obj_13.member_1_3);
    hash(&seed, tf_0_struct_obj_13.member_1_4);
    hash(&seed, tf_0_struct_obj_13.member_1_5);
    hash(&seed, tf_0_struct_obj_13.member_1_6);
    hash(&seed, *(tf_0_ptr_8));
    hash(&seed, *(tf_0_ptr_9));
    hash(&seed, *(tf_0_ptr_10));
    hash(&seed, *(tf_0_ptr_11));
    hash(&seed, *(tf_0_ptr_12));
    hash(&seed, *(tf_0_ptr_13));
    hash(&seed, *(*(tf_0_ptr_14)));
    hash(&seed, *(tf_0_ptr_15));
    hash(&seed, *(tf_0_ptr_16));
    hash(&seed, *(*(tf_0_ptr_17)));
    hash(&seed, *(tf_0_ptr_18));
    hash(&seed, *(tf_0_ptr_19));
}

extern void tf_0_foo ();

long int tf_1_var_2 = -4486489942216840902L;
const long int tf_1_var_4 = 3431466653246664768L;
const unsigned long long int tf_1_var_6 = 2968239198809729583ULL;
const long int tf_1_var_8 = -5240802924770832012L;
const unsigned long int tf_1_var_10 = 9505783593991332753UL;
const long int tf_1_var_12 = 6683882263416623630L;
long int tf_1_var_14 = -707521380016189606L;
unsigned long long int tf_1_var_16 = 10077525172956359447ULL;
const unsigned long int tf_1_var_18 = 13133256722716509473UL;
unsigned long long int tf_1_var_20 = 14481979461479430662ULL;
const long int tf_1_var_22 = -6954131458664171511L;
const long int tf_1_var_24 = -9000971378412287379L;
long int tf_1_var_26 = 4513146464664059371L;
const unsigned long int tf_1_var_28 = 12711271804852803711UL;
long int tf_1_var_30 = 7476008537740900633L;
long int tf_1_var_32 = -503594497165392005L;
const unsigned long long int tf_1_var_34 = 8815666670069684029ULL;
unsigned long long int tf_1_var_36 = 14622352140823348288ULL;
const long int tf_1_var_38 = -194651966417532456L;
unsigned long int tf_1_var_40 = 12545115632616634029UL;
long int tf_1_var_42 = 3071939341452339168L;
const unsigned long long int tf_1_var_44 = 16357985296675346612ULL;
const unsigned long long int tf_1_var_46 = 12871807951729545537ULL;
long int tf_1_var_48 = 5054412728331035198L;
const unsigned long long int tf_1_var_50 = 4499695482654818732ULL;
long int tf_1_var_52 = 2939439361314460245L;
const long int tf_1_var_54 = -4193980815208990973L;
const unsigned long long int tf_1_var_56 = 5803436627965898292ULL;
unsigned long int tf_1_var_58 = 17561637457073397908UL;
long int tf_1_var_60 = -5008723049298544304L;
const long int tf_1_var_62 = 1490154130849468616L;
const unsigned long int tf_1_var_64 = 16182511982898580872UL;
unsigned long int tf_1_var_66 = 7849757090863819158UL;
const unsigned long int tf_1_var_68 = 8226979452008792780UL;
unsigned long int tf_1_var_70 = 2406135695754251859UL;
const long int tf_1_var_72 = 1242444817888785269L;
long int tf_1_var_74 = -4531500649969714793L;
unsigned long int tf_1_var_76 = 16502127428478566256UL;
const long int tf_1_var_78 = 939916943437356858L;
const unsigned long int tf_1_var_80 = 11916109921264561897UL;
unsigned long int tf_1_var_82 = 9797131380444270052UL;
const unsigned long long int tf_1_var_84 = 13427587181521499208ULL;
const long int tf_1_var_86 = 168597051314081203L;
long int tf_1_var_88 = -8718203246865277556L;
unsigned long long int tf_1_var_90 = 24621245468658774ULL;
unsigned long int tf_1_var_92 = 14390494018136523588UL;
const unsigned long long int tf_1_var_94 = 475420552411416888ULL;
const long int tf_1_var_96 = -6861092749188924070L;
const unsigned long int tf_1_var_98 = 6403459830799734223UL;
unsigned long long int tf_1_var_100 = 1908174416320903679ULL;
const unsigned long int tf_1_var_102 = 2202573297151701180UL;
const long int tf_1_var_104 = 6147116827094753142L;
const unsigned long int tf_1_var_106 = 8570367952169480822UL;
const long int tf_1_var_108 = -2868313014652556598L;


long int tf_1_var_110 = -5028434174733977933L;
unsigned long int tf_1_var_112 = 12632709915176443629UL;
long int tf_1_var_114 = -3032346744533866098L;
unsigned long long int tf_1_var_116 = 2806599753668987815ULL;
unsigned long int tf_1_var_118 = 3875044262525203996UL;
unsigned long long int tf_1_var_120 = 12162241196512062512ULL;
unsigned long int tf_1_var_122 = 16320795952274176976UL;
long int tf_1_var_124 = 170823179387726264L;
unsigned long int tf_1_var_126 = 15527810115173753241UL;
long int tf_1_var_128 = 3247514494834375166L;
unsigned long int tf_1_var_130 = 3403739791975591310UL;
unsigned long int tf_1_var_132 = 9836011949895953211UL;
unsigned long long int tf_1_var_134 = 5057908081678112954ULL;
long int tf_1_var_136 = -6474511169254949717L;
unsigned long long int tf_1_var_138 = 9464917137659107668ULL;
unsigned long int tf_1_var_140 = 7547574282876493473UL;
long int tf_1_var_142 = 6142730405217220015L;
long int tf_1_var_144 = 7626210287055098770L;
unsigned long int tf_1_var_146 = 9431799188408783936UL;
unsigned long int tf_1_var_148 = 15925609276360187100UL;


long int tf_1_var_254 = -1314902338580135439L;
unsigned long int tf_1_var_258 = 5561917542846322084UL;
unsigned long long int tf_1_var_288 = 7652757610419998865ULL;
unsigned long long int tf_1_var_352 = 10560730092628139718ULL;
long int tf_1_var_360 = 2934885302654561425L;
long int tf_1_var_400 = 5409369730118623546L;
unsigned long long int tf_1_var_438 = 9029865806274589869ULL;
long int tf_1_var_520 = 934771983579170872L;
long int tf_1_var_522 = 3340715265906857491L;
unsigned long int tf_1_var_524 = 2595698011526898595UL;
long int tf_1_var_576 = 3242982008330115164L;
unsigned long int tf_1_var_588 = 14021065450947315454UL;
unsigned long int tf_1_var_662 = 12113047905486918510UL;
unsigned long long int tf_1_var_668 = 9924149522070428195ULL;
unsigned long long int tf_1_var_730 = 3044594326297155383ULL;
unsigned long int tf_1_var_740 = 10955828700217007913UL;


tf_1_struct_1 tf_1_struct_obj_1;
tf_1_struct_2 tf_1_struct_obj_2;
tf_1_struct_2 tf_1_struct_obj_3;
tf_1_struct_2 tf_1_struct_obj_4;


tf_1_struct_2 tf_1_struct_obj_5;


tf_1_struct_1 tf_1_struct_obj_6;
tf_1_struct_1 tf_1_struct_obj_7;
tf_1_struct_1 tf_1_struct_obj_8;
tf_1_struct_1 tf_1_struct_obj_9;
tf_1_struct_2 tf_1_struct_obj_10;
tf_1_struct_1 tf_1_struct_obj_11;
tf_1_struct_2 tf_1_struct_obj_12;








const unsigned long int * tf_1_ptr_1 = &(tf_1_var_64);
const unsigned long long int * tf_1_ptr_2 = &(tf_1_var_34);
unsigned long int * tf_1_ptr_3 = &(tf_1_var_66);
unsigned long int * * tf_1_ptr_4 = &(tf_1_ptr_3);


unsigned long int * tf_1_ptr_5 = &(tf_1_struct_obj_5.member_2_7.member_1_3);
unsigned long int * tf_1_ptr_6 = &(tf_1_var_132);
unsigned long int * * tf_1_ptr_7 = &(tf_1_ptr_5);
unsigned long int * tf_1_ptr_8 = &(tf_1_var_130);
long int * tf_1_ptr_9 = &(tf_1_var_144);


unsigned long long int * tf_1_ptr_10 = &(tf_1_struct_obj_12.member_2_2.member_1_0);
long int * tf_1_ptr_11 = &(tf_1_struct_obj_10.member_2_0);
unsigned long long int * tf_1_ptr_12 = &(tf_1_struct_obj_10.member_2_3.member_1_0);
unsigned long int * tf_1_ptr_13 = &(tf_1_struct_obj_10.member_2_4.member_1_3);
long int * tf_1_ptr_14 = &(tf_1_struct_obj_12.member_2_0);
long int * tf_1_ptr_15 = &(tf_1_struct_obj_10.member_2_0);
unsigned long int * tf_1_ptr_16 = &(tf_1_struct_obj_6.member_1_3);
unsigned long long int * tf_1_ptr_17 = &(tf_1_struct_obj_8.member_1_0);


unsigned long long int tf_1_struct_1::member_1_0 = 10290640675639174895ULL;
unsigned long int tf_1_struct_1::member_1_3 = 5535092615633922987UL;

tf_1_struct_1 tf_1_struct_2::member_2_2 = {25449428ULL, 67076L, };



void tf_1_init () {
    tf_1_struct_obj_1.member_1_1 = (unsigned long long int) (1019844ULL);
    tf_1_struct_obj_1.member_1_2 = (long int) (36421L);
    tf_1_struct_obj_2.member_2_0 = (long int) (5377073181714728170L);
    tf_1_struct_obj_2.member_2_1 = (unsigned long int) (20599829UL);
    tf_1_struct_obj_2.member_2_3.member_1_1 = (unsigned long long int) (53297515ULL);
    tf_1_struct_obj_2.member_2_3.member_1_2 = (long int) (58613L);
    tf_1_struct_obj_2.member_2_4.member_1_1 = (unsigned long long int) (36981801ULL);
    tf_1_struct_obj_2.member_2_4.member_1_2 = (long int) (99925L);
    tf_1_struct_obj_2.member_2_5 = (unsigned long int) (2634787UL);
    tf_1_struct_obj_2.member_2_6 = (unsigned long long int) (14693657859133008885ULL);
    tf_1_struct_obj_2.member_2_7.member_1_1 = (unsigned long long int) (45367936ULL);
    tf_1_struct_obj_2.member_2_7.member_1_2 = (long int) (120153L);
    tf_1_struct_obj_3.member_2_0 = (long int) (5187691856235321034L);
    tf_1_struct_obj_3.member_2_1 = (unsigned long int) (3439466UL);
    tf_1_struct_obj_3.member_2_3.member_1_1 = (unsigned long long int) (23781511ULL);
    tf_1_struct_obj_3.member_2_3.member_1_2 = (long int) (-46052L);
    tf_1_struct_obj_3.member_2_4.member_1_1 = (unsigned long long int) (198043ULL);
    tf_1_struct_obj_3.member_2_4.member_1_2 = (long int) (128174L);
    tf_1_struct_obj_3.member_2_5 = (unsigned long int) (4126967UL);
    tf_1_struct_obj_3.member_2_6 = (unsigned long long int) (14641678273535990265ULL);
    tf_1_struct_obj_3.member_2_7.member_1_1 = (unsigned long long int) (4131059ULL);
    tf_1_struct_obj_3.member_2_7.member_1_2 = (long int) (110461L);
    tf_1_struct_obj_4.member_2_0 = (long int) (-1112953567769777887L);
    tf_1_struct_obj_4.member_2_1 = (unsigned long int) (52454259UL);
    tf_1_struct_obj_4.member_2_3.member_1_1 = (unsigned long long int) (45833137ULL);
    tf_1_struct_obj_4.member_2_3.member_1_2 = (long int) (128157L);
    tf_1_struct_obj_4.member_2_4.member_1_1 = (unsigned long long int) (12113611ULL);
    tf_1_struct_obj_4.member_2_4.member_1_2 = (long int) (106763L);
    tf_1_struct_obj_4.member_2_5 = (unsigned long int) (2132620UL);
    tf_1_struct_obj_4.member_2_6 = (unsigned long long int) (17178724643054997162ULL);
    tf_1_struct_obj_4.member_2_7.member_1_1 = (unsigned long long int) (44268865ULL);
    tf_1_struct_obj_4.member_2_7.member_1_2 = (long int) (13782L);
    tf_1_struct_obj_5.member_2_0 = (long int) (5485615867531647703L);
    tf_1_struct_obj_5.member_2_1 = (unsigned long int) (11044973UL);
    tf_1_struct_obj_5.member_2_3.member_1_1 = (unsigned long long int) (61572676ULL);
    tf_1_struct_obj_5.member_2_3.member_1_2 = (long int) (-4486L);
    tf_1_struct_obj_5.member_2_4.member_1_1 = (unsigned long long int) (32702691ULL);
    tf_1_struct_obj_5.member_2_4.member_1_2 = (long int) (83417L);
    tf_1_struct_obj_5.member_2_5 = (unsigned long int) (3945390UL);
    tf_1_struct_obj_5.member_2_6 = (unsigned long long int) (8374354836077847033ULL);
    tf_1_struct_obj_5.member_2_7.member_1_1 = (unsigned long long int) (21974028ULL);
    tf_1_struct_obj_5.member_2_7.member_1_2 = (long int) (-84894L);
    tf_1_struct_obj_6.member_1_1 = (unsigned long long int) (45785411ULL);
    tf_1_struct_obj_6.member_1_2 = (long int) (-112375L);
    tf_1_struct_obj_7.member_1_1 = (unsigned long long int) (13082482ULL);
    tf_1_struct_obj_7.member_1_2 = (long int) (-96581L);
    tf_1_struct_obj_8.member_1_1 = (unsigned long long int) (34771555ULL);
    tf_1_struct_obj_8.member_1_2 = (long int) (125532L);
    tf_1_struct_obj_9.member_1_1 = (unsigned long long int) (5718165ULL);
    tf_1_struct_obj_9.member_1_2 = (long int) (-11730L);
    tf_1_struct_obj_10.member_2_0 = (long int) (-3001368333374065258L);
    tf_1_struct_obj_10.member_2_1 = (unsigned long int) (42206370UL);
    tf_1_struct_obj_10.member_2_3.member_1_1 = (unsigned long long int) (673394ULL);
    tf_1_struct_obj_10.member_2_3.member_1_2 = (long int) (-105527L);
    tf_1_struct_obj_10.member_2_4.member_1_1 = (unsigned long long int) (48909224ULL);
    tf_1_struct_obj_10.member_2_4.member_1_2 = (long int) (-73848L);
    tf_1_struct_obj_10.member_2_5 = (unsigned long int) (3172986UL);
    tf_1_struct_obj_10.member_2_6 = (unsigned long long int) (12970591300845698817ULL);
    tf_1_struct_obj_10.member_2_7.member_1_1 = (unsigned long long int) (32130647ULL);
    tf_1_struct_obj_10.member_2_7.member_1_2 = (long int) (-108601L);
    tf_1_struct_obj_11.member_1_1 = (unsigned long long int) (25367120ULL);
    tf_1_struct_obj_11.member_1_2 = (long int) (25055L);
    tf_1_struct_obj_12.member_2_0 = (long int) (478995527305219743L);
    tf_1_struct_obj_12.member_2_1 = (unsigned long int) (40875667UL);
    tf_1_struct_obj_12.member_2_3.member_1_1 = (unsigned long long int) (59417520ULL);
    tf_1_struct_obj_12.member_2_3.member_1_2 = (long int) (131001L);
    tf_1_struct_obj_12.member_2_4.member_1_1 = (unsigned long long int) (20730197ULL);
    tf_1_struct_obj_12.member_2_4.member_1_2 = (long int) (-33955L);
    tf_1_struct_obj_12.member_2_5 = (unsigned long int) (108489UL);
    tf_1_struct_obj_12.member_2_6 = (unsigned long long int) (14005081202076061326ULL);
    tf_1_struct_obj_12.member_2_7.member_1_1 = (unsigned long long int) (52488402ULL);
    tf_1_struct_obj_12.member_2_7.member_1_2 = (long int) (7250L);
}

void tf_1_checksum () {
    hash(&seed, tf_1_struct_1::member_1_0);
    hash(&seed, tf_1_struct_1::member_1_3);

    hash(&seed, tf_1_struct_2::member_2_2.member_1_1);
    hash(&seed, tf_1_struct_2::member_2_2.member_1_2);

    hash(&seed, tf_1_var_110);
    hash(&seed, tf_1_var_112);
    hash(&seed, tf_1_var_114);
    hash(&seed, tf_1_var_116);
    hash(&seed, tf_1_var_118);
    hash(&seed, tf_1_var_120);
    hash(&seed, tf_1_var_122);
    hash(&seed, tf_1_var_124);
    hash(&seed, tf_1_var_126);
    hash(&seed, tf_1_var_128);
    hash(&seed, tf_1_var_130);
    hash(&seed, tf_1_var_132);
    hash(&seed, tf_1_var_134);
    hash(&seed, tf_1_var_136);
    hash(&seed, tf_1_var_138);
    hash(&seed, tf_1_var_140);
    hash(&seed, tf_1_var_142);
    hash(&seed, tf_1_var_144);
    hash(&seed, tf_1_var_146);
    hash(&seed, tf_1_var_148);
    hash(&seed, tf_1_var_254);
    hash(&seed, tf_1_var_258);
    hash(&seed, tf_1_var_288);
    hash(&seed, tf_1_var_352);
    hash(&seed, tf_1_var_360);
    hash(&seed, tf_1_var_400);
    hash(&seed, tf_1_var_438);
    hash(&seed, tf_1_var_520);
    hash(&seed, tf_1_var_522);
    hash(&seed, tf_1_var_524);
    hash(&seed, tf_1_var_576);
    hash(&seed, tf_1_var_588);
    hash(&seed, tf_1_var_662);
    hash(&seed, tf_1_var_668);
    hash(&seed, tf_1_var_730);
    hash(&seed, tf_1_var_740);
    hash(&seed, tf_1_struct_obj_5.member_2_0);
    hash(&seed, tf_1_struct_obj_5.member_2_1);
    hash(&seed, tf_1_struct_obj_5.member_2_3.member_1_1);
    hash(&seed, tf_1_struct_obj_5.member_2_3.member_1_2);
    hash(&seed, tf_1_struct_obj_5.member_2_4.member_1_1);
    hash(&seed, tf_1_struct_obj_5.member_2_4.member_1_2);
    hash(&seed, tf_1_struct_obj_5.member_2_5);
    hash(&seed, tf_1_struct_obj_5.member_2_6);
    hash(&seed, tf_1_struct_obj_5.member_2_7.member_1_1);
    hash(&seed, tf_1_struct_obj_5.member_2_7.member_1_2);
    hash(&seed, tf_1_struct_obj_6.member_1_1);
    hash(&seed, tf_1_struct_obj_6.member_1_2);
    hash(&seed, tf_1_struct_obj_7.member_1_1);
    hash(&seed, tf_1_struct_obj_7.member_1_2);
    hash(&seed, tf_1_struct_obj_8.member_1_1);
    hash(&seed, tf_1_struct_obj_8.member_1_2);
    hash(&seed, tf_1_struct_obj_9.member_1_1);
    hash(&seed, tf_1_struct_obj_9.member_1_2);
    hash(&seed, tf_1_struct_obj_10.member_2_0);
    hash(&seed, tf_1_struct_obj_10.member_2_1);
    hash(&seed, tf_1_struct_obj_10.member_2_3.member_1_1);
    hash(&seed, tf_1_struct_obj_10.member_2_3.member_1_2);
    hash(&seed, tf_1_struct_obj_10.member_2_4.member_1_1);
    hash(&seed, tf_1_struct_obj_10.member_2_4.member_1_2);
    hash(&seed, tf_1_struct_obj_10.member_2_5);
    hash(&seed, tf_1_struct_obj_10.member_2_6);
    hash(&seed, tf_1_struct_obj_10.member_2_7.member_1_1);
    hash(&seed, tf_1_struct_obj_10.member_2_7.member_1_2);
    hash(&seed, tf_1_struct_obj_11.member_1_1);
    hash(&seed, tf_1_struct_obj_11.member_1_2);
    hash(&seed, tf_1_struct_obj_12.member_2_0);
    hash(&seed, tf_1_struct_obj_12.member_2_1);
    hash(&seed, tf_1_struct_obj_12.member_2_3.member_1_1);
    hash(&seed, tf_1_struct_obj_12.member_2_3.member_1_2);
    hash(&seed, tf_1_struct_obj_12.member_2_4.member_1_1);
    hash(&seed, tf_1_struct_obj_12.member_2_4.member_1_2);
    hash(&seed, tf_1_struct_obj_12.member_2_5);
    hash(&seed, tf_1_struct_obj_12.member_2_6);
    hash(&seed, tf_1_struct_obj_12.member_2_7.member_1_1);
    hash(&seed, tf_1_struct_obj_12.member_2_7.member_1_2);
    hash(&seed, *(tf_1_ptr_5));
    hash(&seed, *(tf_1_ptr_6));
    hash(&seed, *(*(tf_1_ptr_7)));
    hash(&seed, *(tf_1_ptr_8));
    hash(&seed, *(tf_1_ptr_9));
    hash(&seed, *(tf_1_ptr_10));
    hash(&seed, *(tf_1_ptr_11));
    hash(&seed, *(tf_1_ptr_12));
    hash(&seed, *(tf_1_ptr_13));
    hash(&seed, *(tf_1_ptr_14));
    hash(&seed, *(tf_1_ptr_15));
    hash(&seed, *(tf_1_ptr_16));
    hash(&seed, *(tf_1_ptr_17));
}

extern void tf_1_foo ();

long int tf_2_var_2 = 6621458389734386152L;
unsigned long long int tf_2_var_4 = 144275729692078989ULL;
unsigned long int tf_2_var_6 = 17854642747535310129UL;
const unsigned long int tf_2_var_8 = 15334358845436411996UL;
const unsigned long int tf_2_var_10 = 6276663114926296718UL;
const unsigned long int tf_2_var_12 = 5345360195458933246UL;
const long int tf_2_var_14 = 4821164342980007315L;
long int tf_2_var_16 = -6623867751587536418L;
const unsigned long int tf_2_var_18 = 11081592822789328656UL;
const long int tf_2_var_20 = 4691348907825687372L;
unsigned long int tf_2_var_22 = 9691708516694316294UL;
const unsigned long long int tf_2_var_24 = 3251764594905331232ULL;
const long int tf_2_var_26 = 8587105974042210366L;
const unsigned long long int tf_2_var_28 = 2168351502600940332ULL;
unsigned long long int tf_2_var_30 = 5963733897183381471ULL;
const unsigned long int tf_2_var_32 = 7665467770532581767UL;
unsigned long int tf_2_var_34 = 13839384569397643147UL;
long int tf_2_var_36 = 3344803437827592041L;
const long int tf_2_var_38 = 8027956844574186364L;
const long int tf_2_var_40 = -710263226043873418L;
unsigned long int tf_2_var_42 = 13151609753545979898UL;
const unsigned long long int tf_2_var_44 = 304823982764804766ULL;
const unsigned long long int tf_2_var_46 = 9870090405427206932ULL;
unsigned long long int tf_2_var_48 = 16712066973185888519ULL;
unsigned long int tf_2_var_50 = 18081979119493613401UL;
long int tf_2_var_52 = 1959207970415543018L;
unsigned long int tf_2_var_54 = 10638027084009111591UL;
const unsigned long int tf_2_var_56 = 4276595556366856055UL;
unsigned long int tf_2_var_58 = 17424876708072520696UL;
const long int tf_2_var_60 = 6486912108304896181L;
const unsigned long long int tf_2_var_62 = 13262409744118450573ULL;
const unsigned long long int tf_2_var_64 = 3296767760088398204ULL;
unsigned long int tf_2_var_66 = 7965415408779008598UL;
const long int tf_2_var_68 = -5274291497518775115L;
const unsigned long long int tf_2_var_70 = 13991882695648035400ULL;
unsigned long long int tf_2_var_72 = 1276841473087724300ULL;
unsigned long long int tf_2_var_74 = 7721266732468334647ULL;
const unsigned long int tf_2_var_76 = 8970607152482182100UL;
const long int tf_2_var_78 = 7839713689808821822L;
const unsigned long long int tf_2_var_80 = 8026637573055738502ULL;
long int tf_2_var_82 = -4541520070362844837L;
const unsigned long long int tf_2_var_84 = 3474270051854413127ULL;


long int tf_2_var_86 = -6560332349834901156L;
long int tf_2_var_88 = -4616244773232041000L;
unsigned long long int tf_2_var_90 = 15355111601894283929ULL;
long int tf_2_var_92 = 7270839823560053296L;
unsigned long long int tf_2_var_94 = 18167437994633553514ULL;
unsigned long long int tf_2_var_96 = 15060380636989216549ULL;
long int tf_2_var_98 = -7607721315564257395L;
long int tf_2_var_100 = 7346125141345382941L;
unsigned long long int tf_2_var_102 = 11660470761501131854ULL;
long int tf_2_var_104 = 7134953479396831679L;
unsigned long long int tf_2_var_106 = 8109141452082938250ULL;
long int tf_2_var_108 = 3693377255699860351L;
unsigned long int tf_2_var_110 = 9358062368553302251UL;
unsigned long int tf_2_var_112 = 13578538449125104309UL;
unsigned long int tf_2_var_114 = 1616988934843951795UL;
unsigned long int tf_2_var_116 = 2116411533353177866UL;
unsigned long int tf_2_var_118 = 9872082229636701742UL;
unsigned long long int tf_2_var_120 = 7340114664729193786ULL;
unsigned long long int tf_2_var_122 = 4812933825552689972ULL;
unsigned long int tf_2_var_124 = 5966279301032791030UL;
unsigned long int tf_2_var_126 = 12943840509292668094UL;
unsigned long int tf_2_var_128 = 7043415047660101217UL;
unsigned long int tf_2_var_130 = 12854162179288479698UL;
unsigned long int tf_2_var_132 = 10268458540146408679UL;
unsigned long int tf_2_var_134 = 15039019559478242583UL;
long int tf_2_var_136 = -8525332049172013442L;
long int tf_2_var_138 = -6086474327188638648L;
unsigned long long int tf_2_var_140 = 10486241248754582699ULL;
unsigned long long int tf_2_var_142 = 17272971541549229378ULL;
long int tf_2_var_144 = 3580437683119231003L;
unsigned long long int tf_2_var_146 = 2839311557626401301ULL;
unsigned long long int tf_2_var_148 = 11373191432078369625ULL;
long int tf_2_var_150 = -4155348809849606665L;
unsigned long int tf_2_var_152 = 11909974023410735951UL;
long int tf_2_var_154 = -4122499042699816919L;
unsigned long long int tf_2_var_156 = 14231106861772814564ULL;


unsigned long int tf_2_var_242 = 9381142312591035254UL;
long int tf_2_var_294 = -1598956366211465362L;
unsigned long int tf_2_var_312 = 7110878524986148580UL;
unsigned long long int tf_2_var_340 = 11138300535891825118ULL;
long int tf_2_var_426 = 2051188676672754369L;
long int tf_2_var_446 = -1633999821701608930L;
long int tf_2_var_462 = 6993829933366056271L;
long int tf_2_var_500 = 81005854787987894L;
unsigned long int tf_2_var_508 = 3558682974423785003UL;
long int tf_2_var_542 = -4758024056280140754L;
unsigned long long int tf_2_var_578 = 14335369894030257906ULL;
long int tf_2_var_584 = -2591154851136583803L;
long int tf_2_var_588 = -3350122674706805050L;
unsigned long int tf_2_var_612 = 4936784480511385598UL;
unsigned long long int tf_2_var_724 = 2707275676428410787ULL;
unsigned long int tf_2_var_856 = 12165313538325918698UL;
unsigned long int tf_2_var_876 = 14752217735838284590UL;
long int tf_2_var_886 = -376393604551269971L;
unsigned long long int tf_2_var_912 = 874848842251465422ULL;
long int tf_2_var_920 = 7723146761852866882L;














const unsigned long long int * tf_2_ptr_1 = &(tf_2_var_24);
unsigned long int * tf_2_ptr_2 = &(tf_2_var_66);
unsigned long int * tf_2_ptr_3 = &(tf_2_var_6);
const unsigned long int * tf_2_ptr_4 = &(tf_2_var_56);
unsigned long long int * tf_2_ptr_5 = &(tf_2_var_48);
unsigned long int * tf_2_ptr_6 = &(tf_2_var_66);


unsigned long long int * tf_2_ptr_7 = &(tf_2_var_122);
long int * tf_2_ptr_8 = &(tf_2_var_88);
unsigned long long int * tf_2_ptr_9 = &(tf_2_var_94);
long int * tf_2_ptr_10 = &(tf_2_var_88);
unsigned long long int * tf_2_ptr_11 = &(tf_2_var_148);
unsigned long int * tf_2_ptr_12 = &(tf_2_var_110);
long int * tf_2_ptr_13 = &(tf_2_var_138);






void tf_2_init () {
}

void tf_2_checksum () {
    hash(&seed, tf_2_var_86);
    hash(&seed, tf_2_var_88);
    hash(&seed, tf_2_var_90);
    hash(&seed, tf_2_var_92);
    hash(&seed, tf_2_var_94);
    hash(&seed, tf_2_var_96);
    hash(&seed, tf_2_var_98);
    hash(&seed, tf_2_var_100);
    hash(&seed, tf_2_var_102);
    hash(&seed, tf_2_var_104);
    hash(&seed, tf_2_var_106);
    hash(&seed, tf_2_var_108);
    hash(&seed, tf_2_var_110);
    hash(&seed, tf_2_var_112);
    hash(&seed, tf_2_var_114);
    hash(&seed, tf_2_var_116);
    hash(&seed, tf_2_var_118);
    hash(&seed, tf_2_var_120);
    hash(&seed, tf_2_var_122);
    hash(&seed, tf_2_var_124);
    hash(&seed, tf_2_var_126);
    hash(&seed, tf_2_var_128);
    hash(&seed, tf_2_var_130);
    hash(&seed, tf_2_var_132);
    hash(&seed, tf_2_var_134);
    hash(&seed, tf_2_var_136);
    hash(&seed, tf_2_var_138);
    hash(&seed, tf_2_var_140);
    hash(&seed, tf_2_var_142);
    hash(&seed, tf_2_var_144);
    hash(&seed, tf_2_var_146);
    hash(&seed, tf_2_var_148);
    hash(&seed, tf_2_var_150);
    hash(&seed, tf_2_var_152);
    hash(&seed, tf_2_var_154);
    hash(&seed, tf_2_var_156);
    hash(&seed, tf_2_var_242);
    hash(&seed, tf_2_var_294);
    hash(&seed, tf_2_var_312);
    hash(&seed, tf_2_var_340);
    hash(&seed, tf_2_var_426);
    hash(&seed, tf_2_var_446);
    hash(&seed, tf_2_var_462);
    hash(&seed, tf_2_var_500);
    hash(&seed, tf_2_var_508);
    hash(&seed, tf_2_var_542);
    hash(&seed, tf_2_var_578);
    hash(&seed, tf_2_var_584);
    hash(&seed, tf_2_var_588);
    hash(&seed, tf_2_var_612);
    hash(&seed, tf_2_var_724);
    hash(&seed, tf_2_var_856);
    hash(&seed, tf_2_var_876);
    hash(&seed, tf_2_var_886);
    hash(&seed, tf_2_var_912);
    hash(&seed, tf_2_var_920);
    hash(&seed, *(tf_2_ptr_7));
    hash(&seed, *(tf_2_ptr_8));
    hash(&seed, *(tf_2_ptr_9));
    hash(&seed, *(tf_2_ptr_10));
    hash(&seed, *(tf_2_ptr_11));
    hash(&seed, *(tf_2_ptr_12));
    hash(&seed, *(tf_2_ptr_13));
}

extern void tf_2_foo ();

long int tf_3_var_2 = 7391651427448421296L;
unsigned long long int tf_3_var_4 = 14590488088545270120ULL;
unsigned long long int tf_3_var_6 = 795342266696058543ULL;
const unsigned long int tf_3_var_8 = 5816111386025414666UL;
long int tf_3_var_10 = -6077685424891245502L;
unsigned long long int tf_3_var_12 = 2043524244138079762ULL;
unsigned long long int tf_3_var_14 = 9881129949635785238ULL;
long int tf_3_var_16 = 1512851147717789038L;
const unsigned long int tf_3_var_18 = 708228760806723175UL;
unsigned long int tf_3_var_20 = 17555010453786442698UL;
const unsigned long long int tf_3_var_22 = 10620440559438416195ULL;
const unsigned long long int tf_3_var_24 = 5648591076085249935ULL;
const long int tf_3_var_26 = 8135273997437614254L;
unsigned long long int tf_3_var_28 = 4464090834109086293ULL;
unsigned long int tf_3_var_30 = 17971408354882805664UL;
long int tf_3_var_32 = 2839959286063139726L;
unsigned long int tf_3_var_34 = 8291287727539233193UL;
const unsigned long long int tf_3_var_36 = 17085730443436708190ULL;
const long int tf_3_var_38 = -3597011935916758339L;
long int tf_3_var_40 = -5230378511370131259L;
const unsigned long int tf_3_var_42 = 14522371170074589802UL;


unsigned long long int tf_3_var_44 = 18073765056405037752ULL;
long int tf_3_var_46 = -697998879014515167L;
unsigned long long int tf_3_var_48 = 9925644048908902561ULL;
unsigned long long int tf_3_var_50 = 3507845697807138633ULL;
unsigned long int tf_3_var_52 = 7800677997278000044UL;
unsigned long long int tf_3_var_54 = 2507253412098408689ULL;
long int tf_3_var_56 = -4360518673925227011L;
unsigned long long int tf_3_var_58 = 10181465855628043216ULL;
unsigned long long int tf_3_var_60 = 12810323638482496350ULL;
unsigned long int tf_3_var_62 = 14688797182531803289UL;
long int tf_3_var_64 = -1428696097985019504L;
long int tf_3_var_66 = 4058485203860148521L;
unsigned long long int tf_3_var_68 = 1926452124224835490ULL;
long int tf_3_var_70 = 5667045692230158225L;
long int tf_3_var_72 = -2048389981842172036L;
unsigned long int tf_3_var_74 = 14678430276233509461UL;
long int tf_3_var_76 = -664044642123336700L;
unsigned long int tf_3_var_78 = 8403945024679948763UL;
long int tf_3_var_80 = -270476276036667301L;
unsigned long int tf_3_var_82 = 6756128609388497439UL;
unsigned long int tf_3_var_84 = 974033993170320449UL;
long int tf_3_var_86 = -637472045825541441L;
unsigned long long int tf_3_var_88 = 13553802772175034778ULL;
long int tf_3_var_90 = 960801510586046122L;
unsigned long int tf_3_var_92 = 2678692517722686572UL;
unsigned long long int tf_3_var_94 = 5918674028838561171ULL;
long int tf_3_var_96 = 7234335553398782259L;
unsigned long int tf_3_var_98 = 16684141199177019806UL;
unsigned long int tf_3_var_100 = 10104576416202021697UL;
unsigned long int tf_3_var_102 = 18389085045662841020UL;
unsigned long long int tf_3_var_104 = 10495795385758813272ULL;
unsigned long int tf_3_var_106 = 12545766439285603329UL;
long int tf_3_var_108 = -2633145394046114469L;
unsigned long int tf_3_var_110 = 11121103950672858801UL;
unsigned long int tf_3_var_112 = 8525532555727300071UL;
long int tf_3_var_114 = 2720315656889057661L;
long int tf_3_var_116 = -8682601804318058735L;
unsigned long long int tf_3_var_118 = 3468017352475660386ULL;
long int tf_3_var_120 = -6406629226502171296L;
unsigned long int tf_3_var_122 = 4136058876130752734UL;
long int tf_3_var_124 = 5403653082369361064L;
unsigned long int tf_3_var_126 = 10855453885300868865UL;
unsigned long long int tf_3_var_128 = 12081948689667703628ULL;
unsigned long long int tf_3_var_130 = 14694193599246267572ULL;
long int tf_3_var_132 = -3359588009051576304L;
long int tf_3_var_134 = -6165470374490079298L;
long int tf_3_var_136 = 6674881333411088616L;
long int tf_3_var_138 = -1932961116604234006L;
long int tf_3_var_140 = -1982375908972322334L;
unsigned long long int tf_3_var_142 = 15903846732103747679ULL;
long int tf_3_var_144 = 5545163858937257505L;




tf_3_struct_2 tf_3_struct_obj_1;
tf_3_struct_1 tf_3_struct_obj_2;
tf_3_struct_2 tf_3_struct_obj_3;
tf_3_struct_3 tf_3_struct_obj_4;
tf_3_struct_2 tf_3_struct_obj_5;


tf_3_struct_1 tf_3_struct_obj_6;
tf_3_struct_2 tf_3_struct_obj_7;


tf_3_struct_2 tf_3_struct_obj_8;
tf_3_struct_2 tf_3_struct_obj_9;
tf_3_struct_2 tf_3_struct_obj_10;
tf_3_struct_2 tf_3_struct_obj_11;
tf_3_struct_1 tf_3_struct_obj_12;








long int * tf_3_ptr_1 = &(tf_3_var_10);
unsigned long int * tf_3_ptr_2 = &(tf_3_struct_obj_5.member_2_5.member_1_0);
unsigned long int * tf_3_ptr_3 = &(tf_3_var_20);
unsigned long int * tf_3_ptr_4 = &(tf_3_var_34);
unsigned long int * tf_3_ptr_5 = &(tf_3_struct_obj_2.member_1_6);
unsigned long int * tf_3_ptr_6 = &(tf_3_struct_obj_3.member_2_5.member_1_0);
unsigned long long int * tf_3_ptr_7 = &(tf_3_struct_obj_5.member_2_6);
unsigned long int * tf_3_ptr_8 = &(tf_3_struct_obj_5.member_2_5.member_1_0);
long int * tf_3_ptr_9 = &(tf_3_struct_obj_1.member_2_0);
unsigned long int * tf_3_ptr_10 = &(tf_3_struct_obj_3.member_2_5.member_1_0);




long int * tf_3_ptr_11 = &(tf_3_struct_obj_10.member_2_3.member_1_2);
long int * tf_3_ptr_12 = &(tf_3_struct_obj_8.member_2_0);
long int * tf_3_ptr_13 = &(tf_3_struct_obj_9.member_2_7.member_1_2);
long int * tf_3_ptr_14 = &(tf_3_struct_obj_8.member_2_5.member_1_2);
unsigned long int * tf_3_ptr_15 = &(tf_3_struct_obj_10.member_2_5.member_1_5);


long int tf_3_struct_1::member_1_2 = -9091753112525671755L;
long int tf_3_struct_1::member_1_3 = -6549717252251031944L;
unsigned long int tf_3_struct_1::member_1_5 = 15935324472696219798UL;

tf_3_struct_1 tf_3_struct_2::member_2_1 = {15656028975682284422UL, -1590051509L, 334283UL, 17683902322382694580UL};
unsigned long int tf_3_struct_2::member_2_2 = 6547246126659184677UL;
tf_3_struct_1 tf_3_struct_2::member_2_3 = {16538260405432987435UL, -1249764237L, 444476UL, 1949990717312430615UL};

unsigned long long int tf_3_struct_3::member_3_1 = 17163872422034267257ULL;



void tf_3_init () {
    tf_3_struct_obj_1.member_2_0 = (long int) (-8297695505772448633L);
    tf_3_struct_obj_1.member_2_4 = (unsigned long int) (104995UL);
    tf_3_struct_obj_1.member_2_5.member_1_0 = (unsigned long int) (12590513205152368161UL);
    tf_3_struct_obj_1.member_2_5.member_1_1 = (long int) (1080311832L);
    tf_3_struct_obj_1.member_2_5.member_1_4 = (unsigned long int) (397697UL);
    tf_3_struct_obj_1.member_2_5.member_1_6 = (unsigned long int) (6392968998255306945UL);
    tf_3_struct_obj_1.member_2_6 = (unsigned long long int) (15199617651017245120ULL);
    tf_3_struct_obj_1.member_2_7.member_1_0 = (unsigned long int) (17424188106571741836UL);
    tf_3_struct_obj_1.member_2_7.member_1_1 = (long int) (-1961200643L);
    tf_3_struct_obj_1.member_2_7.member_1_4 = (unsigned long int) (61498UL);
    tf_3_struct_obj_1.member_2_7.member_1_6 = (unsigned long int) (7786336886600779126UL);
    tf_3_struct_obj_2.member_1_0 = (unsigned long int) (2738055360256738355UL);
    tf_3_struct_obj_2.member_1_1 = (long int) (153719612L);
    tf_3_struct_obj_2.member_1_4 = (unsigned long int) (417956UL);
    tf_3_struct_obj_2.member_1_6 = (unsigned long int) (3599232602056480164UL);
    tf_3_struct_obj_3.member_2_0 = (long int) (-6743840802578174464L);
    tf_3_struct_obj_3.member_2_4 = (unsigned long int) (327210UL);
    tf_3_struct_obj_3.member_2_5.member_1_0 = (unsigned long int) (92554023645266564UL);
    tf_3_struct_obj_3.member_2_5.member_1_1 = (long int) (-2023207090L);
    tf_3_struct_obj_3.member_2_5.member_1_4 = (unsigned long int) (425877UL);
    tf_3_struct_obj_3.member_2_5.member_1_6 = (unsigned long int) (4466812495950638783UL);
    tf_3_struct_obj_3.member_2_6 = (unsigned long long int) (3033006859093894692ULL);
    tf_3_struct_obj_3.member_2_7.member_1_0 = (unsigned long int) (1760971843600533924UL);
    tf_3_struct_obj_3.member_2_7.member_1_1 = (long int) (-1756679492L);
    tf_3_struct_obj_3.member_2_7.member_1_4 = (unsigned long int) (508749UL);
    tf_3_struct_obj_3.member_2_7.member_1_6 = (unsigned long int) (6834394771769943998UL);
    tf_3_struct_obj_4.member_3_0 = (unsigned long int) (1595058430579612095UL);
    tf_3_struct_obj_5.member_2_0 = (long int) (-5813694952373523214L);
    tf_3_struct_obj_5.member_2_4 = (unsigned long int) (298960UL);
    tf_3_struct_obj_5.member_2_5.member_1_0 = (unsigned long int) (6285632292952004786UL);
    tf_3_struct_obj_5.member_2_5.member_1_1 = (long int) (1105743284L);
    tf_3_struct_obj_5.member_2_5.member_1_4 = (unsigned long int) (363923UL);
    tf_3_struct_obj_5.member_2_5.member_1_6 = (unsigned long int) (3534695121677662890UL);
    tf_3_struct_obj_5.member_2_6 = (unsigned long long int) (9953499936125446931ULL);
    tf_3_struct_obj_5.member_2_7.member_1_0 = (unsigned long int) (16442925144766830282UL);
    tf_3_struct_obj_5.member_2_7.member_1_1 = (long int) (293412889L);
    tf_3_struct_obj_5.member_2_7.member_1_4 = (unsigned long int) (499766UL);
    tf_3_struct_obj_5.member_2_7.member_1_6 = (unsigned long int) (6580206921895747732UL);
    tf_3_struct_obj_6.member_1_0 = (unsigned long int) (2455427089755147319UL);
    tf_3_struct_obj_6.member_1_1 = (long int) (-589909326L);
    tf_3_struct_obj_6.member_1_4 = (unsigned long int) (71483UL);
    tf_3_struct_obj_6.member_1_6 = (unsigned long int) (8860459908381620278UL);
    tf_3_struct_obj_7.member_2_0 = (long int) (7877278336009333734L);
    tf_3_struct_obj_7.member_2_4 = (unsigned long int) (400463UL);
    tf_3_struct_obj_7.member_2_5.member_1_0 = (unsigned long int) (14629754883614476415UL);
    tf_3_struct_obj_7.member_2_5.member_1_1 = (long int) (-2109448585L);
    tf_3_struct_obj_7.member_2_5.member_1_4 = (unsigned long int) (483736UL);
    tf_3_struct_obj_7.member_2_5.member_1_6 = (unsigned long int) (432834395937649502UL);
    tf_3_struct_obj_7.member_2_6 = (unsigned long long int) (8961950081307913398ULL);
    tf_3_struct_obj_7.member_2_7.member_1_0 = (unsigned long int) (10656523864005864677UL);
    tf_3_struct_obj_7.member_2_7.member_1_1 = (long int) (-1323814390L);
    tf_3_struct_obj_7.member_2_7.member_1_4 = (unsigned long int) (57374UL);
    tf_3_struct_obj_7.member_2_7.member_1_6 = (unsigned long int) (32920793994834270UL);
    tf_3_struct_obj_8.member_2_0 = (long int) (-614779530052312050L);
    tf_3_struct_obj_8.member_2_4 = (unsigned long int) (246853UL);
    tf_3_struct_obj_8.member_2_5.member_1_0 = (unsigned long int) (16688211244148757482UL);
    tf_3_struct_obj_8.member_2_5.member_1_1 = (long int) (279356721L);
    tf_3_struct_obj_8.member_2_5.member_1_4 = (unsigned long int) (196291UL);
    tf_3_struct_obj_8.member_2_5.member_1_6 = (unsigned long int) (6991562090427114733UL);
    tf_3_struct_obj_8.member_2_6 = (unsigned long long int) (17792997056968155408ULL);
    tf_3_struct_obj_8.member_2_7.member_1_0 = (unsigned long int) (16835966847820050895UL);
    tf_3_struct_obj_8.member_2_7.member_1_1 = (long int) (-1538665337L);
    tf_3_struct_obj_8.member_2_7.member_1_4 = (unsigned long int) (502006UL);
    tf_3_struct_obj_8.member_2_7.member_1_6 = (unsigned long int) (7375550635178572221UL);
    tf_3_struct_obj_9.member_2_0 = (long int) (-7679374986247525650L);
    tf_3_struct_obj_9.member_2_4 = (unsigned long int) (292131UL);
    tf_3_struct_obj_9.member_2_5.member_1_0 = (unsigned long int) (15560833437118507258UL);
    tf_3_struct_obj_9.member_2_5.member_1_1 = (long int) (-1262907575L);
    tf_3_struct_obj_9.member_2_5.member_1_4 = (unsigned long int) (37035UL);
    tf_3_struct_obj_9.member_2_5.member_1_6 = (unsigned long int) (7988186421653331064UL);
    tf_3_struct_obj_9.member_2_6 = (unsigned long long int) (5659032386711112116ULL);
    tf_3_struct_obj_9.member_2_7.member_1_0 = (unsigned long int) (14671944717567350220UL);
    tf_3_struct_obj_9.member_2_7.member_1_1 = (long int) (-297008201L);
    tf_3_struct_obj_9.member_2_7.member_1_4 = (unsigned long int) (400789UL);
    tf_3_struct_obj_9.member_2_7.member_1_6 = (unsigned long int) (12098860490702626586UL);
    tf_3_struct_obj_10.member_2_0 = (long int) (-1663370100483468176L);
    tf_3_struct_obj_10.member_2_4 = (unsigned long int) (502315UL);
    tf_3_struct_obj_10.member_2_5.member_1_0 = (unsigned long int) (15018129326522165494UL);
    tf_3_struct_obj_10.member_2_5.member_1_1 = (long int) (-2088185593L);
    tf_3_struct_obj_10.member_2_5.member_1_4 = (unsigned long int) (253757UL);
    tf_3_struct_obj_10.member_2_5.member_1_6 = (unsigned long int) (3190357738547186681UL);
    tf_3_struct_obj_10.member_2_6 = (unsigned long long int) (14833371671764696637ULL);
    tf_3_struct_obj_10.member_2_7.member_1_0 = (unsigned long int) (6006825623007856382UL);
    tf_3_struct_obj_10.member_2_7.member_1_1 = (long int) (-4792206L);
    tf_3_struct_obj_10.member_2_7.member_1_4 = (unsigned long int) (273656UL);
    tf_3_struct_obj_10.member_2_7.member_1_6 = (unsigned long int) (17125449807660953230UL);
    tf_3_struct_obj_11.member_2_0 = (long int) (7986701507772687145L);
    tf_3_struct_obj_11.member_2_4 = (unsigned long int) (280634UL);
    tf_3_struct_obj_11.member_2_5.member_1_0 = (unsigned long int) (18015683964570151908UL);
    tf_3_struct_obj_11.member_2_5.member_1_1 = (long int) (-1346171993L);
    tf_3_struct_obj_11.member_2_5.member_1_4 = (unsigned long int) (153775UL);
    tf_3_struct_obj_11.member_2_5.member_1_6 = (unsigned long int) (4202017707625158087UL);
    tf_3_struct_obj_11.member_2_6 = (unsigned long long int) (15803036534557372751ULL);
    tf_3_struct_obj_11.member_2_7.member_1_0 = (unsigned long int) (9687992658528144530UL);
    tf_3_struct_obj_11.member_2_7.member_1_1 = (long int) (-878843474L);
    tf_3_struct_obj_11.member_2_7.member_1_4 = (unsigned long int) (482684UL);
    tf_3_struct_obj_11.member_2_7.member_1_6 = (unsigned long int) (16963878736170733852UL);
    tf_3_struct_obj_12.member_1_0 = (unsigned long int) (2768883526922998058UL);
    tf_3_struct_obj_12.member_1_1 = (long int) (434418433L);
    tf_3_struct_obj_12.member_1_4 = (unsigned long int) (40178UL);
    tf_3_struct_obj_12.member_1_6 = (unsigned long int) (6567122855981680855UL);
}

void tf_3_checksum () {
    hash(&seed, tf_3_struct_1::member_1_2);
    hash(&seed, tf_3_struct_1::member_1_3);
    hash(&seed, tf_3_struct_1::member_1_5);

    hash(&seed, tf_3_struct_2::member_2_1.member_1_0);
    hash(&seed, tf_3_struct_2::member_2_1.member_1_1);
    hash(&seed, tf_3_struct_2::member_2_1.member_1_4);
    hash(&seed, tf_3_struct_2::member_2_1.member_1_6);
    hash(&seed, tf_3_struct_2::member_2_2);
    hash(&seed, tf_3_struct_2::member_2_3.member_1_0);
    hash(&seed, tf_3_struct_2::member_2_3.member_1_1);
    hash(&seed, tf_3_struct_2::member_2_3.member_1_4);
    hash(&seed, tf_3_struct_2::member_2_3.member_1_6);

    hash(&seed, tf_3_struct_3::member_3_1);

    hash(&seed, tf_3_var_44);
    hash(&seed, tf_3_var_46);
    hash(&seed, tf_3_var_48);
    hash(&seed, tf_3_var_50);
    hash(&seed, tf_3_var_52);
    hash(&seed, tf_3_var_54);
    hash(&seed, tf_3_var_56);
    hash(&seed, tf_3_var_58);
    hash(&seed, tf_3_var_60);
    hash(&seed, tf_3_var_62);
    hash(&seed, tf_3_var_64);
    hash(&seed, tf_3_var_66);
    hash(&seed, tf_3_var_68);
    hash(&seed, tf_3_var_70);
    hash(&seed, tf_3_var_72);
    hash(&seed, tf_3_var_74);
    hash(&seed, tf_3_var_76);
    hash(&seed, tf_3_var_78);
    hash(&seed, tf_3_var_80);
    hash(&seed, tf_3_var_82);
    hash(&seed, tf_3_var_84);
    hash(&seed, tf_3_var_86);
    hash(&seed, tf_3_var_88);
    hash(&seed, tf_3_var_90);
    hash(&seed, tf_3_var_92);
    hash(&seed, tf_3_var_94);
    hash(&seed, tf_3_var_96);
    hash(&seed, tf_3_var_98);
    hash(&seed, tf_3_var_100);
    hash(&seed, tf_3_var_102);
    hash(&seed, tf_3_var_104);
    hash(&seed, tf_3_var_106);
    hash(&seed, tf_3_var_108);
    hash(&seed, tf_3_var_110);
    hash(&seed, tf_3_var_112);
    hash(&seed, tf_3_var_114);
    hash(&seed, tf_3_var_116);
    hash(&seed, tf_3_var_118);
    hash(&seed, tf_3_var_120);
    hash(&seed, tf_3_var_122);
    hash(&seed, tf_3_var_124);
    hash(&seed, tf_3_var_126);
    hash(&seed, tf_3_var_128);
    hash(&seed, tf_3_var_130);
    hash(&seed, tf_3_var_132);
    hash(&seed, tf_3_var_134);
    hash(&seed, tf_3_var_136);
    hash(&seed, tf_3_var_138);
    hash(&seed, tf_3_var_140);
    hash(&seed, tf_3_var_142);
    hash(&seed, tf_3_var_144);
    hash(&seed, tf_3_struct_obj_6.member_1_0);
    hash(&seed, tf_3_struct_obj_6.member_1_1);
    hash(&seed, tf_3_struct_obj_6.member_1_4);
    hash(&seed, tf_3_struct_obj_6.member_1_6);
    hash(&seed, tf_3_struct_obj_7.member_2_0);
    hash(&seed, tf_3_struct_obj_7.member_2_4);
    hash(&seed, tf_3_struct_obj_7.member_2_5.member_1_0);
    hash(&seed, tf_3_struct_obj_7.member_2_5.member_1_1);
    hash(&seed, tf_3_struct_obj_7.member_2_5.member_1_4);
    hash(&seed, tf_3_struct_obj_7.member_2_5.member_1_6);
    hash(&seed, tf_3_struct_obj_7.member_2_6);
    hash(&seed, tf_3_struct_obj_7.member_2_7.member_1_0);
    hash(&seed, tf_3_struct_obj_7.member_2_7.member_1_1);
    hash(&seed, tf_3_struct_obj_7.member_2_7.member_1_4);
    hash(&seed, tf_3_struct_obj_7.member_2_7.member_1_6);
    hash(&seed, tf_3_struct_obj_8.member_2_0);
    hash(&seed, tf_3_struct_obj_8.member_2_4);
    hash(&seed, tf_3_struct_obj_8.member_2_5.member_1_0);
    hash(&seed, tf_3_struct_obj_8.member_2_5.member_1_1);
    hash(&seed, tf_3_struct_obj_8.member_2_5.member_1_4);
    hash(&seed, tf_3_struct_obj_8.member_2_5.member_1_6);
    hash(&seed, tf_3_struct_obj_8.member_2_6);
    hash(&seed, tf_3_struct_obj_8.member_2_7.member_1_0);
    hash(&seed, tf_3_struct_obj_8.member_2_7.member_1_1);
    hash(&seed, tf_3_struct_obj_8.member_2_7.member_1_4);
    hash(&seed, tf_3_struct_obj_8.member_2_7.member_1_6);
    hash(&seed, tf_3_struct_obj_9.member_2_0);
    hash(&seed, tf_3_struct_obj_9.member_2_4);
    hash(&seed, tf_3_struct_obj_9.member_2_5.member_1_0);
    hash(&seed, tf_3_struct_obj_9.member_2_5.member_1_1);
    hash(&seed, tf_3_struct_obj_9.member_2_5.member_1_4);
    hash(&seed, tf_3_struct_obj_9.member_2_5.member_1_6);
    hash(&seed, tf_3_struct_obj_9.member_2_6);
    hash(&seed, tf_3_struct_obj_9.member_2_7.member_1_0);
    hash(&seed, tf_3_struct_obj_9.member_2_7.member_1_1);
    hash(&seed, tf_3_struct_obj_9.member_2_7.member_1_4);
    hash(&seed, tf_3_struct_obj_9.member_2_7.member_1_6);
    hash(&seed, tf_3_struct_obj_10.member_2_0);
    hash(&seed, tf_3_struct_obj_10.member_2_4);
    hash(&seed, tf_3_struct_obj_10.member_2_5.member_1_0);
    hash(&seed, tf_3_struct_obj_10.member_2_5.member_1_1);
    hash(&seed, tf_3_struct_obj_10.member_2_5.member_1_4);
    hash(&seed, tf_3_struct_obj_10.member_2_5.member_1_6);
    hash(&seed, tf_3_struct_obj_10.member_2_6);
    hash(&seed, tf_3_struct_obj_10.member_2_7.member_1_0);
    hash(&seed, tf_3_struct_obj_10.member_2_7.member_1_1);
    hash(&seed, tf_3_struct_obj_10.member_2_7.member_1_4);
    hash(&seed, tf_3_struct_obj_10.member_2_7.member_1_6);
    hash(&seed, tf_3_struct_obj_11.member_2_0);
    hash(&seed, tf_3_struct_obj_11.member_2_4);
    hash(&seed, tf_3_struct_obj_11.member_2_5.member_1_0);
    hash(&seed, tf_3_struct_obj_11.member_2_5.member_1_1);
    hash(&seed, tf_3_struct_obj_11.member_2_5.member_1_4);
    hash(&seed, tf_3_struct_obj_11.member_2_5.member_1_6);
    hash(&seed, tf_3_struct_obj_11.member_2_6);
    hash(&seed, tf_3_struct_obj_11.member_2_7.member_1_0);
    hash(&seed, tf_3_struct_obj_11.member_2_7.member_1_1);
    hash(&seed, tf_3_struct_obj_11.member_2_7.member_1_4);
    hash(&seed, tf_3_struct_obj_11.member_2_7.member_1_6);
    hash(&seed, tf_3_struct_obj_12.member_1_0);
    hash(&seed, tf_3_struct_obj_12.member_1_1);
    hash(&seed, tf_3_struct_obj_12.member_1_4);
    hash(&seed, tf_3_struct_obj_12.member_1_6);
    hash(&seed, *(tf_3_ptr_11));
    hash(&seed, *(tf_3_ptr_12));
    hash(&seed, *(tf_3_ptr_13));
    hash(&seed, *(tf_3_ptr_14));
    hash(&seed, *(tf_3_ptr_15));
}

extern void tf_3_foo ();

const unsigned long int tf_4_var_2 = 3555350651399690039UL;
long int tf_4_var_4 = -8184611495718258076L;
const long int tf_4_var_6 = 9132120789708289655L;
const unsigned long int tf_4_var_8 = 7266475590426728864UL;
const unsigned long int tf_4_var_10 = 2452262044673951000UL;
long int tf_4_var_12 = 4778556082097228604L;
const unsigned long long int tf_4_var_14 = 11244247818617086686ULL;
long int tf_4_var_16 = -6959828096617180335L;
unsigned long long int tf_4_var_18 = 14930874941475723446ULL;
const unsigned long long int tf_4_var_20 = 18243486669656007949ULL;
long int tf_4_var_22 = 513925838580503435L;
long int tf_4_var_24 = -6406842131021208381L;
long int tf_4_var_26 = -7117867151062664219L;
const unsigned long long int tf_4_var_28 = 18306295327235532220ULL;
unsigned long int tf_4_var_30 = 364215825577305837UL;
unsigned long int tf_4_var_32 = 9251646096507306907UL;
const unsigned long int tf_4_var_34 = 14399431387013611332UL;
long int tf_4_var_36 = -7405846232444967656L;
long int tf_4_var_38 = -7274575780227757619L;
const unsigned long long int tf_4_var_40 = 8753280563743973899ULL;


unsigned long long int tf_4_var_42 = 5411721382217294443ULL;
long int tf_4_var_44 = 6561875343844926634L;
long int tf_4_var_46 = 3581027048275863725L;
unsigned long int tf_4_var_48 = 17922587468677321896UL;
unsigned long int tf_4_var_50 = 14695404447319629609UL;
unsigned long long int tf_4_var_52 = 11071437131407222135ULL;
unsigned long long int tf_4_var_54 = 12332767713041098497ULL;
long int tf_4_var_56 = 1673877814621563795L;
unsigned long int tf_4_var_58 = 5434256742754740377UL;
long int tf_4_var_60 = -6806336567993224322L;
long int tf_4_var_62 = 3247328539233953043L;
long int tf_4_var_64 = -787853266296578622L;
unsigned long long int tf_4_var_66 = 15082440371782757238ULL;
unsigned long int tf_4_var_68 = 8778941912259331002UL;
long int tf_4_var_70 = 4393371391252044604L;
unsigned long long int tf_4_var_72 = 14943251014129966219ULL;
unsigned long int tf_4_var_74 = 11959151098972926115UL;
unsigned long long int tf_4_var_76 = 16661564322957316447ULL;
unsigned long long int tf_4_var_78 = 9443533270168246310ULL;
long int tf_4_var_80 = 1268915928718882926L;
long int tf_4_var_82 = -8604702199266139517L;


unsigned long int tf_4_var_232 = 14337996915560354275UL;
unsigned long int tf_4_var_286 = 11384960892628105280UL;
unsigned long int tf_4_var_374 = 5455044185742803076UL;
unsigned long long int tf_4_var_382 = 11273361673696595288ULL;
unsigned long long int tf_4_var_450 = 9017568474970006170ULL;
unsigned long int tf_4_var_518 = 629371601105520541UL;
unsigned long int tf_4_var_736 = 15852237154289953386UL;
unsigned long int tf_4_var_774 = 72282995417408158UL;
unsigned long int tf_4_var_832 = 6122567788982602007UL;
unsigned long int tf_4_var_836 = 1633362355350533972UL;








unsigned long int tf_4_array_1 [3] = {14042666777787954288UL, 4857597310590789162UL, 13491448635874196320UL};
std::vector<unsigned long int> tf_4_array_2 = {4912995976923188723UL, 15378815545446818053UL, 11217254324861482540UL, 11251006053860652111UL, 868530561296101260UL};
std::vector<unsigned long int> tf_4_array_3 = {3283396245524818041UL, 10424003985564852459UL, 2236861855356995633UL, 5100159776495594106UL, 1719841661633513016UL, 9080542665918696788UL};
unsigned long int tf_4_array_4 [3] = {14169724813809722557UL, 13019443696763990053UL, 3134889305102589194UL};
std::vector<unsigned long long int> tf_4_array_5 = {1278243167962497401ULL, 10720243501052533062ULL, 8706128925911526745ULL, 17119554763526543276ULL, 10095431117064834681ULL, 1058444111714384467ULL};
unsigned long long int tf_4_array_6 [7] = {17584987306556012119ULL, 4069601957221873258ULL, 13533345329528771982ULL, 10461959347338041386ULL, 12373925672407881126ULL, 15501615466595401105ULL, 2324009584269055647ULL};


std::vector<unsigned long int> tf_4_array_7 = {10231707463833594725UL, 11890708191439265088UL, 8536326504707866746UL, 4010519835435284453UL, 11728260249462301448UL, 8902259887835970274UL};
std::vector<unsigned long int> tf_4_array_8 = {9377751364371547096UL, 1488498260417270863UL, 11789355698793695159UL, 3026040029775613482UL, 16035026629731023975UL, 737622420444783044UL};


unsigned long long int tf_4_array_9 [7] = {11895665214150710007ULL, 14596583780914171462ULL, 12457815520852956021ULL, 1464212131832708376ULL, 16637301785662234126ULL, 1726976665857448588ULL, 2600770647171520820ULL};
unsigned long int tf_4_array_10 [3] = {7259177179622831969UL, 14323643065182092286UL, 2250487620640620742UL};
unsigned long int tf_4_array_11 [3] = {7975395655145005922UL, 13435147153347900748UL, 7241256232240511919UL};
unsigned long long int tf_4_array_12 [7] = {8357558307269654614ULL, 5679870397890922916ULL, 5941908176981660950ULL, 6649552536960945292ULL, 12895245857239990283ULL, 12300973538707397188ULL, 2280616156019627439ULL};
std::vector<unsigned long int> tf_4_array_13 = {1345710443228499382UL, 16380332166612669551UL, 12216016618177678436UL, 17334842046624934835UL, 1241937427286615762UL};
unsigned long long int tf_4_array_14 [7] = {5924557495649919694ULL, 10262271959997321861ULL, 7584952229586351278ULL, 7994384365553623148ULL, 12598829803053269605ULL, 12527164521646505830ULL, 1830077703186918151ULL};
std::vector<unsigned long long int> tf_4_array_15 = {3385135284444287314ULL, 10693242585991819779ULL, 1284172606331908619ULL, 16322027835538563304ULL, 316552344339321622ULL, 10865111185978036334ULL};


long int * tf_4_ptr_1 = &(tf_4_var_16);
long int * tf_4_ptr_2 = &(tf_4_var_12);
long int * tf_4_ptr_3 = &(tf_4_var_26);
const unsigned long long int * tf_4_ptr_4 = &(tf_4_var_28);
const unsigned long int * tf_4_ptr_5 = &(tf_4_var_10);
unsigned long long int * tf_4_ptr_6 = &(tf_4_array_6 [4]);
unsigned long int * tf_4_ptr_7 = &(tf_4_array_2 [3]);


long int * tf_4_ptr_8 = &(tf_4_var_62);
long int * * tf_4_ptr_9 = &(tf_4_ptr_8);
long int * tf_4_ptr_10 = &(tf_4_var_60);


unsigned long int * tf_4_ptr_11 = &(tf_4_array_13 [1]);
unsigned long int * tf_4_ptr_12 = &(tf_4_array_10 [0]);
unsigned long int * tf_4_ptr_13 = &(tf_4_array_13 [0]);
unsigned long long int * tf_4_ptr_14 = &(tf_4_array_9 [4]);
unsigned long long int * tf_4_ptr_15 = &(tf_4_array_9 [2]);




void tf_4_init () {
}

void tf_4_checksum () {
    hash(&seed, tf_4_var_42);
    hash(&seed, tf_4_var_44);
    hash(&seed, tf_4_var_46);
    hash(&seed, tf_4_var_48);
    hash(&seed, tf_4_var_50);
    hash(&seed, tf_4_var_52);
    hash(&seed, tf_4_var_54);
    hash(&seed, tf_4_var_56);
    hash(&seed, tf_4_var_58);
    hash(&seed, tf_4_var_60);
    hash(&seed, tf_4_var_62);
    hash(&seed, tf_4_var_64);
    hash(&seed, tf_4_var_66);
    hash(&seed, tf_4_var_68);
    hash(&seed, tf_4_var_70);
    hash(&seed, tf_4_var_72);
    hash(&seed, tf_4_var_74);
    hash(&seed, tf_4_var_76);
    hash(&seed, tf_4_var_78);
    hash(&seed, tf_4_var_80);
    hash(&seed, tf_4_var_82);
    hash(&seed, tf_4_var_232);
    hash(&seed, tf_4_var_286);
    hash(&seed, tf_4_var_374);
    hash(&seed, tf_4_var_382);
    hash(&seed, tf_4_var_450);
    hash(&seed, tf_4_var_518);
    hash(&seed, tf_4_var_736);
    hash(&seed, tf_4_var_774);
    hash(&seed, tf_4_var_832);
    hash(&seed, tf_4_var_836);
    hash(&seed, tf_4_array_7.at(0));
    hash(&seed, tf_4_array_7.at(1));
    hash(&seed, tf_4_array_7 [2]);
    hash(&seed, tf_4_array_7.at(3));
    hash(&seed, tf_4_array_7.at(4));
    hash(&seed, tf_4_array_7 [5]);
    hash(&seed, tf_4_array_8 [0]);
    hash(&seed, tf_4_array_8.at(1));
    hash(&seed, tf_4_array_8 [2]);
    hash(&seed, tf_4_array_8 [3]);
    hash(&seed, tf_4_array_8.at(4));
    hash(&seed, tf_4_array_8 [5]);
    hash(&seed, tf_4_array_9 [0]);
    hash(&seed, tf_4_array_9 [1]);
    hash(&seed, tf_4_array_9 [2]);
    hash(&seed, tf_4_array_9 [3]);
    hash(&seed, tf_4_array_9 [4]);
    hash(&seed, tf_4_array_9 [5]);
    hash(&seed, tf_4_array_9 [6]);
    hash(&seed, tf_4_array_10 [0]);
    hash(&seed, tf_4_array_10 [1]);
    hash(&seed, tf_4_array_10 [2]);
    hash(&seed, tf_4_array_11 [0]);
    hash(&seed, tf_4_array_11 [1]);
    hash(&seed, tf_4_array_11 [2]);
    hash(&seed, tf_4_array_12 [0]);
    hash(&seed, tf_4_array_12 [1]);
    hash(&seed, tf_4_array_12 [2]);
    hash(&seed, tf_4_array_12 [3]);
    hash(&seed, tf_4_array_12 [4]);
    hash(&seed, tf_4_array_12 [5]);
    hash(&seed, tf_4_array_12 [6]);
    hash(&seed, tf_4_array_13 [0]);
    hash(&seed, tf_4_array_13 [1]);
    hash(&seed, tf_4_array_13.at(2));
    hash(&seed, tf_4_array_13 [3]);
    hash(&seed, tf_4_array_13 [4]);
    hash(&seed, tf_4_array_14 [0]);
    hash(&seed, tf_4_array_14 [1]);
    hash(&seed, tf_4_array_14 [2]);
    hash(&seed, tf_4_array_14 [3]);
    hash(&seed, tf_4_array_14 [4]);
    hash(&seed, tf_4_array_14 [5]);
    hash(&seed, tf_4_array_14 [6]);
    hash(&seed, tf_4_array_15.at(0));
    hash(&seed, tf_4_array_15.at(1));
    hash(&seed, tf_4_array_15 [2]);
    hash(&seed, tf_4_array_15 [3]);
    hash(&seed, tf_4_array_15.at(4));
    hash(&seed, tf_4_array_15.at(5));
    hash(&seed, *(tf_4_ptr_8));
    hash(&seed, *(*(tf_4_ptr_9)));
    hash(&seed, *(tf_4_ptr_10));
    hash(&seed, *(tf_4_ptr_11));
    hash(&seed, *(tf_4_ptr_12));
    hash(&seed, *(tf_4_ptr_13));
    hash(&seed, *(tf_4_ptr_14));
    hash(&seed, *(tf_4_ptr_15));
}

extern void tf_4_foo ();


int main () {
    tf_0_init ();
    tf_0_foo ();
    tf_0_checksum ();

    tf_1_init ();
    tf_1_foo ();
    tf_1_checksum ();

    tf_2_init ();
    tf_2_foo ();
    tf_2_checksum ();

    tf_3_init ();
    tf_3_foo ();
    tf_3_checksum ();

    tf_4_init ();
    tf_4_foo ();
    tf_4_checksum ();

    printf("%llu\n", seed);
    return 0;
}
