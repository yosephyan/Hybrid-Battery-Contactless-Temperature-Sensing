//-------------------------------------------------------------
//Function "one_row" calculates the average value
//of the pixels that fall on the same battery cell for one column
//-------------------------------------------------------------


// clm = column
// index = index of mlxarray
//clm_width = # columns wide battery cell is
int one_row (int clm, int index,float *mlxarray, float *frame, float clm_width) {
    //row_num_ - indicates which row based on "* number"
    //Example = row_num_ * 5 <- indicates row 5
    int row_num_ = 32;

    int c;

    //temp array to hold values of battery cells 0-6
    float cell[] = {0, 0, 0, 0, 0, 0};

    //cycles below algorithm based on width of column pixels
    for (c = clm; c < (clm_width+clm); c++) {

        //Battery cell 0 - rows 0,1
        cell[0] = cell[0] + (frame[clm + row_num_ * 0] + frame[clm + row_num_ * 1]) / (float)2;
        //Battery cell 1 - rows 2,4,5
        cell[1] =cell[1] + (frame[clm + row_num_ * 2] + frame[clm + row_num_ * 4]
                            + frame[clm + row_num_ * 5]) / (float)3;
        //Battery cell 2 - rows 7,8,9,10,11
        cell[2] = cell[2] + (frame[clm + row_num_ * 7] + frame[clm + row_num_ * 8] + frame[clm + row_num_ * 9] +
                             frame[clm + row_num_ * 10] + frame[clm + row_num_ * 11]) / (float)5;
        //Battery cell 3 - rows 13,14,15,16
        cell[3] = cell[3] + (frame[clm + row_num_ * 13] + frame[clm + row_num_ * 14] + frame[clm + row_num_ * 15] +
                             frame[clm + row_num_ * 16]) / (float)4;
        //Battery cell 4 - rows 18,20,21
        cell[4] = cell[4] + (frame[clm + row_num_ * 18] + frame[clm + row_num_ * 20]
                             + frame[clm + row_num_ * 21]) / (float)3;
        //Battery cell 5 - row 22 & 23
        cell[5] = cell[5] + (frame[clm + row_num_ * 22] + frame[clm + row_num_ * 23]) / (float)2;
    }

    //places final cell temp. into output array
    for (int r = 0; r<6; r++){
        mlxarray[index+r] = cell[r] /clm_width;
    }


    if (clm_width>1){
        return c-1;
    }
    else {
        return clm;
    }
}

//-------------------------------------------------------------
//Function "calibrate_sensor_type1" calibrates the pixels to 
//13(batteries)x6(cells for each battery) format. 
//Each data point represents 1 cell for 1 battery. 
//-------------------------------------------------------------

int calibrate_sensor_type1(float *mlxarray, float *frame, int index){
int column = 0;         //Col = 32
float clm_width = 1;    //clm_width = # columns wide battery cell is
int row = 0;

  
    for (column = 4; column < 29; column++) { //row 4 to 29

        //rows 4 and 5 are 1 column wide
        //initial clm_width is 1

        if (column == 6){   //rows 6, 8, 10 and 12 are 2 column wide
            clm_width = 2;
        }
        if (column == 14){  //rows 14 and 17 are 3 column wide
            clm_width = 3;
        }
        if (column == 20){  //row 20 is 2 column wide
            clm_width = 2;
        }
        if (column == 22){  //rows 22 is 1 column wide
            clm_width = 1;
        }
        if (column == 23){  //rows 23, 25 and 27 are 2 column wide
            clm_width = 2;
        }

        column = one_row( column,  index, mlxarray,  frame,  clm_width);  //returns 1 is successful
        //checks if there are 13 total rows
        row++;
        index = index + 6;
        }

          //Serial.println(row);
return index;
}



//-------------------------------------------------------------
//Function "calibrate_sensor_type2" calibrates the pixels to 
//14(batteries)x6(cells for each battery) format. 
//Each data point represents 1 cell for 1 battery. 
//-------------------------------------------------------------

int calibrate_sensor_type2(float *mlxarray, float *frame, int index){
int column = 0;         //Col = 32
float clm_width = 1;    //clm_width = # columns wide battery cell is
int row = 0;

  
    for (column = 3; column < 29; column++) { //row 3 to 29

        //rows 3, 4 and 5 are 1 column wide
        //initial clm_width is 1

        if (column == 6){   //rows 6, 8, 10 and 12 are 2 column wide
            clm_width = 2;
        }
        if (column == 14){  //rows 14 and 17 are 3 column wide
            clm_width = 3;
        }
        if (column == 20){  //row 20 is 2 column wide
            clm_width = 2;
        }
        if (column == 22){  //rows 22 is 1 column wide
            clm_width = 1;
        }
        if (column == 23){  //rows 23, 25 and 27 are 2 column wide
            clm_width = 2;
        }

        column = one_row( column,  index, mlxarray,  frame,  clm_width);  //returns 1 is successful
        //checks if there are 14 total rows
        row++;
        index = index + 6;
        }

          //Serial.println(row);
return index;
}

        
