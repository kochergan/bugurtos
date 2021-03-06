/**************************************************************************
    BuguRTOS-2.0.x (Bugurt real time operating system)
    Copyright (C) 2016 anonimous

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Please contact with me by E-mail: shkolnick.kun@gmail.com

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes BuguRTOS, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
**************************************************************************/

/*****************************************************************************************
```````````````````````````````..:+oyhdmNNMMMMMMNmmdhyo+:..```````````````````````````````
``````````````````````````.:oydNMMMMMMMMMNNNNNNNNMMMMMMMMMNdy+:.``````````````````````````
```````````````````````:sdNMMMMMNdys+/::----------::/osydNMMMMMNds:```````````````````````
```````````````````.+hNMMMMmho/-..........................-/shmMMMMNh/.```````````````````
````````````````./hNMMMNho:...................................-:ohNMMMNh/`````````````````
``````````````.smMMMNy/-.......:////ss++/+-.......................-+yNMMMmo.``````````````
````````````-sNMMMd+-.....:////:-...-/s::..............+o/-..........-odMMMNs.````````````
``````````.sNMMNh/....................................-o:--............./hMMMNo.``````````
`````````+mMMMh:-........................................-...............-/dMMMm/`````````
```````.yMMMm/...................-::--..................:-........--........+mMMMy.```````
``````:mMMMy-.......................-::-...............-:.........-::........-yMMMd:``````
`````/NMMN+-..................::-.....-:-............../--.........-:/-.......-+NMMN:`````
````+NMMm::o/-..--/+o+o+++++o+osys+//::-::.............:/....-:-::-..-++-.......:NMMN/````
```/NMMm:.-++-+yhs/-``       `dMMMMMmho+:-..............:-/+yho/:/+oyo//o-......./mMMN:```
``-NMMm/....-/--::/o+o+oo+oo++oosyss+smyo/.............:yyho-`     smMMddh-......./NMMN.``
`.hMMM/......-++:-.-:oooooooooosyyhhys/...............-+osyyyyysssssooo+ohhs-......+MMMh.`
`+MMMy.......-::/++:-.....-:/++++o+o/--................--/oooo+o++o+++////-y/.......hMMM/`
.mMMN:.........--:---...-::/+//::--.......................--//+//-...-.....+/......./NMMd`
/MMMy............-::----------....----/+-.....................-++/:---....-o-........hMMN:
yMMM/.............--:://///oo+++/+++oo+-.......................-://+/:--::::.........+MMMs
mMMN:................----:/h:::/:/::---.........................--/osss+++:..........:NMMd
MMMd-....................:mNs:-....................................--:odo:-..........:mMMN
MMMd-....................yoshyoso:--................................../mm/...........:mMMM
MMMm:..................../-o/h.y-:+dooo+/:--....................-/osydddmh...........:mMMN
mMMN:........................+mNs `h.  -d/:/+h++ooooy+++s++y+++mo+y` yh.do...........:NMMh
sMMM+........................-hmMo/ds  oMo`.-o     :h   s:`h` `Nysd.-Ny-h:...........+MMMo
/MMMh........................./smMMMMd+NMMNNMh`    sN: .mNNMddNMMMMNmN+..............hMMN:
.dMMN/........................./+hMMMMMMMMMMMMmhyyyNMNNMMMMMMMMMMMNsoo-............./NMMd`
`+MMMh.........................-/+omMMMMMMMMMMMMMMMMMMMMMMMMMMMMms-/+...............hMMM/`
`.hMMM+..........................:/-omMMMMMMMMMMMMMMMdmMdhMMMds/-..-...............oMMMy``
``.NMMN/............................--/hNN/h.`ys:dmsd:-syos+--+.................../NMMN.``
```/NMMm:...........................:+/--:+s++oo+osoo+/:-..-/+::-................/mMMN:```
````/NMMN:............................-/++/:-..........-//+/-..:+.--............/NMMN/````
`````:NMMN+-.............../+-.............-://////////:-.......+s+::.........-oNMMN:`````
``````:mMMMy-..............:/o-.................................:yo//........-hMMMd-``````
```````.yMMMm+.............:o:++-...............................+y+o-......-+mMMMs.```````
`````````/mMMMd/-...........-++:+/-.---........................-ho+/.....-/dMMMm/`````````
``````````.oNMMMh/............-++:++/////:....................-yo:o-...-+hMMMNo.``````````
````````````.sNMMMdo-...........-++::++:-:/+//:..............:o:/o-..-omMMMNo.````````````
``````````````.omMMMNy+-..........-/+-.:/+/:--:+++/++//:/::/+/-+/.-+hMMMMmo```````````````
`````````````````/hNMMMNho:-...............-:/:-....--::::--..-/ohNMMMNy:`````````````````
```````````````````./hNMMMMmhs/-..........................-/shNMMMMNy/.```````````````````
```````````````````````:sdNMMMMMNdhso+/:----------:/+oshdNMMMMMNho:```````````````````````
``````````````````````````.:+ydNMMMMMMMMMMNNNNNNMMMMMMMMMMmds+:```````````````````````````
````````````````````````````````.:/osyhdmNNMMMMNNmdhyso/:.````````````````````````````````
******************************************************************************************
*                                                                                        *
*                   This logo was graciously delivered by 10003-kun ITT:                 *
*                                                                                        *
*                           http://www.0chan.ru/r/res/9996.html                          *
*                                                                                        *
*****************************************************************************************/
#include "bugurt.h"

