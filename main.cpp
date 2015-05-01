#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int GetnumHumans();
int GetnumSkeletons();
void SimulateBattle(int NumberHumans,int NumberSkeletons,int &endSkeletons,int &endHumans);
void Returnresults(int endHumans,int endSkeletons,int startHumans,int startSkeletons);


int main()
{

    int startSkeletons;
    int startHumans;

    int endSkeletons;
    int endHumans;

    int NumberHumans;
    int NumberSkeletons;


    NumberHumans=GetnumHumans();
    startHumans=NumberHumans;
    NumberSkeletons=GetnumSkeletons();
    startSkeletons=NumberSkeletons;


    int healthHuman=250;
    int healthSkeleton=185;
    const int maXattackDamageHuman=100;
    const int maXattackDamageSkeleton=75;

     //write the health and attack damage of a human
    cout<<"\nThe health of a humans is:"<<healthHuman<<endl;
    cout<<"The maximum attack damage of a human is:"<<maXattackDamageHuman<<endl;

    //write the health and attack damage of a skeleton
    cout<<"\nThe health of a skeleton is:"<<healthSkeleton<<endl;
    cout<<"The maximum attack damage of a skeleton is:"<<maXattackDamageSkeleton<<endl;


    //Read the number of humans and skeletons
    cout<<"\nThere are "<<NumberHumans<<" Humans fighting"<<endl;
    cout<<"There are "<<NumberSkeletons<<" Skeletons fighting"<<endl;





    //int hd=0;   //initial human damage
    //int ahd=0;  //initial attack human damage is the sum of each human damage
    //int hs=0;   //initial skeleton damage
    //int ads=0;  //initial attack skeleton damage is the sum of each human damage
    //int h=0;    //initial number of humans
    //int s=0;    //initial number of skeletons

    //while (h!=NumberHuman)
   //{
        //int nrh=0;

        //while (nrh<NumberHuman)
        //{
            //nrh++;

        //int AttackDamageHuman=CombatModeHumansDamage(RandomGenerator);

        //hd=AttackDamageHuman;
        //cout<<"\nHuman"<<" nr."<<nrh<<" damage is: "<<hd<<endl;
        //ahd+=hd;
        //cout<<"The total of humans damage:"<<ahd<<endl;
        //h++;
        //}
    //}




    //while (s!=NumberSkeletons)
    //{
        //int nrs=0;

        //while (nrs<NumberSkeleton)
        //{
            //nrs++;

        //int AttackDamageSkeleton=CombatModeSkeletonsDamage(RandomGenerator);

        //hs=AttackDamageSkeleton;
        //cout<<"\nSkeleton"<<" nr."<<nrs<<" damage is: "<<hs<<endl;
        //ads+=hs;
        //cout<<"The total of skeletons damage: "<<ads<<endl;
        //s++;
        //}
    //}


        //while (healthHuman>=0)
        //{
            //int AttackDamageSkeleton=CombatModeSkeletonsDamage(RandomGenerator);

            //cout<<"\nSkeleton attack damage is:"<<AttackDamageSkeleton<<endl;

            //cout<<"(Combat noises!)\n";

           // healthHuman-=AttackDamageSkeleton;
            //cout<<"Human health is:"<<healthHuman<<endl;

        //}
            //cout<<"\nHuman defeated!"<<endl;


        SimulateBattle(NumberHumans,NumberSkeletons,endSkeletons,endHumans);
        Returnresults(endHumans,endSkeletons,startHumans,startSkeletons);

        return 0;
}


int GetnumHumans()
{
     //Write the number of humans
    cout<<"Enter the number of humans:";
    int NumberHumans;
    cin>>NumberHumans;

    return NumberHumans;
}

int GetnumSkeletons()
{
    //Write the number of skeletons
    cout<<"Enter the number of skeletons:";
    int NumberSkeletons;
    cin>>NumberSkeletons;

    return NumberSkeletons;
}


void Returnresults(int endHumans,int endSkeletons,int startHumans,int startSkeletons)
{

                if ((endHumans!=0) && (endSkeletons==0))
                    {
                    cout<<"\n***The number of Humans alive is:"<<endHumans<<"***"<<endl;
                    cout<<"\n\t*****Humans won!*****"<<endl;
                    }

                else if ((endSkeletons!=0) && (endHumans==0))
                 {
                    cout<<"\n***The number of Skeletons alive is:"<<endSkeletons<<"***"<<endl;
                    cout<<"\n\t*****Skeletons won!*****"<<endl;
                 }

        //Kill count
       cout<<endl<<"   "<<startHumans-endHumans<<" humans and "
                 <<startSkeletons-endSkeletons
                 <<" skeletons have lost their lives\n\n";
}

void SimulateBattle(int NumberHumans,int NumberSkeletons,int &endSkeletons,int &endHumans)
{

    //creating the random generator and assigning it to generate the human damage,the skeleton damage and what the fighter is human or skeleton
    static mt19937 RandomGenerator(time(0));
    uniform_int_distribution<int> CombatModHumansDamage(0,100);
    uniform_int_distribution<int> CombatModSkeletonsDamage(0,75);
    uniform_int_distribution<int> CombatModHumanvsSkeleton(0,1);

    int healthHuman=250;
    int healthSkeleton=185;
    int currentskeletonHealth=healthSkeleton;
    int currenthumanHealth=healthHuman;


    //******this way we get in to the fight with the human first then the skeleton and so on
        //int FirstPick=0;

    //######first we are going to use a random generator to get the fight on going


     while ((NumberHumans!=0) && (NumberSkeletons!=0))
        {
            //this way we're using a random generator to figure out which fighter is attacking
            int FirstPick= CombatModHumanvsSkeleton (RandomGenerator);


            if (FirstPick==1)   //is the skeleton's time to attack
            {
                cout<<"\nSkeleton is attacking!";

                int AttackDamageSkeleton=CombatModSkeletonsDamage (RandomGenerator);

                cout<<"\nSkeleton damage is:"<<AttackDamageSkeleton;
                cout<<"\n(Combat noises!)";

                currenthumanHealth-=AttackDamageSkeleton;

                cout<<"\nHuman health is:"<<currenthumanHealth<<endl;

                if (currenthumanHealth<=0)
                {
                    currenthumanHealth=healthHuman;
                    cout<<"\nHuman defeated!"<<endl;
                    NumberHumans--;
                    endHumans=NumberHumans;
                    cout<<"\nThe number of humans remaining is:"<<endHumans<<endl;

                }
                     //if we don't use the random generator we have to initialize that the next fighter is the human
                    //FirstPick=0;
            }
         else    //is the human's time to attack
            {
                cout<<"\nHuman is attacking!";

                int AttackDamageHuman=CombatModHumansDamage (RandomGenerator);

                cout<<"\nHuman damage is:"<<AttackDamageHuman;
                cout<<"\n(Combat noises!)";

                currentskeletonHealth-=AttackDamageHuman;

                cout<<"\nSkeleton health is:"<<currentskeletonHealth<<endl;

                if (currentskeletonHealth<=0)
                {
                    currentskeletonHealth=healthSkeleton;
                    cout<<"\nSkeleton defeated!"<<endl;
                    NumberSkeletons--;
                    endSkeletons=NumberSkeletons;
                    cout<<"\nThe number of Skeletons remaining is:"<<endSkeletons<<endl;

                }
                    //if we don't use the random generator we have to initialize that the next fighter is the skeleton
                   //FirstPick=1;
            }
        }
}
