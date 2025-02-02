#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    //asignamos memoria dinamica para la estructura
    this = (LinkedList*)malloc(sizeof(LinkedList));
  //VALIDO QUE no sea null para cargar los campos,
    if(this != NULL)
    {
	 //inicializamos sus campos //valores default para construir
		//cuando la creemos, por supuesto, el tama�o va a ser 0
		this->size = 0;
		//Todavia no cargamos ningun elemento en la lista, por ende, el unico apuntador(lo que apunta el primer nodo) va a mirar a NULL
		 this->pFirstNode = NULL;
		   //linked list es una estructura que contiene en cada nodo, un elemento de determinada structura y el apuntador al siguiente nodo
    }



    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	//simplemente retorna el tama�o de la estructura
    	returnAux = this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodo = NULL;
	int i;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNodo = this->pFirstNode;
		//La linked_list no funcion como un array,para obtener las posiciones necesitamos recorrer nodo por nodo hasta obtener el nodo anterior al que buscamos , ya que este contiene en nextNode la referencia al nodo que buscamos
		for(i=0;i<nodeIndex;i++)
		{
			pNodo = pNodo->pNextNode;
		}

	}


    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodo = NULL;
    Node* pAuxNodo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {

    	pNodo = (Node*)malloc(sizeof(Node));
    	if(pNodo != NULL)
    	{

    		if(nodeIndex == 0)
    		{
    			pAuxNodo = this->pFirstNode;
    			this->pFirstNode = pNodo;
    			pNodo->pElement = pElement;
    			pNodo->pNextNode = pAuxNodo;

    			this->size++;
    			returnAux = 0;
    		}
    		else
    		{
    			pAuxNodo = getNode(this, nodeIndex-1);
    			if(pAuxNodo != NULL)
    			{
    				pNodo->pNextNode = pAuxNodo->pNextNode;
    				pNodo->pElement = pElement;
    				pAuxNodo->pNextNode = pNodo;

    				this->size++;
    				returnAux = 0;
    			}
    			else
    			{
    				free(pNodo);
    			}
    		}
    	}
    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(addNode(this, ll_len(this), pElement) == 0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pAuxNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pAuxNode = getNode(this, index);
    	if(pAuxNode != NULL)
    	{
    		returnAux = pAuxNode->pElement;
    	}
    }


    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pAuxNode = NULL;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	pAuxNode = getNode(this, index);
    	if(pAuxNode != NULL)
    	{
    		pAuxNode->pElement = pElement;
    		returnAux = 0;
    	}

    }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pAuxNode = NULL;
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	if(index == 0)
    	{
    		pAuxNode = this->pFirstNode->pNextNode;
    		free(this->pFirstNode);
    		this->pFirstNode = pAuxNode;
    		//aca te falto enganchar el first node al siguiente
    		/*free(this->pFirstNode);
    		this->pFirstNode = NULL;*/
    		this->size--;
    		returnAux = 0;
    	}
    	else
    	{
			pAuxNode = getNode(this, index-1);
			pNode = getNode(this, index);
			if(pAuxNode != NULL && pNode != NULL)
			{
				pAuxNode->pNextNode = pNode->pNextNode;
				free(pNode);

				this->size--;
				returnAux = 0;

			}
    	}
    }


    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	Node* pAuxNode = NULL;
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		pAuxNode = getNode(this, i);
    		if(pAuxNode != NULL)
    		{
    			ll_remove(this, i);
    		}
    	}

    	returnAux = 0;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
    		free(this);
    		returnAux = 0;
    	}
    }


    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    void* pAuxElement = NULL;

    if(this != NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{

    		pAuxElement = ll_get(this, i);
    		if(pAuxElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this) == 0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

	if(this != NULL && index >= 0 && index <= ll_len(this))
	{
		 if(addNode(this, index, pElement) == 0)
		 {
			 returnAux = 0;
		 }

	}

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pAuxElement = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pAuxElement = ll_get(this, index);
    	if(ll_remove(this, index) == 0)
    	{
    		returnAux = pAuxElement;
    	}
    }


    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;


    if(this != NULL)
    {
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }


    return returnAux;
}

/*int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* aux;
    int i;
    int len=ll_len(this);

    if(this!=NULL){
    	returnAux=0;
    	for(i=0;i<len;i++){
    		aux=getNode(this, i);
    		if(aux->pElement==pElement){
    			returnAux=1;
    			break;
    		}
    	}
    }
    return returnAux;
}*/

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	int i;

	if(this != NULL && this2 != NULL)
	{
		returnAux = 1;
		for(i=0;i<ll_len(this2);i++)
		{
			if((ll_contains(this, ll_get(this2, i))) == 0)
			{
				returnAux = 0;
				break;
			}
		}
	}


	   return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;

    if(this != NULL && from > -1 && from < to && to <= ll_len(this) )
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for(i=from;i<to;i++)
			{
    			if(ll_add(cloneArray, ll_get(this, i)) != 0)
    			{
    				ll_deleteLinkedList(cloneArray);
    			}

			}
    	}
    }


    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    	if(cloneArray == NULL)
    	{
    		ll_deleteLinkedList(cloneArray);
    	}

	}

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio ; retorna  (1) si void1 > void2 o (-1) si  void1 < void2
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* auxElement;
    int i,j;

    if(this != NULL && pFunc != NULL && order > -1 && order < 2)
    {
    	if(order == 1)
		{
    		for(i=0;i<ll_len(this)-1;i++)
			{
    			for(j=i+1;j<ll_len(this);j++)
    			{
    				if(pFunc(ll_get(this, i),ll_get(this, j)) == 1)
    				{
    					auxElement = ll_get(this, i);
    					ll_set(this, i, ll_get(this,j));
    					ll_set(this, j,auxElement);
    				}
    			}
			}
		}
		else
		{
			for(i=0;i<ll_len(this)-1;i++)
			{
				for(j=i+1;j<ll_len(this);j++)
				{
					if(pFunc(ll_get(this, i),ll_get(this, j)) == -1)
					{
						auxElement = ll_get(this, i);
						ll_set(this, i, ll_get(this,j));
						ll_set(this, j,auxElement);
					}
				}
			}
		}


    	returnAux = 0;
    }


    return returnAux;
}