/* ADLINT:SF:[W0422] NULL */

#ifndef BGRT_VINT_CS_START
#   define BGRT_VINT_CS_START() bgrt_disable_interrupts()
#endif //BGRT_VINT_CS_START

#ifndef BGRT_VINT_CS_END
#   define BGRT_VINT_CS_END() bgrt_enable_interrupts()
#endif //BGRT_VINT_CS_END

void bgrt_vint_init(bgrt_vint_t * vint, bgrt_prio_t prio, bgrt_code_t func, void * arg)
{
    bgrt_pitem_init((bgrt_pitem_t *)vint, prio);
    vint->func = func;
    vint->arg = arg;
}

void bgrt_vic_init(bgrt_vic_t * vic)
{
    bgrt_xlist_init((bgrt_xlist_t *)vic);
    //Must be LOWER, than lowest valid priority
    vic->prio = BGRT_PRIO_LOWEST + 1 ; /* ADLINT:SL:[W0165] signed/unsigned*/
}

bgrt_st_t bgrt_vint_push_isr(bgrt_vint_t * vint, bgrt_vic_t * vic)
{
    if (((bgrt_pitem_t *)vint)->list)
    {
        return BGRT_ST_EAGAIN;
    }
    else
    {
        bgrt_pitem_insert((bgrt_pitem_t *)vint, (bgrt_xlist_t *)vic);
        return BGRT_ST_OK;
    }
}

bgrt_st_t bgrt_vint_push(bgrt_vint_t * vint, bgrt_vic_t * vic)
{
    bgrt_st_t ret;
    //Everything is done on local CPU core, just disable interrupts.
    BGRT_VINT_CS_START();
    //Insert
    ret = bgrt_vint_push_isr(vint, vic);
    //May enable interrupts
    BGRT_VINT_CS_END();
    return ret;
}

static bgrt_vint_t * bgrt_vint_pop(bgrt_vic_t * vic)
{
    bgrt_pitem_t * ret;
    //Everything is done on local CPU core, just disable interrupts.
    BGRT_VINT_CS_START();
    //Get list head
    ret = (bgrt_pitem_t *)bgrt_xlist_head((bgrt_xlist_t *)vic);
    //Is there any work?
    if (ret)
    {
        //Cut it.
        bgrt_pitem_cut(ret);
    }
    //May enable interrupts
    BGRT_VINT_CS_END();
    //We must return virtual interrupt
    return (bgrt_vint_t *)ret;
}

void bgrt_vic_do_work(bgrt_vic_t * vic)
{
    //Remember last priority
    bgrt_prio_t lprio;
    lprio = vic->prio;
    //Do some pending work...
    while (1)
    {
        bgrt_vint_t * work;
        work = bgrt_vint_pop(vic);
        //Is there any work?
        if (work)
        {
            //work_prio is used twice, so remember it.
            bgrt_prio_t work_prio;
            work_prio = ((bgrt_pitem_t *)work)->prio;
            //Do only higher priority work...
            if (work_prio < lprio)
            {
                //func is used twice, so...
                bgrt_code_t func;
                func = work->func;
                //Is it valid?
                if (func)
                {
                    //Remember current priority
                    vic->prio = work_prio;
                    // Do work.
                    func(work->arg);
                }
            }
            else
            {
                //Nothing to do, exit.
                break; /* ADLINT:SL:[W0605] signed/unsigned*/
            }
        }
        else
        {
            //Nothing to do, exit.
            break; /* ADLINT:SL:[W0605] signed/unsigned*/
        }
    }
    //Remind last priority
    vic->prio = lprio;
}
