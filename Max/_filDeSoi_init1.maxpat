{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 2,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 112.0, 79.0, 759.0, 770.0 ],
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
					"comment" : "",
					"id" : "obj-1",
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 112.0, 9.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"linecount" : 51,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 16.0, 63.0, 552.0, 692.0 ],
					"style" : "",
					"text" : ";\rtoMTap init;\rtoMTap setDuration 0 300 425 800 925 1300 1800 2050 2300 200 500 600 1000 3000 2500 700 300;\rtoMTap setFd 0.99;\rtoMTap setFd 8 0.5 0.5 0.2 0.5;\rtoMTap setFd 13 0;\rtoMTap setTransposition 0 386 772 -386 180 386 -772 -45 180 0 0 0 0 -500 50 -1000 -1200;\rtoMTap setInp 0;\rtoMTap setInp 8 1 1 1 1 1 1 1 1;\rtoMTap setOut 0;\rtoMTap setOut 0 1 1 1 0 1 0 1 0 0 0 0 0 1 0.4 1 1;\rtoMTap setXvd 0 1 1 1 1 1 1 1 1 0 0 0 0;\rtoMTap tStretch 0.8;\rtoMTap hStretch 4;\rtoMTap wHarmo 24;\rtoMTap smoothDuration 50;\rtoMTap setFdMat 0 0 1;\rtoMTap setFdMat 1 1 1;\rtoMTap setFdMat 2 2 1;\rtoMTap setFdMat 3 3 1;\rtoMTap setFdMat 4 4 1;\rtoMTap setFdMat 5 5 1;\rtoMTap setFdMat 6 6 1;\rtoMTap setFdMat 7 7 1;\rtoMTap setFdMat 8 0 1;\rtoMTap setFdMat 9 1 1;\rtoMTap setFdMat 10 2 1;\rtoMTap setFdMat 11 3 1;\rtoMTap setFdMat 8 4 1;\rtoMTap setFdMat 9 5 1;\rtoMTap setFdMat 10 6 1;\rtoMTap setFdMat 11 7 1;\rtoMTap setFdMat 8 8 1;\rtoMTap setFdMat 9 9 1;\rtoMTap setFdMat 10 10 1;\rtoMTap setFdMat 11 11 1;\rtoMTap setFdMat 13 0 1;\rtoMTap setFdMat 13 1 1;\rtoMTap setFdMat 13 2 1;\rtoMTap setFdMat 13 4 1;\rtoMTap setFdMat 13 6 1;\rtoMTap setFdMat 13 12 1;\rtoMTap setFdMat 13 13 1;\rtoMTap setFdMat 13 14 1;\rtoMTap setFdMat 13 15 1;\rtoMTap displayAll;\rrenv8_level 127;\rrenv8_freq 17;\rrenv8_short 0.5;\rdirectGuitare_level 40;\rmTDel_level 127;\r"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 16.0, 9.0, 60.0, 22.0 ],
					"style" : "",
					"text" : "loadbang"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 121.5, 50.5, 25.5, 50.5 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-78", 0 ]
				}

			}
 ]
	}

}
