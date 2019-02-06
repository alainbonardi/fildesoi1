{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 5,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 1424.0, 328.0, 759.0, 429.0 ],
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
					"fontsize" : 10.0,
					"id" : "obj-14",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 162.0, 37.0, 26.0, 18.0 ],
					"style" : "",
					"text" : "qlist",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 10.0,
					"id" : "obj-18",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 180.5, 80.0, 32.0, 20.0 ],
					"style" : "",
					"text" : "write"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 10.0,
					"id" : "obj-19",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 140.5, 80.0, 31.0, 20.0 ],
					"style" : "",
					"text" : "read"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 10.0,
					"id" : "obj-17",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 180.5, 55.0, 41.0, 20.0 ],
					"style" : "",
					"text" : "wclose"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 10.0,
					"id" : "obj-16",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 140.5, 55.0, 33.0, 20.0 ],
					"style" : "",
					"text" : "open"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 10.0,
					"id" : "obj-15",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 137.5, 102.0, 83.0, 18.0 ],
					"style" : "",
					"text" : "abc.qlistwithgoto",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-13",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 404.0, -39.0, 58.0, 33.0 ],
					"style" : "",
					"text" : "bang to go"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"hidden" : 1,
					"id" : "obj-12",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 372.0, -39.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-11",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 244.0, -39.0, 58.0, 33.0 ],
					"style" : "",
					"text" : "evt number"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"hidden" : 1,
					"id" : "obj-10",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 211.0, -39.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-9",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "abc.gotoevent.maxpat",
					"numinlets" : 2,
					"numoutlets" : 2,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 6.0, 2.0, 130.0, 38.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 574.0, -34.0, 95.0, 20.0 ],
					"style" : "",
					"text" : "message to qlist"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"hidden" : 1,
					"id" : "obj-8",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 543.0, -39.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-4",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 155.0, -42.0, 46.0, 33.0 ],
					"style" : "",
					"text" : "next event"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"hidden" : 1,
					"id" : "obj-5",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 123.0, -39.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-3",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 45.0, -34.0, 46.0, 20.0 ],
					"style" : "",
					"text" : "reset"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"hidden" : 1,
					"id" : "obj-6",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.0, -39.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-2",
					"index" : 0,
					"maxclass" : "outlet",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 0.0, 314.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.394356, 0.149215, 0.067687, 1.0 ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-1",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "abc.evtcounter.maxpat",
					"numinlets" : 2,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "" ],
					"patching_rect" : [ 0.0, 36.0, 136.0, 90.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.917647, 0.937255, 0.670588, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 24.0,
					"id" : "obj-25",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "bang", "bang" ],
					"patching_rect" : [ 106.0, 234.0, 81.0, 35.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 883.0, 213.0, 81.0, 35.0 ],
					"save" : [ "#N", "qlist", ";", "#X", "insert", "------------------------", 0, ";", ";", "#X", "insert", 0, 0, "generalPreset", 1, ";", ";", "#X", "insert", "------------------------", 1, ";", ";", "#X", "insert", 0, 1, "generalPreset", 1, ";", ";", "#X", "insert", 5000, "toDistance", 3, 10000, ";", ";", "#X", "insert", "------------------------", 2, ";", ";", "#X", "insert", 0, 2, "toDistance", 3, ";", ";", "#X", "insert", "------------------------", 3, ";", ";", "#X", "insert", 0, 3, "toDistance", 5, ";", ";", "#X", "insert", 3000, "niveauGen", -70, 500, ";", ";", "#X", "insert", 17000, "niveauGen", 0, 500, ";", ";", "#X", "insert", 15000, "toDistance", 1.5, 16000, ";", ";", "#X", "insert", "------------------------", 4, ";", ";", "#X", "insert", 0, 4, "anything", 0, ";", ";", "#X", "insert", "------------------------", 5, ";", ";", "#X", "insert", 0, 5, "toDistance", 2.5, ";", ";", "#X", "insert", 1000, "toDistance", 1, 75000, ";", ";", "#X", "insert", "harmoWin", 11, 75000, ";", ";", "#X", "insert", "randomRotationSpeed", 1, ";", ";", "#X", "insert", "randomNiveauGen", 1, ";", ";", "#X", "insert", "------------------------", 6, ";", ";", "#X", "insert", 0, 6, "toDistance", 1.0, ";", ";", "#X", "insert", "harmoWin", 11, ";", ";", "#X", "insert", "randomRotationSpeed", 0, ";", ";", "#X", "insert", "randomNiveauGen", 0, ";", ";", "#X", "insert", "------------------------", 7, ";", ";", "#X", "insert", 0, 7, "toMTap", "setFd", 0.0, ";", ";", "#X", "insert", "toMTap", "setDuration", 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", 5000, "generalPreset", 2, ";", ";", "#X", "insert", "------------------------", 8, ";", ";", "#X", "insert", 0, 8, "toMTap", "setOut", 1.0, ";", ";", "#X", "insert", "toMTap", "setOut", 2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 166, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.01, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 9, ";", ";", "#X", "insert", 0, 9, "anything", 9, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 250, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.02, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 10, ";", ";", "#X", "insert", 0, 10, "anything", 10, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 333, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.03, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 11, ";", ";", "#X", "insert", 0, 11, "anything", 11, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 400, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.04, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 12, ";", ";", "#X", "insert", 0, 12, "anything", 12, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 500, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.05, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 13, ";", ";", "#X", "insert", 0, 13, "anything", 13, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 600, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.06, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 14, ";", ";", "#X", "insert", 0, 14, "anything", 14, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 667, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.07, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 15, ";", ";", "#X", "insert", 0, 15, "anything", 15, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 750, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.08, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 16, ";", ";", "#X", "insert", 0, 16, "anything", 16, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 833, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.09, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 17, ";", ";", "#X", "insert", 0, 17, "anything", 17, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 875, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.1, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 18, ";", ";", "#X", "insert", 0, 18, "anything", 18, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 1000, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.11, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 19, ";", ";", "#X", "insert", 0, 19, "anything", 19, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 1125, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.12, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 20, ";", ";", "#X", "insert", 0, 20, "anything", 20, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 1167, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.13, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 21, ";", ";", "#X", "insert", 0, 21, "anything", 21, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 1250, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.14, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 22, ";", ";", "#X", "insert", 0, 22, "anything", 22, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 1333, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.15, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 23, ";", ";", "#X", "insert", 0, 23, "anything", 23, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 1400, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.16, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 24, ";", ";", "#X", "insert", 0, 24, "anything", 24, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 1500, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.17, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 25, ";", ";", "#X", "insert", 0, 25, "anything", 25, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 1600, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.18, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 26, ";", ";", "#X", "insert", 0, 26, "anything", 26, ";", ";", "#X", "insert", 1800, "toMTap", "setDuration", 1667, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.19, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 27, ";", ";", "#X", "insert", 0, 27, "anything", 27, ";", ";", "#X", "insert", 1900, "toMTap", "setDuration", 1750, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.2, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 28, ";", ";", "#X", "insert", 0, 28, "anything", 28, ";", ";", "#X", "insert", 1900, "toMTap", "setDuration", 1833, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.21, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 29, ";", ";", "#X", "insert", 0, 29, "anything", 29, ";", ";", "#X", "insert", 1900, "toMTap", "setDuration", 1875, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.22, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 30, ";", ";", "#X", "insert", 0, 30, "anything", 30, ";", ";", "#X", "insert", 1900, "toMTap", "setDuration", 2000, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.23, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 31, ";", ";", "#X", "insert", 0, 31, "anything", 31, ";", ";", "#X", "insert", 2017, "toMTap", "setDuration", 875, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.23, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 32, ";", ";", "#X", "insert", 0, 32, "anything", 32, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 857, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.22, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 33, ";", ";", "#X", "insert", 0, 33, "anything", 33, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 833, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.21, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 34, ";", ";", "#X", "insert", 0, 34, "anything", 34, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 800, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.2, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 35, ";", ";", "#X", "insert", 0, 35, "anything", 35, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 750, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.19, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 36, ";", ";", "#X", "insert", 0, 36, "anything", 36, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 714, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.18, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 37, ";", ";", "#X", "insert", 0, 37, "anything", 37, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 667, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.17, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 38, ";", ";", "#X", "insert", 0, 38, "anything", 38, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 625, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.16, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 39, ";", ";", "#X", "insert", 0, 39, "anything", 39, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 600, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.15, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 40, ";", ";", "#X", "insert", 0, 40, "anything", 40, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 571, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.14, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 41, ";", ";", "#X", "insert", 0, 41, "anything", 41, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 500, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.13, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 42, ";", ";", "#X", "insert", 0, 42, "anything", 42, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 429, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.12, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 43, ";", ";", "#X", "insert", 0, 43, "anything", 43, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 400, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.11, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 44, ";", ";", "#X", "insert", 0, 44, "anything", 44, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 375, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.1, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 45, ";", ";", "#X", "insert", 0, 45, "anything", 45, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 333, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.09, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 46, ";", ";", "#X", "insert", 0, 46, "anything", 46, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 285, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.08, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 47, ";", ";", "#X", "insert", 0, 47, "anything", 47, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 250, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.07, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 48, ";", ";", "#X", "insert", 0, 48, "anything", 48, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 200, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.06, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 49, ";", ";", "#X", "insert", 0, 49, "anything", 49, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 167, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.05, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 50, ";", ";", "#X", "insert", 0, 50, "anything", 50, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 143, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.04, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 51, ";", ";", "#X", "insert", 0, 51, "anything", 51, ";", ";", "#X", "insert", 900, "toMTap", "setDuration", 125, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.03, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 52, ";", ";", "#X", "insert", 0, 52, "anything", 52, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.02, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "------------------------", 53, ";", ";", "#X", "insert", 0, 53, "anything", 53, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", -0.01, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "------------------------", 54, ";", ";", "#X", "insert", 0, 54, "anything", 54, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.0, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "------------------------", 55, ";", ";", "#X", "insert", 0, 55, "generalPreset", 3, ";", ";", "#X", "insert", "------------------------", 56, ";", ";", "#X", "insert", 0, 56, "toMTap", "tStretch", 1.2, ";", ";", "#X", "insert", "toMTap", "setFd", 0, 0.8, 0.7, 0.6, 0.55, 0.52, 0.5, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 57, ";", ";", "#X", "insert", 0, 57, "tStretch", 2.0, ";", ";", "#X", "insert", "toMTap", "setFd", 0, 0.7, 0.6, 0.55, 0.53, 0.52, 0.5, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 58, ";", ";", "#X", "insert", 0, 58, "toMTap", "tStretch", 4.0, ";", ";", "#X", "insert", "toMTap", "setFd", 0, 0.6, 0.55, 0.54, 0.53, 0.52, 0.5, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 59, ";", ";", "#X", "insert", 0, 59, "toMTap", "tStretch", 5.0, ";", ";", "#X", "insert", "toMTap", "setFd", 0, 0.55, 0.54, 0.53, 0.52, 0.51, 0.5, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 60, ";", ";", "#X", "insert", 0, 60, "anything", 60, ";", ";", "#X", "insert", "toInputLevels", "randomenv", "freq", 0.4, ";", ";", "#X", "insert", "toInputLevels", "randomness", "shorten", 0.8, ";", ";", "#X", "insert", "toInputLevels", "randomenv", "level", 100, ";", ";", "#X", "insert", "------------------------", 61, ";", ";", "#X", "insert", 0, 61, "anything", 61, ";", ";", "#X", "insert", "toInputLevels", "randomenv", "freq", 0.8, ";", ";", "#X", "insert", "toInputLevels", "randomness", "shorten", 0.75, ";", ";", "#X", "insert", "------------------------", 62, ";", ";", "#X", "insert", 0, 62, "anything", 62, ";", ";", "#X", "insert", "toInputLevels", "randomenv", "freq", 1.5, ";", ";", "#X", "insert", "toInputLevels", "randomness", "shorten", 0.7, ";", ";", "#X", "insert", "------------------------", 63, ";", ";", "#X", "insert", 0, 63, "anything", 63, ";", ";", "#X", "insert", "toInputLevels", "randomenv", "freq", 3.0, ";", ";", "#X", "insert", "toInputLevels", "randomness", "shorten", 0.65, ";", ";", "#X", "insert", "------------------------", 64, ";", ";", "#X", "insert", 0, 64, "anything", 64, ";", ";", "#X", "insert", "toInputLevels", "randomenv", "freq", 5.0, ";", ";", "#X", "insert", "toInputLevels", "randomness", "shorten", 0.6, ";", ";", "#X", "insert", "------------------------", 65, ";", ";", "#X", "insert", 0, 65, "anything", 65, ";", ";", "#X", "insert", "toInputLevels", "randomenv", "freq", 7.0, ";", ";", "#X", "insert", "toInputLevels", "randomness", "shorten", 0.5, ";", ";", "#X", "insert", "------------------------", 66, ";", ";", "#X", "insert", 0, 66, "globalPreset", 4, ";", ";", "#X", "insert", "------------------------", 67, ";", ";", "#X", "insert", 0, 67, "toMTap", "wHarmo", 28, ";", ";", "#X", "insert", "------------------------", 68, ";", ";", "#X", "insert", 0, 68, "toMTap", "wHarmo", 26, ";", ";", "#X", "insert", "------------------------", 69, ";", ";", "#X", "insert", 0, 69, "toMTap", "wHarmo", 24, ";", ";", "#X", "insert", "------------------------", 70, ";", ";", "#X", "insert", 0, 70, "toMTap", "wHarmo", 22, ";", ";", "#X", "insert", "------------------------", 71, ";", ";", "#X", "insert", 0, 71, "toMTap", "wHarmo", 20, ";", ";", "#X", "insert", "------------------------", 72, ";", ";", "#X", "insert", 0, 72, "toMTap", "wHarmo", 18, ";", ";", "#X", "insert", "------------------------", 73, ";", ";", "#X", "insert", 0, 73, "toMTap", "wHarmo", 16, ";", ";", "#X", "insert", "------------------------", 74, ";", ";", "#X", "insert", 0, 74, "toMTap", "wHarmo", 14, ";", ";", "#X", "insert", "------------------------", 75, ";", ";", "#X", "insert", 0, 75, "toMTap", "wHarmo", 12, ";", ";", "#X", "insert", "------------------------", 76, ";", ";", "#X", "insert", 0, 76, "toMTap", "wHarmo", 10, ";", ";", "#X", "insert", "------------------------", 77, ";", ";", "#X", "insert", 0, 77, "toMTap", "wHarmo", 8, ";", ";", "#X", "insert", "------------------------", 78, ";", ";", "#X", "insert", 0, 78, "anything", 78, ";", ";", "#X", "insert", "------------------------", 79, ";", ";", "#X", "insert", 0, 79, "anything", 79, ";", ";", "#X", "insert", "------------------------", 80, ";", ";", "#X", "insert", 0, 80, "anything", 80, ";", ";", "#X", "insert", "------------------------", 81, ";", ";", "#X", "insert", 0, 81, "anything", 81, ";", ";", "#X", "insert", "------------------------", 82, ";", ";", "#X", "insert", 0, 82, "anything", 82, ";", ";", "#X", "insert", "------------------------", 83, ";", ";", "#X", "insert", 0, 83, "anything", 83, ";", ";", "#X", "insert", "------------------------", 84, ";", ";", "#X", "insert", 0, 84, "anything", 84, ";", ";", "#X", "insert", "------------------------", 85, ";", ";", "#X", "insert", 0, 85, "anything", 85, ";", ";", "#X", "insert", "------------------------", 86, ";", ";", "#X", "insert", 0, 86, "anything", 86, ";", ";", "#X", "insert", "------------------------", 87, ";", ";", "#X", "insert", 0, 87, "anything", 87, ";", ";", "#X", "insert", "------------------------", 88, ";", ";", "#X", "insert", 0, 88, "anything", 88, ";", ";", "#X", "insert", "------------------------", 89, ";", ";", "#X", "insert", 0, 89, "anything", 89, ";", ";", "#X", "insert", "------------------------", 90, ";", ";", "#X", "insert", 0, 90, "anything", 90, ";", ";", "#X", "insert", "------------------------", 91, ";", ";", "#X", "insert", 0, 91, "anything", 91, ";", ";", "#X", "insert", "------------------------", 92, ";", ";", "#X", "insert", 0, 92, "anything", 92, ";", ";", "#X", "insert", "------------------------", 93, ";", ";", "#X", "insert", 0, 93, "anything", 93, ";", ";", "#X", "insert", "------------------------", 94, ";", ";", "#X", "insert", 0, 94, "anything", 94, ";", ";", "#X", "insert", "------------------------", 95, ";", ";", "#X", "insert", 0, 95, "anything", 95, ";", ";", "#X", "insert", "------------------------", 96, ";", ";", "#X", "insert", 0, 96, "anything", 96, ";", ";", "#X", "insert", "------------------------", 97, ";", ";", "#X", "insert", 0, 97, "anything", 97, ";", ";", "#X", "insert", "------------------------", 98, ";", ";", "#X", "insert", 0, 98, "anything", 98, ";", ";", "#X", "insert", "------------------------", 99, ";", ";", "#X", "insert", 0, 99, "anything", 99, ";", ";", "#X", "insert", "------------------------", 100, ";", ";", "#X", "insert", 0, 100, "anything", 100, ";", ";", "#X", "insert", "------------------------", 101, ";", ";", "#X", "insert", 0, 101, "anything", 101, ";", ";", "#X", "insert", "------------------------", 102, ";", ";", "#X", "insert", 0, 102, "anything", 102, ";", ";", "#X", "insert", "------------------------", 103, ";", ";", "#X", "insert", 0, 103, "anything", 103, ";", ";", "#X", "insert", "------------------------", 104, ";", ";", "#X", "insert", 0, 104, "anything", 104, ";", ";", "#X", "insert", "------------------------", 105, ";", ";", "#X", "insert", 0, 105, "generalPreset", 5, ";", ";", "#X", "insert", 15000, "toSpatConfig", 7, ";", ";", "#X", "insert", 15000, "toSpatConfig", 8, ";", ";", "#X", "insert", 15000, "toSpatConfig", 1, ";", ";", "#X", "insert", "------------------------", 106, ";", ";", "#X", "insert", 0, 106, "toInputDispatch", "dispatch", 2, ";", ";", "#X", "insert", "toSpatConfig", 5, ";", ";", "#X", "insert", "------------------------", 107, ";", ";", "#X", "insert", 0, 107, "anything", 107, ";", ";", "#X", "insert", "harmoWin", 64, 30000, ";", ";", "#X", "insert", "------------------------", 108, ";", ";", "#X", "insert", 0, 108, "anything", 108, ";", ";", "#X", "insert", "harmoWin", 64, ";", ";", "#X", "insert", "toMTap", "tStretch", 0.05, ";", ";", "#X", "insert", "toMTap", "hStretch", 3.0, ";", ";", "#X", "insert", "toMTap", "setOut", 4, 0, ";", ";", "#X", "insert", "toMTap", "setOut", 11, 0, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", 10000, "toMTap", "tStretch", 0.07, ";", ";", "#X", "insert", 20000, "toMTap", "tStretch", 0.09, ";", ";", "#X", "insert", 30000, "toMTap", "tStretch", 0.12, ";", ";", "#X", "insert", "------------------------", 109, ";", ";", "#X", "insert", 0, 109, "anything", 109, ";", ";", "#X", "insert", "toMTap", "setOut", 1, ";", ";", "#X", "insert", "toMTap", "tStretch", 0.3, ";", ";", "#X", "insert", "toMTap", "displayAll", ";", ";", "#X", "insert", "------------------------", 110, ";", ";", "#X", "insert", 0, 110, "anything", 110, ";", ";", "#X", "insert", "toSpat", 16, 0, 0, ";", ";", "#X", "insert", "toSpat", 16, 7, 1, ";", ";", "#X", "insert", "toSpat", "rotSpeeds", 0.2, 0.0, 0.0, 0.0, ";", ";", "#X", "insert", "toInputLevels", "processed", 0, 38000, ";", ";" ],
					"style" : "",
					"text" : "qlist",
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 11.595187,
					"id" : "obj-29",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 5,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 685.0, 232.0, 555.0, 510.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 11.595187,
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
						"boxes" : [ 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-29",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 49.0, 460.0, 122.0, 21.0 ],
									"style" : "",
									"text" : "print abc.qlistwithgoto"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "int", "bang" ],
									"patching_rect" : [ 147.0, 244.0, 40.0, 21.0 ],
									"style" : "",
									"text" : "t b i b"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "int", "int" ],
									"patching_rect" : [ 147.0, 220.0, 81.0, 21.0 ],
									"style" : "",
									"text" : "split 0 100000"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 147.0, 197.0, 27.0, 21.0 ],
									"style" : "",
									"text" : "-"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "int", "int" ],
									"patching_rect" : [ 155.0, 286.0, 81.0, 21.0 ],
									"style" : "",
									"text" : "split 1 100000"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-5",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 83.0, 190.0, 30.0, 21.0 ],
									"style" : "",
									"text" : "stop"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "" ],
									"patching_rect" : [ 311.0, 58.0, 33.0, 21.0 ],
									"style" : "",
									"text" : "sel 0"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "bang" ],
									"patching_rect" : [ 311.0, 86.0, 31.0, 21.0 ],
									"style" : "",
									"text" : "t b b"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-8",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 311.0, 156.0, 71.0, 21.0 ],
									"style" : "",
									"text" : "rewind, next"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 331.0, 30.0, 67.0, 19.0 ],
									"style" : "",
									"text" : "events inlet"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-10",
									"index" : 3,
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 311.0, 29.0, 15.0, 15.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-11",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 162.0, 318.0, 18.0, 21.0 ],
									"style" : "",
									"text" : "0"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-12",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 241.0, 318.0, 47.0, 21.0 ],
									"style" : "",
									"text" : "next $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 241.0, 285.0, 27.0, 21.0 ],
									"style" : "",
									"text" : "i 0"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-14",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 82.0, 406.0, 162.0, 19.0 ],
									"style" : "",
									"text" : "gets time delays from the qlist"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-15",
									"index" : 1,
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 127.0, 29.0, 15.0, 15.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "int", "int" ],
									"patching_rect" : [ 127.0, 94.0, 47.0, 21.0 ],
									"style" : "",
									"text" : "unpack"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-17",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 263.0, 348.0, 195.0, 32.0 ],
									"style" : "",
									"text" : "outlet for 'rewind' and 'next' messages which are sent to the qlist"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-18",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 294.0, 254.0, 253.0, 58.0 ],
									"style" : "",
									"text" : "If negative, do nothing. If zero, send a 'next' to the qlist and 'bang' the delay object. If positive, send a 'next' to the qlist, a delay time of zero to the delay object, and 'bang' the delay object."
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-19",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 181.0, 28.0, 81.0, 45.0 ],
									"style" : "",
									"text" : "executable or nonexecutable 'next' inlet"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-20",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 188.0, 432.0, 248.0, 19.0 ],
									"style" : "",
									"text" : "dummy variable which should not be removed!"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-21",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 49.0, 431.0, 135.0, 21.0 ],
									"style" : "",
									"text" : "r ------------------------"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-22",
									"linecount" : 8,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 34.0, 50.0, 93.0, 110.0 ],
									"style" : "",
									"text" : "separate the time delays and event numbers being output from the qlist and send time delays to the delay object"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-23",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 319.0, 199.0, 157.0, 45.0 ],
									"style" : "",
									"text" : "send the present event number for comparison with any incoming event numbers"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-24",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 348.0, 115.0, 161.0, 45.0 ],
									"style" : "",
									"text" : "if the event number is 0, initalize by sending a 'rewind' and 'next' message to qlist"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-25",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 329.0, 118.0, 18.0, 21.0 ],
									"style" : "",
									"text" : "0"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 11.595187,
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 83.0, 384.0, 54.0, 21.0 ],
									"style" : "",
									"text" : "del"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-27",
									"index" : 2,
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 258.0, 28.0, 15.0, 15.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-28",
									"index" : 1,
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 241.0, 355.0, 15.0, 15.0 ],
									"style" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"source" : [ "obj-1", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-1", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 1 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 1 ],
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 1 ],
									"source" : [ "obj-16", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-29", 0 ],
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 1 ],
									"source" : [ "obj-25", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-26", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 1 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-6", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"order" : 1,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"order" : 0,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-7", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 106.0, 203.0, 112.0, 21.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 11.595187,
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "patcher qlist_control"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"hidden" : 1,
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 2 ],
					"hidden" : 1,
					"midpoints" : [ 9.5, 177.0, 208.5, 177.0 ],
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"hidden" : 1,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 1 ],
					"hidden" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"hidden" : 1,
					"midpoints" : [ 150.0, 141.0, 115.5, 141.0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"hidden" : 1,
					"midpoints" : [ 190.0, 159.0, 115.5, 159.0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"hidden" : 1,
					"midpoints" : [ 190.0, 152.5, 115.5, 152.5 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"hidden" : 1,
					"midpoints" : [ 150.0, 168.0, 115.5, 168.0 ],
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"midpoints" : [ 115.5, 277.0, 80.5, 277.0, 80.5, 193.0, 115.5, 193.0 ],
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 1 ],
					"hidden" : 1,
					"midpoints" : [ 132.5, 13.0, 126.5, 13.0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"hidden" : 1,
					"midpoints" : [ 15.5, 13.0, 9.5, 13.0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"hidden" : 1,
					"midpoints" : [ 552.5, 228.0, 115.5, 228.0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 1 ],
					"hidden" : 1,
					"midpoints" : [ 126.5, 40.5, 126.5, 40.5 ],
					"source" : [ "obj-9", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"hidden" : 1,
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "abc.evtcounter.maxpat",
				"bootpath" : "~/Documents/5_CREATIONS/FIL_DE_SOI/FIL_DE_SOI1/FilDeSoi1_versions_patchs/_FilDeSoi1_v1.7_octobre2017_aTester",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "abc.gotoevent.maxpat",
				"bootpath" : "~/Documents/5_CREATIONS/FIL_DE_SOI/FIL_DE_SOI1/FilDeSoi1_versions_patchs/_FilDeSoi1_v1.7_octobre2017_aTester",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
 ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "newobjBlue-1",
				"default" : 				{
					"accentcolor" : [ 0.317647, 0.654902, 0.976471, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "newobjGreen-1",
				"default" : 				{
					"accentcolor" : [ 0.0, 0.533333, 0.168627, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "newobjYellow-1",
				"default" : 				{
					"accentcolor" : [ 0.82517, 0.78181, 0.059545, 1.0 ],
					"fontsize" : [ 12.059008 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
 ]
	}

}
