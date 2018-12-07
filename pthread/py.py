#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os
import sys
import wx


class my_frame(wx.Frame):
    """We simple derive a new class of Frame"""
    def __init__(self,parent, title):
        wx.Frame.__init__(self, parent, title=title,size=(300,100))
        self.control = wx.TextCtrl(self, style=wx.TE_MULTILINE)

	self.control.AppendText("1111")

        self.Show(True)



logname="/debuglog_t.log"

def printf_arg(str):
	print str
def handlefile(str):
	#print "__file__=%s" % __file__
	rootpath=os.path.dirname(os.path.realpath(__file__));
	logpath=rootpath+logname
	print logpath

	fd = open(logpath,"rw+") 
	for line in fd.readlines():
		print line

	fd.close()

def creatui(arg):

	app = wx.App(False)
	frame = my_frame (None,'Small edior')
	app.MainLoop()

