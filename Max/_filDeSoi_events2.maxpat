{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 1,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 1065.0, 436.0, 1461.0, 883.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1200.5, 608.5, 49.5, 20.0 ],
					"style" : "",
					"text" : "evt21"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1030.0, 428.0, 49.5, 20.0 ],
					"style" : "",
					"text" : "evt20"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1030.0, 450.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "mesure 110"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"linecount" : 8,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1142.0, 409.0, 141.0, 116.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.6;\rtoMTap hStretch 0.6;\rtoMTap setFd 13 0.4;\rtoMTap wHarmo 24;\rtoMTap displayAll;\rdirectGuitare_level 105;\rrenv8_level 100;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 313.5, 674.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "nouveau 14"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 162.0, 674.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "nouveau 13"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 300.5, 698.0, 127.0, 49.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.6;\rtoMTap setFd 13 0.2;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 162.0, 698.0, 127.0, 49.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.7;\rtoMTap setFd 13 0.4;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 922.0, 78.0, 171.0, 33.0 ],
					"style" : "",
					"text" : "evt 31 = evt 21, 32 = 4, 33 = 3, 34 = 2, 35 = 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-111",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1174.5, 815.0, 127.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.5;\rtoMTap hStretch 0.7;\rtoMTap setFd 13 0.1;\rtoMTap wHarmo 30;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-113",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1032.0, 800.0, 131.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 1.5;\rtoMTap hStretch 0.65;\rtoMTap setFd 13 0.9;\rtoMTap wHarmo 28;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-108",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1187.0, 793.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt30"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-109",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 890.0, 800.0, 133.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 1.4;\rtoMTap hStretch 0.6;\rtoMTap setFd 13 0.85;\rtoMTap wHarmo 26;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-64",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1040.5, 780.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt29"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-80",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 749.0, 800.0, 131.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 1.3;\rtoMTap hStretch 0.55;\rtoMTap setFd 13 0.8;\rtoMTap wHarmo 24;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-106",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 897.5, 775.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt28"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-105",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 615.0, 796.0, 127.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 1.2;\rtoMTap hStretch 0.5;\rtoMTap setFd 13 0.7;\rtoMTap wHarmo 22;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-94",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 755.5, 775.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt27"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-86",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 475.5, 796.0, 131.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 1.1;\rtoMTap hStretch 0.45;\rtoMTap setFd 13 0.6;\rtoMTap wHarmo 20;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-77",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 615.0, 780.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt26"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-128",
					"linecount" : 4,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 203.0, 793.5, 131.0, 62.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.9;\rtoMTap hStretch 0.35;\rtoMTap setFd 13 0.4;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-124",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 203.0, 771.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt23"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-116",
					"linecount" : 11,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1171.0, 631.5, 134.0, 156.0 ],
					"style" : "",
					"text" : ";\rtoMTap setOut 12 1.;\rtoMTap tStretch 0.8;\rtoMTap hStretch -1;\rtoMTap setFd 13 0.34;\rtoMTap wHarmo 20;\rtoMTap displayAll;\rrenv8_freq 17;\rrenv8_level 127;\rdirectGuitare_level 40;\rmTDel_level 127;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-110",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 482.0, 775.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt25"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-112",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 350.0, 775.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt24"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 345.5, 793.5, 127.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 1;\rtoMTap hStretch 0.4;\rtoMTap setFd 13 0.5;\rtoMTap wHarmo 18;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"linecount" : 9,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 25.0, 793.5, 175.0, 129.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.8;\rtoMTap hStretch 0.3;\rtoMTap setFd 13 0.3;\rtoMTap wHarmo 16;\rdirectGuitare_level 100;\rtoMTap smoothDuration 3000;\rrenv8_level 127;\rrenv8_freq 4;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 41.0, 771.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt22"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1040.5, 631.5, 127.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.8;\rtoMTap hStretch 0.3;\rtoMTap setFd 13 0.4;\rtoMTap wHarmo 22;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-39",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1045.0, 612.25, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt19"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 904.0, 612.25, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt18"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 904.0, 631.5, 131.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.7;\rtoMTap hStretch 0.25;\rtoMTap setFd 13 0.5;\rtoMTap wHarmo 22;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-123",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 637.5, 608.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt16"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-34",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 771.5, 608.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt17"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 767.0, 627.75, 127.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.6;\rtoMTap hStretch 0.2;\rtoMTap setFd 13 0.6;\rtoMTap wHarmo 20;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 631.0, 627.75, 131.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.5;\rtoMTap hStretch 0.15;\rtoMTap setFd 13 0.7;\rtoMTap wHarmo 18;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-126",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 464.0, 608.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt15"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-91",
					"linecount" : 8,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 459.0, 626.0, 161.0, 116.0 ],
					"style" : "",
					"text" : ";\rtoMTap smoothDuration 50;\rtoMTap tStretch 0.4;\rtoMTap hStretch 0.1;\rtoMTap setFd 13 0.4;\rtoMTap setFd 13 0.8;\rdirectGuitare_level 85;\rrenv8_level 80;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-122",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 316.0, 608.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt12"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-119",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 316.0, 626.0, 127.0, 49.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.8;\rtoMTap setFd 13 0.4;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-121",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 171.0, 605.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt11"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-118",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 171.0, 626.0, 127.0, 49.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 1.2;\rtoMTap setFd 13 0.6;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-120",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 32.0, 604.0, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt10"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-117",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 32.0, 626.0, 127.0, 49.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 1;\rtoMTap setFd 13 0.4;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 36,
					"numoutlets" : 36,
					"outlettype" : [ "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "" ],
					"patching_rect" : [ 25.0, 65.0, 549.0, 22.0 ],
					"style" : "",
					"text" : "sel 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-115",
					"linecount" : 9,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1039.5, 158.0, 161.0, 129.0 ],
					"style" : "",
					"text" : ";\rtoMTap smoothDuration 10;\rtoMTap tStretch 0.8;\rtoMTap hStretch -2;\rtoMTap setFd 13 0.2;\rtoMTap wHarmo 22;\rdirectGuitare_level 40;\rrenv8_level 127;\rrenv8_freq 17;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-103",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1044.0, 138.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt9"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-102",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 908.0, 136.0, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt8"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-90",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 908.0, 158.0, 128.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.75;\rtoMTap hStretch 3;\rtoMTap setFd 13 0.6;\rrenv8_level 127;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-101",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 749.5, 136.5, 134.0, 20.0 ],
					"style" : "",
					"text" : "evt7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-100",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 588.5, 136.5, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt6"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-89",
					"linecount" : 16,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 750.0, 158.0, 153.0, 223.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 1.5;\rtoMTap hStretch 2;\rtoMTap setFd 13 0.3;\rtoMTap wHarmo 24;\rrenv8_level 115;\rdirectGuitare_level 100;\rmTDel_level 127;\rtoMTap setFdMat 13 0 1;\rtoMTap setFdMat 13 1 1;\rtoMTap setFdMat 13 2 1;\rtoMTap setFdMat 13 4 1;\rtoMTap setFdMat 13 12 1;\rtoMTap setFdMat 13 13 1;\rtoMTap setFdMat 13 14 1;\rtoMTap setFdMat 13 15 1;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-88",
					"linecount" : 18,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 588.5, 158.0, 153.0, 250.0 ],
					"style" : "",
					"text" : ";\rtoSpatConfig 2;\rtoMTap tStretch 1.5;\rtoMTap hStretch -0.5;\rtoMTap setFd 13 0.;\rtoMTap wHarmo 24;\rrenv8_level 100;\rrenv8_freq 8;\rdirectGuitare_level 120;\rmTDel_level 120;\rtoMTap setFdMat 13 0 0;\rtoMTap setFdMat 13 1 0;\rtoMTap setFdMat 13 2 0;\rtoMTap setFdMat 13 4 0;\rtoMTap setFdMat 13 12 0;\rtoMTap setFdMat 13 13 0;\rtoMTap setFdMat 13 14 0;\rtoMTap setFdMat 13 15 0;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-99",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 473.0, 478.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt5"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-98",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 338.0, 478.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-97",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 184.0, 478.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-95",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 32.0, 478.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-87",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 473.0, 500.0, 133.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.8;\rtoMTap hStretch -1;\rtoMTap setFd 13 0.34;\rtoMTap wHarmo 20;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-85",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 338.0, 500.0, 127.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.8;\rtoMTap hStretch 2;\rtoMTap setFd 13 0.4;\rtoMTap wHarmo 22;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 184.0, 500.0, 121.0, 49.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.7;\rtoMTap wHarmo 24;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 32.0, 500.0, 128.0, 49.0 ],
					"style" : "",
					"text" : ";\rtoMTap tStretch 0.75;\rtoMTap wHarmo 22;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 25.0, 115.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-41",
					"linecount" : 24,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 25.0, 137.0, 542.0, 330.0 ],
					"style" : "",
					"text" : ";\rtoMTap setDuration 300 425 800 925 1300 1800 2000 2300 200 500 600 1000 3000 2500 700 300;\rtoMTap setTransposition 13 50;\rtoMTap setFd 13 0;\rtoMTap tStretch 0.8;\rtoMTap hStretch 4;\rtoMTap wHarmo 24;\rtoMTap setFd 10 0.2;\rtoMTap setOut 0.6 0.6 0.5 0 0.5 0 1 0 0 0 0 0 0.5 0.3 0.5 0.5;\rtoMTap setFdMat 13 0 1;\rtoMTap setFdMat 13 1 1;\rtoMTap setFdMat 13 2 1;\rtoMTap setFdMat 13 4 1;\rtoMTap setFdMat 13 6 1;\rtoMTap setFdMat 13 12 1;\rtoMTap setFdMat 13 13 1;\rtoMTap setFdMat 13 14 1;\rtoMTap setFdMat 13 15 1;\rtoMTap smoothDuration 50;\rrenv8_freq 17;\rrenv8_level 127;\rdirectGuitare_level 40;\rmTDel_level 127;\rtoSpatConfig 1;\r"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-1",
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 25.0, 22.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 25 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-109", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 27 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 16 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-111", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 29 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-113", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 28 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-115", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 8 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-116", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 30 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-116", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 20 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-117", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 9 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-118", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 10 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-119", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 11 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-128", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 22 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 19 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 33 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 21 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 17 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 15 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 32 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 12 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 34 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 18 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 13 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-71", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 23 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-80", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 26 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 31 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-86", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 24 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 5 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-89", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 6 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 7 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-91", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 14 ]
				}

			}
 ],
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
