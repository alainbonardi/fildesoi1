{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 3,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 1026.0, 323.0, 1820.0, 1220.0 ],
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
					"id" : "obj-33",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 247.0, 225.0, 60.0, 35.0 ],
					"style" : "",
					"text" : ";\rtoMsg _;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 502.0, 303.0, 217.0, 35.0 ],
					"style" : "",
					"text" : ";\rtoMsg Turn_micro_off_in_5_s_M_key;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 497.5, 448.0, 179.0, 35.0 ],
					"style" : "",
					"text" : ";\rtoMsg Turn_page_at_next_evt;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-31",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 444.5, 382.0, 152.0, 35.0 ],
					"style" : "",
					"text" : ";\rtoMsg Turns_page_in_3s;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 275.0, 382.0, 152.0, 35.0 ],
					"style" : "",
					"text" : ";\rtoMsg Turns_page_in_8s;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 53.333328, 45.0, 75.0, 22.0 ],
					"style" : "",
					"text" : "s tr_evtNum"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"linecount" : 12,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1487.0, 180.0, 98.0, 169.0 ],
					"style" : "",
					"text" : ";\rtoMT fd00 0.99;\rtoMT fd01 0.99;\rtoMT fd02 0.99;\rtoMT fd03 0.99;\rtoMT fd04 0.99;\rtoMT fd05 0.99;\rtoMT fd06 0.99;\rtoMT fd07 0.99;\rtoMT fd12 0.99;\rtoMT fd14 0.99;\rtoMT fd15 0.99;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"linecount" : 12,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1389.0, 180.0, 91.0, 169.0 ],
					"style" : "",
					"text" : ";\rtoMT fd00 0.9;\rtoMT fd01 0.9;\rtoMT fd02 0.9;\rtoMT fd03 0.9;\rtoMT fd04 0.9;\rtoMT fd05 0.9;\rtoMT fd06 0.9;\rtoMT fd07 0.9;\rtoMT fd12 0.9;\rtoMT fd14 0.9;\rtoMT fd15 0.9;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"linecount" : 13,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1490.0, 678.5, 149.0, 183.0 ],
					"style" : "",
					"text" : ";\rtoSpatConfig 1;\rtoMT out12 1.;\rtoMT dStretch 0.8;\rtoMT hStretch -1;\rtoMT fd13 0.34;\rtoMT hWin 20;\rrenv8_freq 17;\rrenv8_level 127;\rdirectGuitare_level 40;\rmTDel_level 127;\rrStretch -0.4;\rtoMT smoothDuration 10;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 29.333332, 108.333328, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt37"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 196.0, 518.0, 120.5, 20.0 ],
					"style" : "",
					"text" : "evt36"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 348.0, 518.0, 120.5, 20.0 ],
					"style" : "",
					"text" : "evt35"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 502.0, 518.0, 120.5, 20.0 ],
					"style" : "",
					"text" : "evt34"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1497.5, 655.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt33"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1342.0, 876.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt32"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1199.5, 861.0, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt31"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 509.5, 767.75, 112.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.2;\rtoMT fd13 0.4;\rrStretch 1.5;\rtoMT hStretch -2;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1204.5, 667.5, 49.5, 20.0 ],
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
					"patching_rect" : [ 1072.0, 667.5, 49.5, 20.0 ],
					"style" : "",
					"text" : "evt20"
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
					"patching_rect" : [ 1306.0, 444.0, 141.0, 116.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.6;\rtoMT hStretch 0.6;\rtoMT fd13 0.4;\rtoMT hWin 24;\rdirectGuitare_level 105;\rrenv8_level 100;\rrStretch -0.8;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 375.0, 745.75, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt14"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 269.0, 745.75, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt 13"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 385.5, 768.0, 116.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 2.;\rtoMT fd13 0.1;\rrStretch 1.;\rtoMT hStretch -2.5;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 258.0, 768.0, 116.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1.;\rtoMT fd13 0.2;\rrStretch 0.8;\rtoMT hStretch -2.2;\r"
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
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1334.5, 898.0, 112.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.5;\rtoMT hStretch 0.7;\rtoMT fd13 0.1;\rtoMT hWin 30;\rrStretch 0.15;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-113",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1192.0, 883.0, 119.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1.5;\rtoMT hStretch 0.65;\rtoMT fd13 0.9;\rtoMT hWin 28;\rrStretch -0.2;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-108",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1044.0, 861.0, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt30"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-109",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1050.0, 883.0, 112.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1.4;\rtoMT hStretch 0.6;\rtoMT fd13 0.85;\rtoMT hWin 26;\rrStretch 0.3;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-64",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 909.0, 861.0, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt29"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-80",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 909.0, 883.0, 119.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1.3;\rtoMT hStretch 0.55;\rtoMT fd13 0.8;\rtoMT hWin 24;\rrStretch -0.2;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-106",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 763.5, 858.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt28"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-105",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 775.0, 879.0, 112.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1.2;\rtoMT hStretch 0.5;\rtoMT fd13 0.7;\rtoMT hWin 22;\rrStretch 0.7;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-94",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 633.0, 858.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt27"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-86",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 635.5, 879.0, 119.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1.1;\rtoMT hStretch 0.45;\rtoMT fd13 0.6;\rtoMT hWin 20;\rrStretch -0.3;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-77",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 509.0, 858.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt26"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-128",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 363.0, 876.5, 119.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.9;\rtoMT hStretch 0.35;\rtoMT fd13 0.4;\rrStretch -0.4;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-124",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1329.5, 655.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt23"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-116",
					"linecount" : 12,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1326.0, 678.5, 134.0, 169.0 ],
					"style" : "",
					"text" : ";\rtoSpatConfig 1;\rtoMT out12 1.;\rtoMT dStretch 0.8;\rtoMT hStretch -1;\rtoMT fd13 0.34;\rtoMT hWin 20;\rrenv8_freq 17;\rrenv8_level 127;\rdirectGuitare_level 40;\rmTDel_level 127;\rrStretch -0.4;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-110",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 363.0, 858.5, 118.0, 20.0 ],
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
					"patching_rect" : [ 207.0, 858.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt24"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 505.5, 876.5, 112.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1;\rtoMT hStretch 0.4;\rtoMT fd13 0.5;\rtoMT hWin 18;\rrStretch 0.6;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"linecount" : 11,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 185.0, 876.5, 162.0, 156.0 ],
					"style" : "",
					"text" : ";\rtoSpatConfig 2;\rtoMT dStretch 0.8;\rtoMT hStretch 0.3;\rtoMT fd13 0.3;\rtoMT hWin 16;\rdirectGuitare_level 95;\rrenv8_level 127;\rrenv8_freq 4;\rrStretch 0.5;\rtoMT smoothDuration 3000;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1306.0, 421.833313, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt22"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1204.5, 696.25, 112.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.8;\rtoMT hStretch 0.3;\rtoMT fd13 0.4;\rtoMT hWin 22;\rrStretch 2.;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-39",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 931.0, 667.5, 118.0, 20.0 ],
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
					"patching_rect" : [ 795.0, 667.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt18"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1071.0, 689.75, 119.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.7;\rtoMT hStretch 0.25;\rtoMT fd13 0.5;\rtoMT hWin 22;\rrStretch 1.5;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-123",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 637.0, 518.0, 118.0, 20.0 ],
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
					"patching_rect" : [ 646.5, 667.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt17"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 931.0, 689.75, 112.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.6;\rtoMT hStretch 0.2;\rtoMT fd13 0.6;\rtoMT hWin 20;\rrStretch 1.2;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 795.0, 689.75, 119.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.5;\rtoMT hStretch 0.15;\rtoMT fd13 0.7;\rtoMT hWin 18;\rrStretch 1.;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-126",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 509.5, 745.75, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt15"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-91",
					"linecount" : 9,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 637.0, 688.0, 134.0, 129.0 ],
					"style" : "",
					"text" : ";\rtoSpatConfig 2;\rtoMT dStretch 0.4;\rtoMT hStretch 0.1;\rtoMT fd13 0.4;\rtoMT fd13 0.8;\rdirectGuitare_level 90;\rrenv8_level 90;\rrStretch 0.5;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-122",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 489.0, 644.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt12"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-119",
					"linecount" : 5,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 489.0, 662.0, 123.0, 76.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1.5;\rtoMT fd13 0.4;\rrStretch 0.6;\rtoMT hStretch -2.05;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-121",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 357.0, 641.5, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt11"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-118",
					"linecount" : 4,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 357.0, 662.0, 119.0, 62.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1.2;\rtoMT fd13 0.6;\rrStretch 0.5;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-120",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 197.0, 640.0, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt10"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-117",
					"linecount" : 4,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 185.0, 662.0, 102.0, 62.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1;\rtoMT fd13 0.4;\rrStretch 0.4;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 38,
					"numoutlets" : 38,
					"outlettype" : [ "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "bang", "" ],
					"patching_rect" : [ 25.0, 83.5, 582.0, 22.0 ],
					"style" : "",
					"text" : "sel 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-115",
					"linecount" : 11,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1208.0, 220.0, 142.0, 156.0 ],
					"style" : "",
					"text" : ";\rtoSpatConfig 1;\rtoMT dStretch 0.8;\rtoMT hStretch -2;\rtoMT fd13 0.2;\rtoMT hWin 22;\rdirectGuitare_level 40;\rrenv8_level 120;\rrenv8_freq 17;\rrStretch 0.3;\rtoMT smoothDuration 1;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-103",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1208.0, 200.5, 118.0, 20.0 ],
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
					"patching_rect" : [ 1072.0, 198.0, 118.0, 20.0 ],
					"style" : "",
					"text" : "evt8"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-90",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1072.0, 220.0, 119.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.75;\rtoMT hStretch 3;\rtoMT fd13 0.6;\rrenv8_level 127;\rrStretch 1.5.;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-101",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 913.5, 198.5, 134.0, 20.0 ],
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
					"patching_rect" : [ 752.5, 198.5, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt6"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-89",
					"linecount" : 17,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 913.5, 220.0, 141.0, 236.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 1.5;\rtoMT hStretch 2;\rtoMT fd13 0.3;\rtoMT hWin 24;\rrenv8_level 115;\rdirectGuitare_level 100;\rmTDel_level 127;\rtoMT r013 1;\rtoMT r029 1;\rtoMT r045 1;\rtoMT r077 1;\rtoMT r205 1;\rtoMT r221 1;\rtoMT r237 1;\rtoMT r253 1;\rrStretch 2.;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-88",
					"linecount" : 20,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 752.5, 220.0, 149.0, 277.0 ],
					"style" : "",
					"text" : ";\rtoSpatConfig 2;\rtoMT dStretch 1.5;\rtoMT hStretch -0.5;\rtoMT fd13 0.;\rtoMT hWin 24;\rrenv8_level 100;\rrenv8_freq 8;\rdirectGuitare_level 120;\rmTDel_level 120;\rtoMT r013 0;\rtoMT r029 0;\rtoMT r045 0;\rtoMT r077 0;\rtoMT r205 0;\rtoMT r221 0;\rtoMT r237 0;\rtoMT r253 0;\rrStretch 0.8;\rtoMT smoothDuration 10;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-99",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 637.0, 540.0, 150.0, 20.0 ],
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
					"patching_rect" : [ 502.0, 540.0, 150.0, 20.0 ],
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
					"patching_rect" : [ 348.0, 540.0, 150.0, 20.0 ],
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
					"patching_rect" : [ 196.0, 540.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-87",
					"linecount" : 7,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 637.0, 562.0, 149.0, 102.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.8;\rtoMT hStretch -1;\rtoMT fd13 0.34;\rtoMT hWin 20;\rrStretch -0.4;\rtoMT smoothDuration 30;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-85",
					"linecount" : 6,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 502.0, 562.0, 112.0, 89.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.8;\rtoMT hStretch 2;\rtoMT fd13 0.4;\rtoMT hWin 22;\rrStretch 0.8;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"linecount" : 4,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 348.0, 562.0, 112.0, 62.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.7;\rtoMT hWin 24;\rrStretch 0.4;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"linecount" : 4,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 196.0, 562.0, 119.0, 62.0 ],
					"style" : "",
					"text" : ";\rtoMT dStretch 0.75;\rtoMT hWin 22;\rrStretch 0.3;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 29.333332, 130.333328, 150.0, 20.0 ],
					"style" : "",
					"text" : "evt1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-41",
					"linecount" : 56,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 25.0, 161.5, 149.0, 759.0 ],
					"style" : "",
					"text" : ";\rtoMT d00 300;\rtoMT d01 425;\rtoMT d02 800;\rtoMT d03 925;\rtoMT d04 1300;\rtoMT d05 1800;\rtoMT d06 2000;\rtoMT d07 2300;\rtoMT d08 200;\rtoMT d09 500;\rtoMT d10 600;\rtoMT d11 1000;\rtoMT d12 3000;\rtoMT d13 2500;\rtoMT d14 700;\rtoMT d15 300;\rtoMT tr13 50;\rtoMT out00 0.25;\rtoMT out01 0.3;\rtoMT out02 0.35;\rtoMT out03 0.;\rtoMT out04 0.25;\rtoMT out05 0.;\rtoMT out06 0.9;\rtoMT out07 0.;\rtoMT out08 0.;\rtoMT out09 0.;\rtoMT out10 0.;\rtoMT out11 0.;\rtoMT out12 0.4;\rtoMT out13 0.4;\rtoMT out14 0.3;\rtoMT out15 0.3;\rtoMT fd13 0.;\rtoMT fd10 0.2;\rtoMT r013 1;\rtoMT r029 1;\rtoMT r045 1;\rtoMT r077 1;\rtoMT r109 1;\rtoMT r205 1;\rtoMT r221 1;\rtoMT r237 1;\rtoMT r253 1;\rtoMT dStretch 0.8;\rtoMT hStretch 4;\rtoMT hWin 24;\rtoMT smoothDuration 10;\rrenv8_freq 13;\rrenv8_short 0.5;\rrenv8_level 127;\rdirectGuitare_level 70;\rmTDel_level 127;\rtoSpatConfig 1;\rrStretch 0.15;\r"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-1",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 25.0, 4.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 27 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-109", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 29 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 18 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-111", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 31 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-113", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 30 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-115", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 8 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-116", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 22 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-117", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
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
					"source" : [ "obj-2", 24 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 21 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 35 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 23 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 32 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 32 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 22 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 8 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 23 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 16 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 5 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 19 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 17 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 34 ]
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
					"destination" : [ "obj-31", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 2,
					"source" : [ "obj-2", 8 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 30 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 18 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 31 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 19 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 9 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 2,
					"source" : [ "obj-2", 5 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 36 ]
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
					"order" : 1,
					"source" : [ "obj-2", 36 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 20 ]
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
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 14 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-71", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 25 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-80", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 28 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 33 ]
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
					"source" : [ "obj-2", 26 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 15 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-2", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
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
					"order" : 1,
					"source" : [ "obj-2", 16 ]
				}

			}
 ],
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
