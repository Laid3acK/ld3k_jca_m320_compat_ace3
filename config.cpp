class CfgPatches
{
    class ld3k_jca_m320_compat_ace3
    {
        requiredAddons[]=
        {
            "weapons_f_JCA_LRR_LongRangeRifles_M320"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    class BulletBase;
    /*class B_408_Ball: BulletBase // official BI tool All-in-one Config Arma3 2.19.152469 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        hit=24;
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_127";
        visibleFire=5;
        audibleFire=120;
        visibleFireTime=3;
        cost=7;
        airLock=1;
        caliber=2.4; // 0.36 lb/in2
        typicalSpeed=910;
        timeToLive=10;
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
        tracerScale=1.2;
        tracerStartTime=0.075;
        tracerEndTime=1;
        airFriction=-0.00048;
        class CamShakeExplode
        {
            power=3.16228;
            duration=0.6;
            frequency=20;
            distance=9.48683;
        };
        class CamShakeHit
        {
            power=10;
            duration=0.4;
            frequency=20;
            distance=1;
        };
    };*/
    class JCA_B_408_419gr_Ball: BulletBase // https://cheytac.com/product/cheytac-match-grade-ammunition/
    {
        ACE_caliber=10.36; // CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-i/408-chey-tac-en.pdf
        ACE_bulletLength=55.19; // 2.173" https://www.jbmballistics.com/
        ACE_bulletMass=27.151; // 419 gr
        ACE_transonicStabilityCoef=1;
        ACE_muzzleVelocityVariationSD=0.2;
        ACE_ammoTempMuzzleVelocityShifts[]={-18.7,-18.2,-16.6,-14,-10.4,-5.7,0,6.8,14.6,23.4,33.3}; // Same curve default ACE_ammoTempMuzzleVelocityShifts. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        ACE_ballisticCoefficients[]={0.949};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={869}; // 2850fps
        ACE_barrelLengths[]={736.6};
        hit=21.9; // 10253 Joules, B_408_Ball 24 11244 Joules
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_127";
        visibleFire=5;
        audibleFire=120;
        visibleFireTime=3;
        cost=7;
        airLock=1;
        caliber=2.4; // SD 0.36 lb/in2, CheyTac INTERVENTION System https://usarmorment.com/pdf/cheytac408.pdf#page=7: "It will penetrate 1” cold rolled steel at 200 yds, and .5” cold rolled at 850 yds."
        // 25.4mm 183m 809m/s caliber ~2.1, 12.7mm 777m 630m/s caliber ~1.35. Perforation in-game 23mm RHA "armour_plate_23mm.bisurf" ~810m/s: caliber ~1.89. Perforation in-game 12mm RHA "armour_plate_12mm.bisurf" ~630m/s: caliber ~1.27
        typicalSpeed=869; // 10253 Joules, B_408_Ball 910 11244 Joules
        timeToLive=10;
        model="\A3\Weapons_f\Data\bullettracer\tracer_white"; // B_408_Ball tracer_green
        tracerScale=1.2;
        tracerStartTime=0.075;
        tracerEndTime=1;
        nvgOnly=0; // B_408_Ball w/o nvgOnly
        airFriction=-0.00042608; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        class CamShakeExplode
        {
            power=3.16228;
            duration=0.6;
            frequency=20;
            distance=9.48683;
        };
        class CamShakeHit
        {
            power=10;
            duration=0.4;
            frequency=20;
            distance=1;
        };
    };
    class JCA_B_408_419gr_Ball_Tracer_Red: JCA_B_408_419gr_Ball
    {
        visibleFire=8; // B_127x99_Ball_Tracer_Red, B_408_Ball 5
        model="\A3\Weapons_f\Data\bullettracer\tracer_Red";
        tracerStartTime=0.23; // No .408 tracer data, based on 12.7x99 Tracer visible 200m 1500m 43g MV 903m/s ICAO according to https://www.nammo.com, ToF 200m 0.23s (Strelok Pro)
        tracerEndTime=2.71; // No .408 tracer data, based on 12.7x99 Tracer visible 200m 1500m 43g MV 903m/s ICAO according to https://www.nammo.com, ToF 1500m 2.71s (Strelok Pro)
    };
    class JCA_B_408_419gr_Ball_Tracer_IR: JCA_B_408_419gr_Ball
    {
        tracerScale=0.6; // IR dim tracer
        tracerStartTime=0.02; // No .408 dim tracer IR data, based on 7.62x51 IR Dim Tracer visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 13m 0.02s (Strelok Pro)
        tracerEndTime=3.03; // No .408 dim tracer IR data, based on 7.62x51 IR Dim Tracer visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 1250m 3.03s (Strelok Pro)
        nvgOnly=1;
    };
    class JCA_B_408_305gr_Ball: JCA_B_408_419gr_Ball
    {
        ACE_bulletLength=41.45; // 1.632" https://www.jbmballistics.com/
        ACE_bulletMass=19.764; // 305 gr
        ACE_ballisticCoefficients[]={0.612}; // http://lutzmoeller.net/Ballistik/A-Ballistic-Coefficient-Discussion-with-Lost_River.php
        ACE_muzzleVelocities[]={1067}; // 3500fps https://usarmorment.com/pdf/cheytac408.pdf#page=19
        hit=24; // 11252 Joules, B_408_Ball 24 11244 Joules
        caliber=1.75; // SD 0.262 lb/in2
        typicalSpeed=1067; // 11252 Joules, B_408_Ball 910 11244 Joules
        airFriction=-0.00062734; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_408_305gr_Ball_Tracer_Red: JCA_B_408_305gr_Ball
    {
        visibleFire=8; // B_127x99_Ball_Tracer_Red, B_408_Ball 5
        model="\A3\Weapons_f\Data\bullettracer\tracer_Red";
        tracerStartTime=0.23; // No .408 tracer data, based on 12.7x99 Tracer visible 200m 1500m 43g MV 903m/s ICAO according to https://www.nammo.com, ToF 200m 0.23s (Strelok Pro)
        tracerEndTime=2.71; // No .408 tracer data, based on 12.7x99 Tracer visible 200m 1500m 43g MV 903m/s ICAO according to https://www.nammo.com, ToF 1500m 2.71s (Strelok Pro)
    };
    class JCA_B_408_305gr_Ball_Tracer_IR: JCA_B_408_305gr_Ball
    {
        tracerScale=0.6; // IR dim tracer
        tracerStartTime=0.02; // No .408 dim tracer IR data, based on 7.62x51 IR Dim Tracer visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 13m 0.02s (Strelok Pro)
        tracerEndTime=3.03; // No .408 dim tracer IR data, based on 7.62x51 IR Dim Tracer visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 1250m 3.03s (Strelok Pro)
        nvgOnly=1;
    };
    class JCA_B_408_450gr_AP_Ball: JCA_B_408_419gr_Ball // SBR .408 450gr Armor Piercing https://www.sbrammunition.com/assets/images/M408-450.pdf
    {
        ACE_bulletLength=57.3; // 2.256" Cutting Edge 450gr G1 BC 0.865 https://www.jbmballistics.com/ https://cuttingedgebullets.com/
        ACE_bulletMass=29.16; // 450 gr
        ACE_transonicStabilityCoef=0.5; // ACE3 default value https://github.com/acemod/ACE3/blob/24e57825f7e75822e936282b36a3929bae189338/addons/advanced_ballistics/functions/fnc_readAmmoDataFromConfig.sqf#L40
        ACE_muzzleVelocityVariationSD=0.3; // ACE3 default value https://github.com/acemod/ACE3/blob/master/addons/advanced_ballistics/script_component.hpp#L32
        ACE_ballisticCoefficients[]={1.009}; // https://www.sbrammunition.com/assets/images/M408-450.pdf
        ACE_muzzleVelocities[]={808}; // 2650fps https://www.sbrammunition.com/assets/images/M408-450.pdf
        hit=20.3; // 9520 Joules, B_408_Ball 24 11244 Joules
        caliber=2.6; // SD 0.386 lb/in2, tungsten carbide core, SBR Precision Ammunition penetration 12mm 600m, perforation in-game 12mm RHA "armour_plate_12mm.bisurf" ~640m/s: caliber ~1.25
        typicalSpeed=808; // 9520 Joules, B_408_Ball 910 11244 Joules
        airFriction=-0.00040889; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_408_375gr_API_Ball: JCA_B_408_419gr_Ball // Extreme Performance .408 375gr Armor Piercing Incendiary https://www.jbmballistics.com/
    {
        ACE_bulletLength=51.94; // 2.045" https://www.jbmballistics.com/
        ACE_bulletMass=24.3; // 375 gr
        ACE_transonicStabilityCoef=0.5; // ACE3 default value https://github.com/acemod/ACE3/blob/24e57825f7e75822e936282b36a3929bae189338/addons/advanced_ballistics/functions/fnc_readAmmoDataFromConfig.sqf#L40
        ACE_muzzleVelocityVariationSD=0.3; // ACE3 default value https://github.com/acemod/ACE3/blob/master/addons/advanced_ballistics/script_component.hpp#L32
        ACE_ballisticCoefficients[]={0.8}; // ASM G1 0.8 converted to ICAO G1 0.7895 for airFriction calculation (ICAO 0.789467) https://www.jbmballistics.com/
        ACE_standardAtmosphere="ASM";
        ACE_muzzleVelocities[]={945}; // 3100fps
        ace_vehicle_damage_incendiary=1;
        hit=39.1; // anti-material, 24x1.69x0.965, average ratio anti-material/anti-personal B_127x99_SLAP/B_127x99_Ball and B_127x108_APDS/B_127x108_Ball "hit": 1.69. Energy ratio JCA_B_408_375gr_API_Ball/B_408_Ball: 0.965
        indirectHit=4; // B_20mm_AP 8
        indirectHitRange=0.1; // B_20mm_AP 0.2
        caliber=2.1; // SD 0.322 lb/in2, tungsten carbide core, titanium tip, no incendiary chemicals
        typicalSpeed=945; // 10852 Joules, B_408_Ball 910 11244 Joules
        airFriction=-0.00050064; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        CraterEffects="ExploAmmoCrater"; // ammo_Penetrator_Base
        class HitEffects // B_30mm_APFSDS. Observable flash at hard targets. Ignition of vaporized fuel https://www.nammo.com
        {
            hitMetal="ImpactMetalSabotSmall";
            hitMetalPlate="ImpactMetalSabotSmall";
            hitBuilding="ImpactConcreteSabotSmall";
            hitConcrete="ImpactConcreteSabotSmall";
            hitGroundSoft="ImpactEffectsGroundSabot";
            hitGroundRed="ImpactEffectsGroundSabot"; // BulletBase ImpactEffectsRed
            hitGroundHard="ImpactEffectsGroundSabot";
            Hit_Foliage_green="ImpactLeavesGreen";
            Hit_Foliage_Dead="ImpactLeavesDead";
            Hit_Foliage_Green_big="ImpactLeavesGreenBig";
            Hit_Foliage_Palm="ImpactLeavesPalm";
            Hit_Foliage_Pine="ImpactLeavesPine";
            hitFoliage="ImpactLeaves";
            hitGlass="ImpactGlass";
            hitGlassArmored="ImpactGlassThin";
            hitWood="ImpactWood";
            hitHay="ImpactHay";
            hitPlastic="ImpactPlastic";
            hitRubber="ImpactRubber";
            hitTyre="ImpactTyre";
            hitMan="ImpactEffectsBlood";
            hitWater="ImpactEffectsWater";
            hitVirtual="ImpactMetal"; // BulletBase
            default_mat="ImpactEffectsGroundSabot";
        };
    };
};
class CfgMagazines
{
    class CA_Magazine;
    /* To avoid all conflict with other mods, all 7Rnd_408_Mags with JCA as prefixe
    class 7Rnd_408_Mag: CA_Magazine // official BI tool All-in-one Config Arma3 2.19.152232 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        author="$STR_A3_Bohemia_Interactive";
        scope=2;
        displayName="$STR_A3_CFGMAGAZINES_7RND_408_MAG0";
        picture="\A3\weapons_f\data\UI\m_M24_CA.paa";
        count=7;
        ammo="B_408_Ball";
        initSpeed=910;
        descriptionShort="$STR_A3_CFGMAGAZINES_7RND_408_MAG1";
        mass=14;
    };
    class 7Rnd_408_Mag: CA_Magazine // JCA config
    {
        author="$STR_A3_Bohemia_Interactive";
        scope=2;
        displayName="$STR_A3_CFGMAGAZINES_7RND_408_MAG0";
        picture="\weapons_f_JCA_LRR\LongRangeRifles\M320\data\UI\icon_mag_408.paa";
        count=7;
        ammo="B_408_Ball";
        initSpeed=910;
        descriptionShort="$STR_A3_CFGMAGAZINES_7RND_408_MAG1";
        mass=14;
    };*/
    class JCA_7Rnd_408_419gr_Mag: CA_Magazine
    {
        author="Grave";
        scope=2;
        displayName=".408 7Rnd 419gr Mag";
        picture="\weapons_f_JCA_LRR\LongRangeRifles\M320\data\UI\icon_mag_408.paa";
        count=7;
        ammo="JCA_B_408_419gr_Ball";
        initSpeed=869; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        descriptionShort="Caliber: .408<br />Rounds: 7<br />Used in: M320 LRR";
        mass=15; // 1.5 lbs, 680g https://cheytac.com/product/m200-m300-magazines-2/
    };
    class JCA_7Rnd_408_419gr_Mag_Tracer_Red: JCA_7Rnd_408_419gr_Mag
    {
        author="Grave";
        displayName=".408 7Rnd 419gr Tracer (Red) Mag";
        ammo="JCA_B_408_419gr_Ball_Tracer_Red";
        tracersEvery=1;
        displaynameshort="Tracer";
    };
    class JCA_7Rnd_408_419gr_Mag_Tracer_IR: JCA_7Rnd_408_419gr_Mag_Tracer_Red
    {
        author="Grave";
        displayName=".408 7Rnd 419gr Tracer (IR) Mag";
        ammo="JCA_B_408_419gr_Ball_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_7Rnd_408_305gr_Mag: JCA_7Rnd_408_419gr_Mag
    {
        author="Grave";
        displayName=".408 7Rnd 305gr Mag";
        ammo="JCA_B_408_305gr_Ball";
        initSpeed=1067; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_7Rnd_408_305gr_Mag_Tracer_Red: JCA_7Rnd_408_305gr_Mag
    {
        author="Grave";
        displayName=".408 7Rnd 305gr Tracer (Red) Mag";
        ammo="JCA_B_408_305gr_Ball_Tracer_Red";
        tracersEvery=1;
        displaynameshort="Tracer";
    };
    class JCA_7Rnd_408_305gr_Mag_Tracer_IR: JCA_7Rnd_408_305gr_Mag_Tracer_Red
    {
        author="Grave";
        displayName=".408 7Rnd 305gr Tracer (IR) Mag";
        ammo="JCA_B_408_305gr_Ball_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_7Rnd_408_450gr_AP_Mag: JCA_7Rnd_408_419gr_Mag
    {
        author="Grave";
        displayName=".408 7Rnd 450gr AP Mag";
        ammo="JCA_B_408_450gr_AP_Ball";
        initSpeed=808; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="AP";
    };
    class JCA_7Rnd_408_375gr_API_Mag: JCA_7Rnd_408_419gr_Mag
    {
        author="Grave";
        displayName=".408 7Rnd 375gr API Mag";
        ammo="JCA_B_408_375gr_API_Ball";
        initSpeed=945; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="API";
    };
};
class CfgMagazineWells
{
    class M320_408
    {
        JCA_Magazines[]= // Weapon initSpeed -1 ACE_barrelLength 736.6mm (29"): 869, 1067, 808, 945m/s ICAO conditions (15°C, 1013.25 hPa, 0%) according to JCA_7Rnd_408 magazines initSpeed
        {
            "JCA_7Rnd_408_419gr_Mag",
            "JCA_7Rnd_408_419gr_Mag_Tracer_Red",
            "JCA_7Rnd_408_419gr_Mag_Tracer_IR",
            "JCA_7Rnd_408_305gr_Mag",
            "JCA_7Rnd_408_305gr_Mag_Tracer_Red",
            "JCA_7Rnd_408_305gr_Mag_Tracer_IR",
            "JCA_7Rnd_408_450gr_AP_Mag",
            "JCA_7Rnd_408_375gr_API_Mag"
        };
    };
};
class CfgWeapons
{
    class Rifle_Long_Base_F;
    class LRR_base_F: Rifle_Long_Base_F
    {
        maxZeroing=3100; // distance .408 CheyTac 419gr and 450gr AP Mach 0.8 (272m/s) ICAO, LRR_base_F 2400
        initSpeed=-1; // 869, 1067, 808, 945m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), LRR_base_F 910
    };
};
class ACE_ATragMX_Presets
{
    class ld3k_JCA_B_408_419gr_Ball
    {
        preset[]=
        {
            "JCA M320 419gr",
            869,
            100,
            0.0805291,
            -0.00042608,
            7.37,
            0,
            2,
            10,
            120,
            0,
            0,
            27.151,
            10.02,
            33.02,
            0.949,
            1,
            "ICAO",

            {
                {-15,850},
                {0,855},
                {10,863},
                {15,869},
                {25,884},
                {30,892},
                {35,902}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
    class ld3k_JCA_B_408_305gr_Ball
    {
        preset[]=
        {
            "JCA M320 305gr",
            1067,
            100,
            0.0680144,
            -0.00062734,
            7.37,
            0,
            2,
            10,
            120,
            0,
            0,
            19.764,
            9.91,
            33.02,
            0.612,
            1,
            "ICAO",

            {
                {-15,1048},
                {0,1053},
                {10,1061},
                {15,1067},
                {25,1082},
                {30,1090},
                {35,1100}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
    class ld3k_JCA_B_408_450gr_AP_Ball
    {
        preset[]=
        {
            "JCA M320 AP",
            808,
            100,
            0.0864878,
            -0.00040889,
            7.37,
            0,
            2,
            10,
            120,
            0,
            0,
            29.16,
            10.15,
            33.02,
            1.009,
            1,
            "ICAO",

            {
                {-15,789},
                {0,794},
                {10,802},
                {15,808},
                {25,823},
                {30,831},
                {35,841}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
    class ld3k_JCA_B_408_375gr_API_Ball
    {
        preset[]=
        {
            "JCA M320 API",
            945,
            100,
            0.074771,
            -0.00050064,
            7.37,
            0,
            2,
            10,
            120,
            0,
            0,
            24.3,
            9.82,
            33.02,
            0.8,
            1,
            "ASM",

            {
                {-15,926},
                {0,931},
                {10,939},
                {15,945},
                {25,960},
                {30,968},
                {35,978}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
};