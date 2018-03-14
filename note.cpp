#include "note.h"

bool addNote(){
    for (int i=0; i<16;i++){
        if (gGl.notes[i] == gGl.note){
            return false;
        }
        if (gGl.notes[i] == 0){
            gGl.notes[i] = gGl.note;
            gGl.note = 0;
            return true;
        }
    }
    return false;
}

void displayNote(){
    note_dialog n;
    n.exec();
}

void displayNote(int i){
    gGl.note = i;
    note_dialog n;
    n.exec();

}
