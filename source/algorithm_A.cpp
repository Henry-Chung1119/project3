#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions 
 * 1. ~ 4. are listed in next block)
 * 
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 * 
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/


void algorithm_A(Board board, Player player, int index[]){

    // cout << board.get_capacity(0, 0) << endl;
    // cout << board.get_orbs_num(0, 0) << endl;
    // cout << board.get_cell_color(0, 0) << endl;
    // board.print_current_board(0, 0, 0);

    //////////// Random Algorithm ////////////
    // Here is the random algorithm for your reference, you can delete or comment it.
    long long cpu_cycle;
    asm volatile(".byte 15;.byte 49" : "=A" (cpu_cycle));
    srand((unsigned int)cpu_cycle);
    int row, col;
    char color = player.get_color();
    bool find = false;
    int maxorb[5][6]=
    {   
        1,2,2,2,2,1,
        2,3,3,3,3,2,
        2,3,3,3,3,2,
        2,3,3,3,3,2,
        1,2,2,2,2,1
    };
    
    if(board.get_cell_color(0,0)==color){
        if((board.get_cell_color(0,1)!=color && board.get_cell_color(0,1)!='w') && board.get_orbs_num(0,1)==2 ||
            (board.get_cell_color(1,0)!=color && board.get_cell_color(1,0)!='w' && board.get_orbs_num(1,0)==2))            
        {
            row=0;
            col=0;
            find=true;
        }
    }
    if(!find && board.get_cell_color(0,5)==color){
        if((board.get_cell_color(0,4)!=color && board.get_cell_color(0,4)!='w' && board.get_orbs_num(0,4)==2) ||
            (board.get_cell_color(1,5)!=color && board.get_cell_color(1,5)!='w' && board.get_orbs_num(1,5)==2))
        {
            row=0;
            col=5;
            find=true;
        }
    }
    if(!find && board.get_cell_color(4,0)==color){
        if((board.get_cell_color(4,1)!=color && board.get_cell_color(4,1)!='w' && board.get_orbs_num(4,1)==2) ||
            (board.get_cell_color(3,0)!=color && board.get_cell_color(3,0)!='w' && board.get_orbs_num(3,0)==2))
        {
            row=4;
            col=0;
            find=true;
        }
    }
    if(!find && board.get_cell_color(4,5)==color){
        if((board.get_cell_color(4,4)!=color && board.get_cell_color(4,4)!='w' && board.get_orbs_num(4,4)==2) ||
            (board.get_cell_color(3,5)!=color && board.get_cell_color(3,5)!='w' && board.get_orbs_num(3,5)==2))
        {
            row=4;
            col=5;
            find=true;
        }
    }
/*
    if(!find && board.get_cell_color(0,0)=='w'){
        if((board.get_cell_color(0,1)=='w' || board.get_cell_color(0,1)==color) &&
        (board.get_cell_color(1,0)=='w' || board.get_cell_color(1,0)==color))
        {
            row=0;
            col=0;
            find=true;
        }
        else if((board.get_cell_color(0,1)!='w' && board.get_cell_color(0,1)!=color && board.get_orbs_num(0,1)!=2) 
        || (board.get_cell_color(1,0)!='w' && board.get_cell_color(1,0)!=color && board.get_orbs_num(1,0)!=2))
        {
            row=0;
            col=0;
            find=true;
        }
    }
    if(!find && board.get_cell_color(0,5)=='w'){
        if((board.get_cell_color(0,4)=='w' || board.get_cell_color(0,4)==color) &&
        (board.get_cell_color(1,5)=='w' || board.get_cell_color(1,5)==color))
        {
            row=0;
            col=5;
            find=true;
        }
        else if((board.get_cell_color(0,4)!='w' && board.get_cell_color(0,4)!=color && board.get_orbs_num(0,4)!=2) 
        || (board.get_cell_color(1,5)!='w' && board.get_cell_color(1,5)!=color && board.get_orbs_num(1,5)!=2))
        {
            row=0;
            col=5;
            find=true;
        }
    }
    if(!find && board.get_cell_color(4,0)=='w'){
        if((board.get_cell_color(4,1)=='w' || board.get_cell_color(4,1)==color) &&
        (board.get_cell_color(3,0)=='w' || board.get_cell_color(3,0)==color))
        {
            row=4;
            col=0;
            find=true;
        }
        else if((board.get_cell_color(4,1)!='w' && board.get_cell_color(4,1)!=color && board.get_orbs_num(4,1)!=2) 
        || (board.get_cell_color(3,0)!='w' && board.get_cell_color(3,0)!=color && board.get_orbs_num(3,0)!=2))
        {
            row=4;
            col=0;
            find=true;
        }
    }
    if(!find && board.get_cell_color(4,5)=='w'){
        if((board.get_cell_color(4,4)=='w' || board.get_cell_color(4,4)==color) &&
        (board.get_cell_color(3,5)=='w' || board.get_cell_color(3,5)==color))
        {
            row=4;
            col=5;
            find=true;
        }
        else if((board.get_cell_color(4,4)!='w' && board.get_cell_color(4,4)!=color && board.get_orbs_num(4,4)!=2) 
        || (board.get_cell_color(3,5)!='w' && board.get_cell_color(3,5)!=color && board.get_orbs_num(3,5)!=2))
        {
            row=4;
            col=5;
            find=true;
        }
    }
*/
    int currentexplosion=0;
    if(!find){
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                //此cell是自己的，檢查附近的顏色
                if(board.get_cell_color(i,j)==color){
                    int explosion=0;
                    if(i-1>=0 && board.get_cell_color(i-1,j)!=color && board.get_cell_color(i-1,j)!='w'){
                        if((board.get_capacity(i,j)-board.get_orbs_num(i,j))==(board.get_capacity(i-1,j)-board.get_orbs_num(i-1,j)))
                            explosion++;
                        else if((board.get_capacity(i,j)-board.get_orbs_num(i,j))>(board.get_capacity(i-1,j)-board.get_orbs_num(i-1,j)))
                            continue;
                    }

                    if(i+1<=4 && board.get_cell_color(i+1,j)!=color && board.get_cell_color(i+1,j)!='w'){
                        if((board.get_capacity(i,j)-board.get_orbs_num(i,j))==(board.get_capacity(i+1,j)-board.get_orbs_num(i+1,j)))
                            explosion++;
                        else if((board.get_capacity(i,j)-board.get_orbs_num(i,j))>(board.get_capacity(i+1,j)-board.get_orbs_num(i+1,j)))
                            continue;
                    }

                    if(j-1>=0 && board.get_cell_color(i,j-1)!=color && board.get_cell_color(i,j-1)!='w'){
                        if((board.get_capacity(i,j)-board.get_orbs_num(i,j))==(board.get_capacity(i,j-1)-board.get_orbs_num(i,j-1)))
                            explosion++;
                        else if((board.get_capacity(i,j)-board.get_orbs_num(i,j))>(board.get_capacity(i,j-1)-board.get_orbs_num(i,j-1)))
                            continue;
                    }

                    if(j+1<=5 && board.get_cell_color(i,j+1)!=color && board.get_cell_color(i,j+1)!='w'){
                        if((board.get_capacity(i,j)-board.get_orbs_num(i,j))==(board.get_capacity(i,j+1)-board.get_orbs_num(i,j+1)))
                            explosion++;
                        else if((board.get_capacity(i,j)-board.get_orbs_num(i,j))>(board.get_capacity(i,j+1)-board.get_orbs_num(i,j+1)))
                            continue;
                    }
                    
                    if(explosion>currentexplosion){
                        row=i;
                        col=j;
                        currentexplosion=explosion;
                        find=true;
                    }
                    else if(explosion!=0 && explosion==currentexplosion){
                        if(board.get_capacity(i,j)<board.get_capacity(row,col)){
                            row=i;
                            col=j;
                        }
                    }
                    
                }
            }
        }
    }

    int currentk=0;
    if(!find){
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                if(board.get_cell_color(i,j)=='w'){
                    int k=0;
                    if(i-1>=0 && board.get_cell_color(i-1,j)!='w' && board.get_cell_color(i-1,j)!=color){
                        if((board.get_capacity(i-1,j)-board.get_orbs_num(i-1,j))<(board.get_capacity(i,j)-board.get_orbs_num(i,j))){
                            continue;
                        }
                        k++;
                    }
                    if(i+1<=4 && board.get_cell_color(i+1,j)!='w' && board.get_cell_color(i+1,j)!=color){
                        if((board.get_capacity(i+1,j)-board.get_orbs_num(i+1,j))<(board.get_capacity(i,j)-board.get_orbs_num(i,j))){
                            continue;
                        }
                        k++;
                    } 
                    if(j+1<=5 && board.get_cell_color(i,j+1)!='w' && board.get_cell_color(i,j+1)!=color){
                        if((board.get_capacity(i,j+1)-board.get_orbs_num(i,j+1))<(board.get_capacity(i,j)-board.get_orbs_num(i,j))){
                            continue;
                        }
                        k++;
                    }
                    if(j-1>=0 && board.get_cell_color(i,j-1)!='w' && board.get_cell_color(i,j-1)!=color){
                        if((board.get_capacity(i,j-1)-board.get_orbs_num(i,j-1))<(board.get_capacity(i,j)-board.get_orbs_num(i,j))){
                            continue;
                        }
                        k++;
                    }
                    if(k>currentk){ 
                        row=i;
                        col=j;
                        currentk=k;
                        find=true;
                    }
                    else if(k!=0 && k==currentk){
                        if(board.get_capacity(i,j)<board.get_capacity(row,col)){    
                            row=i;
                            col=j;
                        }
                    }
                }       
                
            }
        }
    }
    if(!find){
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                if(board.get_cell_color(i,j)=='w'){
                    if(i-1>=0){
                        if(board.get_cell_color(i-1,j)!='w')
                            continue;
                    }
                    if(i+1<=4){
                        if(board.get_cell_color(i+1,j)!='w')
                            continue;
                    }
                    if(j-1>=0){
                        if(board.get_cell_color(i,j-1)!='w')
                            continue;
                    }
                    if(j+1<=5){
                        if(board.get_cell_color(i,j+1)!='w')
                            continue;
                    }
                    
                    if(!find){
                        row=i;
                        col=j;
                        find=true;
                    }
                    else if(board.get_capacity(i,j)<board.get_capacity(row,col)){
                        row=i;
                        col=j;
                    }

                }
            }
        }
    }

    if(!find){
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                if(board.get_cell_color(i,j)==color && board.get_orbs_num(i,j)!=board.get_capacity(i,j)-1){
                    if(i-1>=0){
                        if(board.get_cell_color(i-1,j)!=color && board.get_cell_color(i-1,j)!='w' 
                        && (board.get_capacity(i-1,j)-board.get_orbs_num(i-1,j))<(board.get_capacity(i,j)-board.get_orbs_num(i,j)))
                        {
                            continue;
                        }
                    }
                    if(i+1<=4){
                        if(board.get_cell_color(i+1,j)!=color && board.get_cell_color(i+1,j)!='w' 
                        && (board.get_capacity(i+1,j)-board.get_orbs_num(i+1,j))<(board.get_capacity(i,j)-board.get_orbs_num(i,j)))
                        {
                            continue;
                        }
                    }
                    if(j-1>=0){
                        if(board.get_cell_color(i,j-1)!=color && board.get_cell_color(i,j-1)!='w' 
                        && (board.get_capacity(i,j-1)-board.get_orbs_num(i,j-1))<(board.get_capacity(i,j)-board.get_orbs_num(i,j)))
                        {
                            continue;
                        }
                    }
                    if(j+1<=5){
                        if(board.get_cell_color(i,j+1)!=color && board.get_cell_color(i,j+1)!='w' 
                        && (board.get_capacity(i,j+1)-board.get_orbs_num(i,j+1))<(board.get_capacity(i,j)-board.get_orbs_num(i,j)))
                        {
                            continue;
                        }
                    }
                    if(!find){
                        row=i;
                        col=j;
                        find=true;
                    }
                    else if(board.get_capacity(i,j)<board.get_capacity(row,col)){
                        row=i;
                        col=j;
                    }
                }
            }
        }
    }
    while(!find){
        row=rand()%5;
        col=rand()%6;
        if(board.get_cell_color(row,col)=='w' || board.get_cell_color(row,col)==color)
            find=true;
    }
    index[0] = row;
    index[1] = col;
}