/*  cdrdao - write audio CD-Rs in disc-at-once mode
 *
 *  Copyright (C) 2000  Andreas Mueller <mueller@daneb.ping.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __PROJECT_H__
#define __PROJECT_H__

#include <gtk--.h>
#include <gtk/gtk.h>
#include <gnome--.h>

#include "AudioCDChild.h"
#include "ProjectChooser.h"

class Project : public Gnome::App
{
private:
  ProjectChooser *projectChooser_;
  AudioCDChild *audioCDChild_;
  GList *childs;

  int project_number;

  enum ProjectType { P_NONE, P_CHOOSER, P_AUDIOCD };
  ProjectType projectType;

  Gtk::FileSelection *readFileSelector_;

public:
  Project(int);

  void newChooserWindow();
  void newAudioCDProject();
  void openProject();
  void readFileSelectorOKCB();
  void readFileSelectorCancelCB();
  void saveProject();
  void saveAsProject();
  void closeProject();
  void recordToc2CD();
  void configureDevices();
};
#endif
