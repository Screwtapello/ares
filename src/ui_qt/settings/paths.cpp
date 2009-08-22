void PathSettingsWindow::setup() {
  panel = new QWidget;

  layout = new QVBoxLayout;
  layout->setMargin(0);
  layout->setSpacing(0);

  title = new QLabel("Default Folder Paths");
  title->setProperty("class", "title");
  layout->addWidget(title);

  gameLabel = new QLabel("Games:");
  layout->addWidget(gameLabel);

  games = new QHBoxLayout; {
    games->setMargin(0);

    gamePath = new QLineEdit;
    gamePath->setReadOnly(true);
    games->addWidget(gamePath);

    gameSelect = new QPushButton("Select ...");
    games->addWidget(gameSelect);

    gameDefault = new QPushButton("Default");
    games->addWidget(gameDefault);
  }
  games->setSpacing(Style::WidgetSpacing);
  layout->addLayout(games);
  layout->addSpacing(Style::WidgetSpacing);

  saveLabel = new QLabel("Save RAM:");
  layout->addWidget(saveLabel);

  saves = new QHBoxLayout; {
    saves->setMargin(0);

    savePath = new QLineEdit;
    savePath->setReadOnly(true);
    saves->addWidget(savePath);

    saveSelect = new QPushButton("Select ...");
    saves->addWidget(saveSelect);

    saveDefault = new QPushButton("Default");
    saves->addWidget(saveDefault);
  }
  saves->setSpacing(Style::WidgetSpacing);
  layout->addLayout(saves);
  layout->addSpacing(Style::WidgetSpacing);

  stateLabel = new QLabel("Save states:");
  layout->addWidget(stateLabel);

  states = new QHBoxLayout; {
    states->setMargin(0);

    statePath = new QLineEdit;
    statePath->setReadOnly(true);
    states->addWidget(statePath);

    stateSelect = new QPushButton("Select ...");
    states->addWidget(stateSelect);

    stateDefault = new QPushButton("Default");
    states->addWidget(stateDefault);
  }
  states->setSpacing(Style::WidgetSpacing);
  layout->addLayout(states);
  layout->addSpacing(Style::WidgetSpacing);

  patchLabel = new QLabel("UPS patches:");
  layout->addWidget(patchLabel);

  patches = new QHBoxLayout; {
    patches->setMargin(0);

    patchPath = new QLineEdit;
    patchPath->setReadOnly(true);
    patches->addWidget(patchPath);

    patchSelect = new QPushButton("Select ...");
    patches->addWidget(patchSelect);

    patchDefault = new QPushButton("Default");
    patches->addWidget(patchDefault);
  }
  patches->setSpacing(Style::WidgetSpacing);
  layout->addLayout(patches);
  layout->addSpacing(Style::WidgetSpacing);

  cheatLabel = new QLabel("Cheat codes:");
  layout->addWidget(cheatLabel);

  cheats = new QHBoxLayout; {
    cheats->setMargin(0);

    cheatPath = new QLineEdit;
    cheatPath->setReadOnly(true);
    cheats->addWidget(cheatPath);

    cheatSelect = new QPushButton("Select ...");
    cheats->addWidget(cheatSelect);

    cheatDefault = new QPushButton("Default");
    cheats->addWidget(cheatDefault);
  }
  cheats->setSpacing(Style::WidgetSpacing);
  layout->addLayout(cheats);
  layout->addSpacing(Style::WidgetSpacing);

  dataLabel = new QLabel("Exported data:");
  layout->addWidget(dataLabel);

  datum = new QHBoxLayout; {
    datum->setMargin(0);
    datum->setSpacing(Style::WidgetSpacing);

    dataPath = new QLineEdit;
    dataPath->setReadOnly(true);
    datum->addWidget(dataPath);

    dataSelect = new QPushButton("Select ...");
    datum->addWidget(dataSelect);

    dataDefault = new QPushButton("Default");
    datum->addWidget(dataDefault);
  }
  layout->addLayout(datum);

  spacer = new QWidget;
  spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  layout->addWidget(spacer);

  syncUi();

  panel->setLayout(layout);
  connect(gameSelect, SIGNAL(released()), this, SLOT(selectGamePath()));
  connect(gameDefault, SIGNAL(released()), this, SLOT(defaultGamePath()));
  connect(saveSelect, SIGNAL(released()), this, SLOT(selectSavePath()));
  connect(saveDefault, SIGNAL(released()), this, SLOT(defaultSavePath()));
  connect(stateSelect, SIGNAL(released()), this, SLOT(selectStatePath()));
  connect(stateDefault, SIGNAL(released()), this, SLOT(defaultStatePath()));
  connect(patchSelect, SIGNAL(released()), this, SLOT(selectPatchPath()));
  connect(patchDefault, SIGNAL(released()), this, SLOT(defaultPatchPath()));
  connect(cheatSelect, SIGNAL(released()), this, SLOT(selectCheatPath()));
  connect(cheatDefault, SIGNAL(released()), this, SLOT(defaultCheatPath()));
  connect(dataSelect, SIGNAL(released()), this, SLOT(selectDataPath()));
  connect(dataDefault, SIGNAL(released()), this, SLOT(defaultDataPath()));
}

