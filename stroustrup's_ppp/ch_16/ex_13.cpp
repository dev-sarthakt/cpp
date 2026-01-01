// #include <iostream>
// #include <vector>
// #include <random>
// using namespace std;

// mt19937 gen(random_device{}());

// int rand_int(int low, int high) {
//     uniform_int_distribution<> dist(low, high);
//     return dist(gen);
// }

// struct wumpus{
//     bool alive = false;
//     int current_room = -1;
// };

// struct pit{
//     bool alive = false;
//     int current_room = -1;
// };

// struct bat{
//     bool alive = false;
//     int current_room = -1;
// };

// struct palyer{
//     bool alive = false;
//     int arrow = 5, current_room = -1;
// };

// struct room{
//     palyer sarthak;
//     wumpus wump;
//     pit pithole;
//     bat vampire;
//     int t1 = -1, t2 = -1, t3 = -1;
// };

// void gen_tunnels(vector<room> &v){
//     for (room r : v){
//         r.t1 = rand_int(0, 19);
//         r.t2 = rand_int(0, 19);
//         r.t3 = rand_int(0, 19);
//     }
// }

// void gen_wump(vector<room> &v){
//     int room = rand_int(0, 19);
//     if (v[room].pithole.alive == false && v[room].sarthak.alive == false && v[room].vampire.alive == false)
//     {
//         v[room].wump.alive = true;
//         v[room].wump.current_room = room;
//     }
//     else{
//         gen_wump(v);
//     }
// }

// void gen_pit(vector<room> &v){
//     int room = rand_int(0, 19);
//     if (v[room].wump.alive == false && v[room].sarthak.alive == false && v[room].vampire.alive == false)
//     {
//         v[room].pithole.alive = true;
//         v[room].pithole.current_room = room;
//     }
//     else{
//         gen_pit(v);
//     }
// }

// void gen_bat(vector<room> &v){
//     int room = rand_int(0, 19);
//     if (v[room].pithole.alive == false && v[room].sarthak.alive == false && v[room].wump.alive == false)
//     {
//         v[room].vampire.alive = true;
//         v[room].vampire.current_room = room;
//     }
//     else{
//         gen_bat(v);
//     }
// }

// void gen_palyer(vector<room> &v){
//     int room = rand_int(0, 19);
//     if (v[room].pithole.alive == false && v[room].wump.alive == false && v[room].vampire.alive == false)
//     {
//         v[room].sarthak.alive = true;
//         v[room].sarthak.current_room = room;
//     }
//     else{
//         gen_wump(v);
//     }
// }

// int main(){
//     bool player_alive = false, wump_alive = false;
//     vector<room> v(20);
//     gen_tunnels(v), gen_bat(v), gen_palyer(v), gen_pit(v), gen_wump(v);
//     player_alive = true, wump_alive = true;
//     while (player_alive && wump_alive)
//     {
//         for(room r : v){
//             if (r.pithole.alive == r.sarthak.alive)
//             {
//                 cout << "!! Game Over !!" << endl;
//                 exit(0);
//             }
//             else if (r.pithole.alive == r.wump.alive)
//             {
//                 cout << "!! Congrulations You Won !!" << endl;
//                 exit(0);
//             }
//             else if ((v[r.t1].pithole.alive || v[r.t2].pithole.alive || v[r.t3].pithole.alive) == r.sarthak.alive)
//             {
//                 cout << "I feel a breeze." << endl;
//             }
//             else if (r.vampire.alive == r.sarthak.alive)
//             {
//                 int temp = rand_int(0,2);
//                 if (temp == 0)
//                 {
//                     r.sarthak.alive = false;
//                     r.sarthak.current_room = -1;
//                     v[r.t1].sarthak.alive = true;
//                     v[r.t1].sarthak.current_room = r.t1;
//                 }
//                 else if (temp == 1)
//                 {
//                     r.sarthak.alive = false;
//                     r.sarthak.current_room = -1;
//                     v[r.t2].sarthak.alive = true;
//                     v[r.t2].sarthak.current_room = r.t2;
//                 }
//                 else if (temp == 2)
//                 {
//                     r.sarthak.alive = false;
//                     r.sarthak.current_room = -1;
//                     v[r.t3].sarthak.alive = true;
//                     v[r.t3].sarthak.current_room = r.t3;
//                 }
//             }
//             else if (r.vampire.alive == r.wump.alive)
//             {
//                 int temp = rand_int(0,2);
//                 if (temp == 0)
//                 {
//                     r.wump.alive = false;
//                     r.wump.current_room = -1;
//                     v[r.t1].wump.alive = true;
//                     v[r.t1].wump.current_room = r.t1;
//                 }
//                 else if (temp == 1)
//                 {
//                     r.wump.alive = false;
//                     r.wump.current_room = -1;
//                     v[r.t2].wump.alive = true;
//                     v[r.t2].wump.current_room = r.t2;
//                 }
//                 else if (temp == 2)
//                 {
//                     r.wump.alive = false;
//                     r.wump.current_room = -1;
//                     v[r.t3].wump.alive = true;
//                     v[r.t3].wump.current_room = r.t3;
//                 }
//             }
//             else if ((v[r.t1].vampire.alive || v[r.t2].vampire.alive || v[r.t3].vampire.alive) == r.sarthak.alive)
//             {
//                 cout << "I hear a bat." << endl;
//             }

//         }
//     }
    
//     return 0;
// }
