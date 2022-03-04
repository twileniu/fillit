/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:12:48 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/03 15:20:29 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_board_size()
{
    g_size = 0;
    while (g_size * g_size < g_npieces * 4)
        ++g_size;
}

static int ft_checkplacement(char *board, char j)
{
    int i;
    int adj;
    int count;

    count = 0;
    i = 0;
    adj = 0;
    while (board[i] != '\0')
    {
        if(board[i] == j && board[i - 1] == j && count > 0)
            ++adj;
        if(board[i] == j && board[i + 1] == j && count < (g_size * (g_size + 1)))
            ++adj;
        if(board[i] == j && board[i - (g_size + 1)] == j && count > g_size)
            ++adj;
        if(board[i] == j && board[i + (g_size + 1)] == j && count < (g_size * (g_size + 1) - 4))
            ++adj;
        ++i;
        ++count;
    }
    if (adj == 6 || adj == 8)
        return (1);
    else
        return (0);
}

static void    ft_clear(char *board, int j)
{
    int i;

    i = 0;
    while (board[i] != '\0')
    {
        if (board[i] == j)
            board[i] = '.';
        ++i;    
    }
}

static int    ft_place(char *board, char *tetrilist, int k)
{
    int        i;
    int        count;
    char    letter;

    i = 0;
    count = 0;
    //printf("%s\n", tetrilist); //Tänne lähetetään palanen mist otettu tyhjät pois
    letter = tetrilist[i]; //tyhjät pois palan eka merkki 'A'/'B'/'C' jne.
    while (tetrilist[i])
    {
        //Jos size == 3 k--
        //Jos size > 4, k += (size - 4), eli jos 5 k++, jos 6 k += 2
        if (tetrilist[i] == '\n' && g_size == 3) // Jos size < tetri size
            k--;    //k pienemmäks, koska board yhden "edellä"
        if (tetrilist[i] == '\n' && g_size > 4) //Jos size > tetri size
            k += (g_size - 4);    //k:hon += "board size" - "tetri size", koska muuten
        if (k > g_size * (g_size + 1) || board[k] == '\0')
            break ;
        if (board[k] == '.' && tetrilist[i] > '@') //Jos boardilla on '.' ja palasessa 'kirjain'
        {
            board[k] = tetrilist[i];                //pisteen tilalle kirjain
            ++count;    //lasketaan montako 'kirjainta' asetettu (Max 4)
        }
        k++; //boardia yks eteenpäi
        i++; //palasta yks eteenpäi
        if (count == 4) //jos neljä kirjain laitettu chekataan osuko ne
            break ;
    }
    if (ft_checkplacement(board, letter)) //tsekki osuks palanen laudalle oikein
        return(1);
    return(0);
}

static char    *ft_algo(char *board, char **tetrilist)
{
    int    k;
    int i;
    int    j;

    k = 0;
    i = 0;
    j = 0;
    //tetrilist[j][i] vähä turha vois olla vaa: tetrilist[0][0] xd
    if (!tetrilist[j])    //Jos palaa ei oo -> return vastaus
        return (board); //palauttaa tän jos tetrilist == NULL, eli ei oo enää palasia
    while (tetrilist[j] && tetrilist[j][i] < '@') //Tyhjät pois palasesta
        tetrilist[j]++; //incrementoidaan pointteria tetrilistin nykyiseen jäseneen (tyhjät pois), voidaan lähettää pointteri ft_placeen eikä tarvi kikkailla indekseillä
    while (board[k])    //nii kaua ku board[k]:ssa on tilaa, koitetaan asettaa palanen joka kohtaa
    {
        if (ft_place(board, tetrilist[0], k) != 1) //Jos place ei onnistu
            ft_clear(board, *tetrilist[0]);//tänne board ja tyhjät pois palasen eka char, eli esim 'A'
        else if (!ft_algo(board, &tetrilist[1])) //Jos algo->place ei onnistu seuraaval palal, nii sillo myös clear: Tähän tulee stäkki kaikist yrityksist ja jos tähä palataan se 
            ft_clear(board, *tetrilist[0]);
        else
            return (board); //Jos place onnistuu JA algo (eli algo->place) onnistuu seuraaval palal (ks. rivi 106), meil on oikee vastaus
        k++;

    }
    //... Jos on viel palasia ja algo kusee menee tänne -> isompi boardi
    return (NULL);
}

/*Tääl mallocoidaa ja kasvatetaa boardii aina tarpeen mukaa jos algo kusee myöhemmi
    ja lopuks printataa oikee vastaus
*/

void    ft_solver(char **tetrilist)
{
    char        *board;
    size_t        i;
    int        k;
    int        count;

    count = 0;
    k = 0;
    ft_board_size();
    board = ft_strnew(g_size * (g_size + 1) + 1);
    if (!board || !tetrilist)
        ft_error();
    while (count < g_npieces)
    {
        count++;
        i  = 0;
        while ((int)i < g_size * (g_size + 1))
        {
            board[i] = '.';
            if (i % (g_size + 1) == g_size)
                board[i] = '\n';
            ++i;    
        }
        board = ft_algo(board, tetrilist);
        if (!board)    //jos algo kusee -> isompi board
        {
            g_size++;
            free(board);
            board = ft_strnew(g_size * (g_size + 1));
        }
        else    //muulloin breakataa pois whilest ja printataa vastaus
            break ;
    }
    ft_putstr(board);
}