void PathSettingsWindow::syncUi() {
  syncPath(gamePath,  config.path.rom,   "Startup path");
  syncPath(savePath,  config.path.save,  "Same folder as loaded game");
  syncPath(statePath, config.path.state, "Same folder as loaded game");
  syncPath(patchPath, config.path.patch, "Same folder as loaded game");
  syncPath(cheatPath, config.path.cheat, "Same folder as loaded game");
  syncPath(dataPath,  config.path.data,  "Same folder as loaded game");
}

void PathSettingsWindow::syncPath(QLineEdit *control, const string &path, const char *caption) {
  if(path == "") {
    control->setStyleSheet("color: #808080");
    control->setText(caption);
  } else {
    control->setStyleSheet("color: #000000");
    control->setText((const char*)path);
  }
}

void PathSettingsWindow::selectGamePath() {
  string path = utility.selectFolder("Default Game Path");
  if(path.length() > 0) {
    config.path.rom = path;
    syncUi();
  }
}

void PathSettingsWindow::defaultGamePath() {
  config.path.rom = "";
  syncUi();
}

void PathSettingsWindow::selectSavePath() {
  string path = utility.selectFolder("Default Save RAM Path");
  if(path.length() > 0) {
    config.path.save = path;
    syncUi();
  }
}

void PathSettingsWindow::defaultSavePath() {
  config.path.save = "";
  syncUi();
}

void PathSettingsWindow::selectStatePath() {
  string path = utility.selectFolder("Default Save State Path");
  if(path.length() > 0) {
    config.path.state = path;
    syncUi();
  }
}

void PathSettingsWindow::defaultStatePath() {
  config.path.state = "";
  syncUi();
}

void PathSettingsWindow::selectPatchPath() {
  string path = utility.selectFolder("Default UPS Patch Path");
  if(path.length() > 0) {
    config.path.patch = path;
    syncUi();
  }
}

void PathSettingsWindow::defaultPatchPath() {
  config.path.patch = "";
  syncUi();
}

void PathSettingsWindow::selectCheatPath() {
  string path = utility.selectFolder("Default Cheat File Path");
  if(path.length() > 0) {
    config.path.cheat = path;
    syncUi();
  }
}

void PathSettingsWindow::defaultCheatPath() {
  config.path.cheat = "";
  syncUi();
}

void PathSettingsWindow::selectDataPath() {
  string path = utility.selectFolder("Default Exported Data Path");
  if(path.length() > 0) {
    config.path.data = path;
    syncUi();
  }
}

void PathSettingsWindow::defaultDataPath() {
  config.path.data = "";
  syncUi();
}
