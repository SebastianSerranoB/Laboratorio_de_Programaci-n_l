/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

    void ordenarDobleCriterio(eTicket listaTickets[],int tam)
{
	int i;
	int j;
	eTicket aux;


	for(i=0;i<tam-1;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			if(strcmp(listaTickets[i].nombre, listaTickets[j].nombre)>0)
			{
				aux = listaTickets[i];
				listaTickets[i] = listaTickets[j];
				listaTickets[j] = aux;
			}
			else
			{
				if(strcmp(listaTickets[i].nombre, listaTickets[j].nombre)==0)
				{
					if(listaTickets[i].horarioSalida> listaTickets[j].horarioSalida)
					{
						aux = listaTickets[i];
						listaTickets[i] = listaTickets[j];
						listaTickets[j] = aux;
					}

				}

			}
		}

	}


}


