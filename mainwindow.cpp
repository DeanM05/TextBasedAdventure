#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap map("C:\\Users\\Dean\\Documents\\aaah\\map.jpg");
    ui->map->setPixmap(map);
    createRooms();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createRooms()  {
    QPixmap aI("C:\\Users\\Dean\\Documents\\aaah\\shopentrance.jpg");
    QPixmap bI("C:\\Users\\Dean\\Documents\\aaah\\shop.jpg");
    QPixmap cI("C:\\Users\\Dean\\Documents\\aaah\\poker.jpg");
    QPixmap dI("C:\\Users\\Dean\\Documents\\aaah\\shopentrance.jpg");
    QPixmap eI("C:\\Users\\Dean\\Documents\\aaah\\fountain.jpg");
    QPixmap fI("C:\\Users\\Dean\\Documents\\aaah\\carousel.jpg");
    QPixmap gI("C:\\Users\\Dean\\Documents\\aaah\\parkentrance.jpg");
    QPixmap hI("C:\\Users\\Dean\\Documents\\aaah\\officeentrance.jpg");
    QPixmap iI("C:\\Users\\Dean\\Documents\\aaah\\carpark.jpg");
    QPixmap jI("C:\\Users\\Dean\\Documents\\aaah\\office.jpg");
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *currentRoom;



    a = new Room("Souvenir Shop", 1);
        a->addItem(new Item("Chest of lead", 1, 11));
        a->addItem(new Item("Chest of silver", 2, 22));
        a->addItem(new Item("Chest of gold", 3, 33));
    b = new Room("???", 2);
        b->addItem(new Item("Money Bag", 3, 33));
        b->addItem(new Item("yy", 4, 44));
    c = new Room("Hideout Vault", 3);
    d = new Room("Shop Entrance", 4);
    e = new Room("Fountain", 5);
    f = new Room("Carousel", 6);
    g = new Room("Theme Park Entrance", 7);
    h = new Room("Shack Entrance", 8);
    i = new Room("Car Park", 9);
    j = new Room("Parking Shack", 10);
    h->addItem(new Item("Euro Coin", 4, 44));


//             (N, E, S, W)
    a->setExits(NULL, b, d, NULL);
    b->setExits(NULL, c, NULL, a);
    c->setExits(NULL, NULL, NULL, b);
    d->setExits(a, e, g, NULL);
    e->setExits(NULL, f, NULL, NULL);
    f->setExits(d, NULL, NULL, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, g, j, i);
    i->setExits(NULL, h, NULL, NULL);
    j->setExits(h, NULL, NULL, b);
  /*  Room* temp[] = {a, b, c, d, e, f, g, h, i, j};
    for(int i = 0; i<10; i++)
      rooms[i] = temp[i];
      */
    currentRoom = i;
}


void MainWindow::on_nB_clicked()
{
    Room* nextRoom = currentRoom->nextRoom("north");

    if (nextRoom == NULL)
        ui->desc->setText("Can't go north!");
    else
        {
            currentRoom = nextRoom;
            setDesc();
        }
}

void MainWindow::on_eB_clicked()
{
   /* Room* nextRoom = currentRoom->nextRoom("east");

    if (nextRoom == NULL)
        ui->desc->setText("Can't go east!");
    else {
       currentRoom = nextRoom;*/
        setDesc();
    //}
}

void MainWindow::on_wB_clicked()
{
    Room* nextRoom = currentRoom->nextRoom("west");

    if (nextRoom == NULL)
        ui->desc->setText("Can't go west!");
    else {
        currentRoom = nextRoom;
        setDesc();
    }
}


void MainWindow::on_sB_clicked()
{
    Room* nextRoom = currentRoom->nextRoom("south");

    if (nextRoom == NULL)
        ui->desc->setText("Can't go south!");
    else {
        currentRoom = nextRoom;
        setDesc();
    }
}

void MainWindow::on_execB_clicked()
{
 QString qstr = ui->textbox->toPlainText();
 string buffer = qstr.toStdString();
 Command* command = parser.getCommand(buffer);
 // Pass dereferenced command and check for end of game.
 processCommand(*command);
 // Free the memory allocated by "parser.getCommand()"
 //   with ("return new Command(...)")
 delete command;
}

void MainWindow::processCommand(Command command) {


    string commandWord = command.getCommandWord();

     if (command.isUnknown()) {
        ui->desc->setText("Invalid Input!");
    }



    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "What item were you trying to take? Try again."<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "The " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "cannot be found" << endl;
        else
            cout << "has been added to your inventory" << endl;

        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    }
void MainWindow::setDesc()
{
    switch(currentRoom->getID())

    {
    case 9:
        ui->desc->setText("You return to the desolate car park. Not much to see here.");
        ui->label->setPixmap(jI);
        break;
    case 8:
        ui->desc->setText("You walk towards the parking shack. The door is unlocked.");
        ui->label->setPixmap(hI);
        break;
    case 7:
        ui->desc->setText("The park entrance lies before you. Time to investigate within.");
        ui->label->setPixmap(gI);
        break;
    case 6:
        ui->desc->setText("You approach the carousel. There are 50 horses numbered 1 to 50.");
        ui->label->setPixmap(fI);
        break;
    case 5:
        ui->desc->setText("The fountain stands at your feet.");
        ui->label->setPixmap(eI);
        break;
    case 4:
        ui->desc->setText("A lit-up souvenir shop? Unusual.");
        ui->label->setPixmap(jI);
        break;
    case 3:
        ui->desc->setText("A gigantic vault is your final obstacle.");
        ui->label->setPixmap(jI);
        break;
    case 2:
        ui->desc->setText("You uncover the secret hideout. What can be unravelled here?");
        ui->label->setPixmap(jI);
        break;
    case 1:
        ui->desc->setText("The shop is empty, but what lies beneath?");
        ui->label->setPixmap(jI);
        break;
    case 10:
        ui->desc->setText("The shack is small but has some interesting items of note.");
        ui->label->setPixmap(jI);
        break;
    }

}

