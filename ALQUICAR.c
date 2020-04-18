#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//No se como poner el %  cuando digo 100% si escribo 100PORCIEN queda un poco mal


struct coches{
	char stock[100]; //los que tenemos
	char reserva[100]; //los que hay que quitar del fichero de stock
	char comprador[100];
};
struct registro{
	char nombre[50],correo[100],contra[100],poblacion[20];
	char codPos[10],telefono[20];
};


int main (){
	system ("color 3f" );
	int opcion, categoria,inicio,i,ncoches;
	int permiso=0; //Comprueba que se ha logueado
	int arrobas=0,puntos=0,error=0, mayus=0, num=0;
	struct registro usuario[100];
	int contUsuarios=0;
	//DATOS LOGING
	int salirlog,j; //la j da la posicion en el fichero del usuario que se ha logueado
	char contra[20],correo[100];
	struct coches coches[100];
	int coche; //indica la posicion del coche que se quiere reservar en el fichero
	int aceptar; //acepta la reserva
	int nreservas=0,t; //cuenta las reservas
	FILE * pUsuarios;
	FILE * pCoches;
	FILE * pReservas;
	
	
	printf("                      _______ ______ _______ _____  __________________________ ________    \n");
    printf("           ||     |  ___    |___  / __  _  |__  / / /____  _/__  ____/___    |___  __ |  | \n");
	printf("      .----|-----,|  __  /| |__  /  _  / / /_  / / /  __  /  _  /     __  /| |__  /_/ /  | \n");
	printf("      ||  ||   ==||  _  ___ |_  /___/ /_/ / / /_/ /  __/ /   / /___   _  ___ |_  _, _/   | \n");
	printf(" .-----'--'|   ==||  /_/  |_|/_____/\___|_|   \____/   /___/   |____/   /_/  |_|/_/ |_|    | \n");
	printf(" |)-      ~|     ||______________________________________________________________________| \n");
	printf(" | ___     |     |____...==..._  >                  |______________________________|       \n");
	printf("[_/.-.\'--''-------- |/.-.  .-.\\/                     |/            || .-.  .-. ||        \n");
	printf("  ( o )`===''''''''''`( o )( o )                     o              `( o )( o )`         \n");
	printf("   '-'                 '-'  '-'                                       '-'  '-'           \n");
	printf("\n\n");
	
	
	printf("Le mostraremos a continuacion el menu:\n\n");
	//system ("clc"); (limpia la pantalla)
	
	
		pUsuarios = fopen("usuarios.txt","r");
	if (pUsuarios == NULL){ 
		printf("No se encuentra fichero");
		return 0;
		}
	contUsuarios=0;
	while(fscanf(pUsuarios, "%s %s %s %s %s %s", usuario[contUsuarios].nombre,usuario[contUsuarios].correo,usuario[contUsuarios].contra,usuario[contUsuarios].poblacion,&usuario[contUsuarios].codPos,&usuario[contUsuarios].telefono) != EOF){ 
		//Para ver los Usuarios registrados activa el siguiente printf
		//printf(%s %s %s %s %d %d, usuario[contUsuarios].nombre,usuario[contUsuarios].correo,usuario[contUsuarios].contra,usuario[contUsuarios].poblacion,&usuario[contUsuarios].codPos,&usuario[contUsuarios].telefono);
		contUsuarios++;
		}
		fclose(pUsuarios);
		//para ver los usuarios registrados activa el siguiente printf
		//printf("%d\n",contUsuarios);
	
	
	do{

		printf ("SELECCIONE UNA DE LAS SIGUIENTES OPCIONES \n\n");
		printf ("1-REGISTRARSE \n\n");
		printf ("2-INICIAR SESION \n\n");
		printf ("3-VER CATALOGO \n\n"); /*No es necesario registrarse para verlo*/
		printf ("4-MIS RESERVAS \n\n"); /* Es obligatorio el registro para hacer reservas*/
		printf ("5-QUIENES SOMOS \n\n");
		printf ("6-CERRAR MENU \n\n");
		scanf("%d", &opcion);


	switch (opcion){
		case 1: 
			printf("SE VA A LLEVAR A CABO SU REGISTRO: \n");
			printf("Introduzca su nombre y apellidos: \n");
			fflush (stdin);
			gets(usuario[contUsuarios].nombre);
			i=0;
			while (usuario[contUsuarios].nombre[i]!='\0'){
				if(usuario[contUsuarios].nombre[i]==' '){
					usuario[contUsuarios].nombre[i]='_';
				}
				i++;
			}
			fflush (stdin);
			
			do{ 
			printf("Introduzca un correo operativo, este a su vez sera su NOMBRE DE USUARIO: \n");
			gets(usuario[contUsuarios].correo);
			i=0;
			arrobas=0;
			puntos=0;
			while (usuario[contUsuarios].correo[i]!='\0'){
				if (usuario[contUsuarios].correo[i]=='@'){
					arrobas++;
				}
				else if (usuario[contUsuarios].correo[i]=='.'){
					puntos++;
				}
					i++;
				}
			}while (arrobas!=1 || puntos<1 );
				fflush (stdin);
			do{
				printf("Introduzca una contrasena: \n");
				if(error>0) 	
					printf("La contraseña debe tener una mayuscula, un numero y mas de 5 caracteres\n");
					gets(usuario[contUsuarios].contra);
					i=0;
					num=0;
					mayus=0;
				while(usuario[contUsuarios].contra[i]!='\0'){
					if (usuario[contUsuarios].contra[i]>'0'&& usuario[contUsuarios].contra[i]<'9'){
					num++;
					}
					if(usuario[contUsuarios].contra[i]>'A'&& usuario[contUsuarios].contra[i]<'Z'){
					mayus++;
					}
					i++;
				} 
				error++;
			} while(num<=0 || mayus<=0 || strlen(usuario[contUsuarios].contra)<5);
				fflush (stdin);
				printf("Introduzca su poblacion: \n"); //sin espacios
				scanf("%s", usuario[contUsuarios].poblacion);
				i=0;
			while (usuario[contUsuarios].poblacion[i]!='\0'){
				if(usuario[contUsuarios].poblacion[i]==' '){
					usuario[contUsuarios].poblacion[i]='_';
				}
				i++;
			}
				fflush (stdin);
				error=0;
			do{
				printf("Introduzca su codigo postal: \n");
				if(error>0) printf("El codigo postal debe ser valido\n");
					scanf("%s", &usuario[contUsuarios].codPos);
					error++;
			}while(strlen(usuario[contUsuarios].codPos)!=5);
				fflush (stdin);
				error=0;
			do{
			printf("Por ultimo introduzca su telefono movil: \n");
			if(error>0) printf("El numero introducido debe ser valido\n");
				scanf("%s", &usuario[contUsuarios].telefono);
				error++;
			}while(strlen(usuario[contUsuarios].telefono)!=9);
			printf("Su registro se ha realizado con exito \n");
			
			pUsuarios = fopen("usuarios.txt","w");
		if (pUsuarios == NULL){ 
			printf("No se encuentra fichero");
			return 0;
		}
		for(i=0;i<=contUsuarios;i++){
			fprintf(pUsuarios, "%s %s %s %s %s %s\n", usuario[i].nombre,usuario[i].correo,usuario[i].contra,usuario[i].poblacion,usuario[i].codPos,usuario[i].telefono);
		}
		fclose(pUsuarios);
			
			
			system("PAUSE()");
			system("CLS()");
			
		break;


		case 2: 
			error=0;
			do{
				if(error!=0){
					printf("ERROR AL INICIAR SESION\n");
					printf("EL CORREO Y LA CONTRASENA NO COINCIDEN, INTENTELO DE NUEVO:\n");
					printf("Si no quieres iniciar sesion pulse 1\n");
					printf("En caso contrario pulse cualquier otra letra\n");
					scanf("%d",&salirlog);
					if(salirlog==1){
						break;
					}
				}
				else{printf("INICIA TU SESION \n");
				}
			fflush (stdin);
			printf("Introduzca su correo:\n");
			gets(correo);
			fflush (stdin);
			printf("Introduzca la contrasena:\n");
			gets(contra);
			//COMPROBACION DE LOGING:
			for(j=0;j<=contUsuarios;j++){
				permiso=0;
				if(strcmp(correo,usuario[j].correo)==0)
				permiso++;
				if(strcmp(contra,usuario[j].contra)==0)
				permiso++;
				if(permiso==2)
				break;
			}
			error++;
			}while(permiso!=2);
			error=0;
			printf ("SE HA LOGUEADO CORRECTAMENTE, BIENVENIDO %s\n", usuario[j].nombre);
			printf ("TOQUE UNA TECLA PARA VOLVER AL MENU \n");
			scanf ("%c", &inicio);
			
			system("PAUSE()");
			system("CLS()");
		break;
		
	
		case 3: 
		//CREAMOS VECTOR DE COCHES (REVISAR) 
		pCoches = fopen("coches.txt","r");
		if (pCoches == NULL){ 
		printf("No se encuentra fichero");
		return 0;
		}
		ncoches=0;
		while(fscanf(pCoches, "%s ", coches[ncoches].stock)!= EOF){ //Lee el fichero y lo copia en un vector
				ncoches++;
			
		}
		fclose(pCoches);
		pReservas = fopen("reservas.txt", "r");
			if (pReservas == NULL){ 
			printf("No se encuentra fichero");
			return 0;
			}
			while(fscanf(pReservas, "%s %s", coches[nreservas].reserva, coches[nreservas].comprador)!= EOF){ //Lee el fichero y lo copia en un vector
				nreservas++;
								
			}
								
			printf("ESTE ES NUESTRO CATALOGO, HAY %d COCHES DISPONIBLES\n\n", ncoches-nreservas); 
			printf ("SELECCIONE UNA DE LAS CATEGORIAS: \n");
			printf ("1-Si buscas un viaje de grupo o sois una familia numerosa y siempre os falta espacio tenemos vuestra solucion  \n\n");
			printf ("2-Si eres un fan de los clasicos no dudes en elegir esta opcion \n\n");
			printf ("3-Si lo que te gusta es volar y lo tuyo son los coches deportivos aqui encontraras lo que buscas \n\n");
			printf ("4-Si buscas lo mas barato y comodo te damos las mejores opciones \n\n");
			printf ("5-Si estas a la moda y optas por un coche electrico es aqui donde debes buscar \n\n");
			printf ("6-Si lo que quieres es un coche que no suene para que no se entere nadie de que te vas, esta es tu opcion \n\n");
			printf ("7-Si lo que deseas es oler el ambiente madrileno a través de los nuevos patines electricos con tu familia o grupo de amig@s, ¡adelante! \n\n ");
			scanf("%d", &categoria);

		switch (categoria){
			case 1: system("CLS()");
			printf("Si necesitas espacio y buen ritmo... te ofrecemos: \n");

				printf ("\n");
				printf("OPEL COMBO LIFE \n");
				printf("El Opel Combo Life es una furgoneta industrial adaptada para pasajeros que esta disponible en dos longitudes.\n Tanto en la version corta como en la version larga es posible llevar 7 asientos individuales, \n pero si vamos a utilizar habitualmente todas las plazas es recomendable optar por la carroceria larga ya que los pasajeros viajaran con mucho mas desahogo en la ultima fila, \n aunque esta carroceria rompa un poco las proporciones exteriores del coche.\n");
				
				printf ("\n");
				printf("PEUGEOT RIFTER \n");
				printf("El Peugeot Rifter es una de las mejores versiones de pasajeros de una furgoneta que existen ahora mismo. \n Las ventajas de comprarse una furgoneta radican, sobre todo, en el coste de mantenimiento y la fiabilidad y dureza de estos vehiculos.\n Tres sillas infantiles son pan comido para su asiento trasero dividido en tres bloques independientes, y tiene disponibilidad de hasta 7 plazas reales.\n");
	
				printf ("\n");
				printf("FIAT 500L WAGON \n");
				printf("Tiene a su favor una buena relacion espacio/precio y podemos anadirle interesantes opciones de equipamiento y conectividad que lo convierten en un coche muy razonable para viajes familiares. \n De entre sus motores, la mecanica 0.9 TwinAir de 105 CV probablemente es la estrella por su ajustado consumo y buen rendimiento. \n Para los mas viajeros tambien existen alternativas diesel Multijet de alta eficiencia, pero algo por encima en precios.\n");
	
				printf ("\n");
				printf("RENAULT KANGOO \n");
				printf("La Renault Kangoo es otra de las posibles furgonetas industriales que se han puesto de moda para ser transformadas en monovolumen de hasta 7 plazas para el transporte de pasajeros. \n La Kangoo es un clasico entre los vehiculos comerciales por su imagen simpatica y su durabilidad. \n\n");
				
				printf("Si ya te has decidido, puedes reservar marcando una de las siguientes opciones:\n\n");
				if(permiso!=2) 
					printf("DEBE INICIAR SESION PARA HACER UNA RESERVA\n");
				else{
					printf("PULSA 1 para reservar:OPEL COMBO LIFE\n\n");
					printf("PULSA 2 para reservar:PEUGEOT RIFTER\n\n");
					printf("PULSA 3 para reservar:FIAT 500L WAGON\n\n");
					printf("PULSA 4 para reservar:RENAULT KANGOO\n\n");
					error=0;   
				
					do{
						if(error!=0) {
							printf("Vuelve a seleccionar el coche deseado\n");
						} 
						scanf("%d", &coche);
						system("PAUSE()");
						printf("Ha seleccionado el %s\n\n", coches[coche-1].stock); //SI PONE RESERVADO HAY QUE IMPEDIR LA RESERVA
						switch (coche){
							case 1: 
								printf("El Opel Combo Life es una furgoneta industrial adaptada para pasajeros que esta disponible en dos longitudes.\n Tanto en la version corta como en la version larga es posible llevar 7 asientos individuales, \n pero si vamos a utilizar habitualmente todas las plazas es recomendable optar por la carroceria larga ya que los pasajeros viajaran con mucho mas desahogo en la ultima fila, \n aunque esta carroceria rompa un poco las proporciones exteriores del coche.\n");
								system("PAUSE()");
								break;
							
							case 2: 
								printf("El Peugeot Rifter es una de las mejores versiones de pasajeros de una furgoneta que existen ahora mismo. \n Las ventajas de comprarse una furgoneta radican, sobre todo, en el coste de mantenimiento y la fiabilidad y dureza de estos vehiculos.\n Tres sillas infantiles son pan comido para su asiento trasero dividido en tres bloques independientes, y tiene disponibilidad de hasta 7 plazas reales.\n");
								system("PAUSE()");
								break;
								
							case 3: 
								printf("Tiene a su favor una buena relacion espacio/precio y podemos anadirle interesantes opciones de equipamiento y conectividad que lo convierten en un coche muy razonable para viajes familiares. \n De entre sus motores, la mecanica 0.9 TwinAir de 105 CV probablemente es la estrella por su ajustado consumo y buen rendimiento. \n Para los mas viajeros tambien existen alternativas diesel Multijet de alta eficiencia, pero algo por encima en precios.\n");
								system("PAUSE()");
								break;
								
							case 4: 
								printf("La Renault Kangoo es otra de las posibles furgonetas industriales que se han puesto de moda para ser transformadas en monovolumen de hasta 7 plazas para el transporte de pasajeros. \n La Kangoo es un clasico entre los vehiculos comerciales por su imagen simpatica y su durabilidad. \n\n");
								system("PAUSE()");
								break;
							
							default : 
								printf("NO HA SELECIONADO NINGUNA OPCION VALIDA, POR FAVOR, INTENTELO DE NUEVO"); 
								system("PAUSE()");
								system("CLS()");
						}
						
						printf("Esta seguro de hacer su reserva, si es asi pulse 1, en caso contrario pulse otro numero\n");
						scanf("%d", &aceptar);
						error++;
					
				}while(aceptar!= 1);
				
				
				if (aceptar == 1){
							pCoches = fopen("coches.txt","w");
						if (pCoches == NULL){ 
							printf("No se encuentra fichero");
							return 0;
							}
						for(i=0;i<=ncoches;i++){
						if(i==coche-1){
							pReservas = fopen("reservas.txt", "w");
							if (pReservas == NULL){ 
								printf("No se encuentra fichero");
								return 0;
							}
							strcpy(coches[nreservas].reserva,coches[coche-1].stock); // el coche seleccionado es la ultima reserva que tiene que copiar
							strcpy(coches[nreservas].comprador,usuario[j].correo); // el usuario registrado es el ultimo en copiarse
							for (t=0;t<=nreservas;t++){
								fprintf(pReservas, "%s %s\n", coches[t].reserva, coches[t].comprador );	// TIENE QUE ESCRIBIR LAS RESERVAS en reservas.txt
								}
								fprintf(pCoches, "RESERVADO\n");
							}
							else
								fprintf(pCoches, "%s\n", coches[i].stock);
							}
							fclose(pCoches);
							fclose(pReservas);
					}	
				}
				
				system("PAUSE()");
				system("CLS()");
				
				
			break;

			case 2: system("CLS()");
				printf("Las personas que le gustan los clasicos, ¿para que cambiar?\n");


				printf ("\n");
				printf("CITROEN DYANE 6 \n");
				printf("Aquí podríamos haber puesto un 2CV, pero el problema es que, por un coche objetivamente peor (aunque con mas carisma y simpatia), tendrias que gastar mas del doble.\n El Dyane 6 es un coche que tiene todo lo que posee el 2CV e incluso mas y que puedes conseguir por precios en el entorno de los 3.000 euros,\n casi la mitad de lo que te pedirán por un 2CV en identicas condiciones.\n");
	
				printf ("\n");
				printf("VOLKSWAGEN ESCARABAJO \n");
				printf("El VW Escarabajo es otro coche con un mantenimiento muy sencillo y que puedes conseguir por precios muy asequibles. \n Como se fabrico muchos años y hay infinidad de versiones, puedes hacerte con un 1.200 en buenas condiciones alrededor de los 3.000 euros, aunque mi consejo si estas iniciandote es que busques un 1303, algo mas confortable y con frenos de disco en el eje delantero, ademas de con una instalacion electrica a 12V. \n");
	
				printf ("\n");
				printf("MINI\n");
				printf("El Mini es otro coche con una mecanica muy sencilla y para el que es facilisimo encontrar recambios y accesorios. \n Es muy divertido de utilizar. Si te gustan los rallys de regularidad, es una excelente alternativa ya que su tamano hace que las carreteras por las que se suelen realizar estas pruebas parezcan autovias, lo cual es una ventaja.\n");
	
				printf ("\n");
				printf("SEAT 127 \n");
				printf("Por cifras mucho mas razonables que las que se estan pidiendo por un Panda o un Seat 600 te puedes comprar un Seat 127 que es mucho mas divertido de conducir y mucho mas coche.\n Sus puntos fuertes son su excelente conduccion (te sorprendera lo bien que va, incluso comparado con utilitarios modernos), los costes de mantenimiento y uso (gasta poco) y que puedes hacer tu mismo casi todo el mantenimiento.\n");
				
				printf("Si ya te has decidido, puedes reservar marcando una de las siguientes opciones:\n\n");
				if(permiso!=2) printf("DEBE INICIAR SESION PARA HACER UNA RESERVA\n");
				else{
				printf("PULSA 1 para reservar: CITROEN DYANE 6\n\n");
				printf("PULSA 2 para reservar: VOLKSWAGEN ESCARABAJO\n\n");
				printf("PULSA 3 para reservar: MINI\n\n");
				printf("PULSA 4 para reservar: SEAT 127\n\n");
				error=0;
				do{
					if(error!=0) {
						printf("Vuelve a seleccionar el coche deseado\n");
					}
					scanf("%d", &coche);
					printf("Ha seleccionado el %s\n\n", coches[coche-1].stock); 
					switch (coche){
						case 1: 
							printf("Aquí podríamos haber puesto un 2CV, pero el problema es que, por un coche objetivamente peor (aunque con mas carisma y simpatia), tendrias que gastar mas del doble.\n El Dyane 6 es un coche que tiene todo lo que posee el 2CV e incluso mas y que puedes conseguir por precios en el entorno de los 3.000 euros,\n casi la mitad de lo que te pedirán por un 2CV en identicas condiciones.\n");
							system("PAUSE()");
							break;
							
						case 2:
							printf("El VW Escarabajo es otro coche con un mantenimiento muy sencillo y que puedes conseguir por precios muy asequibles. \n Como se fabrico muchos años y hay infinidad de versiones, puedes hacerte con un 1.200 en buenas condiciones alrededor de los 3.000 euros, aunque mi consejo si estas iniciandote es que busques un 1303, algo mas confortable y con frenos de disco en el eje delantero, ademas de con una instalacion electrica a 12V.\n");
							system("PAUSE()");
							break;
							
						case 3: 
							printf("El Mini es otro coche con una mecanica muy sencilla y para el que es facilisimo encontrar recambios y accesorios. \n Es muy divertido de utilizar. Si te gustan los rallys de regularidad, es una excelente alternativa ya que su tamano hace que las carreteras por las que se suelen realizar estas pruebas parezcan autovias, lo cual es una ventaja.\n");
							system("PAUSE()");
							break;
							
						case 4: 
							printf("Por cifras mucho mas razonables que las que se estan pidiendo por un Panda o un Seat 600 te puedes comprar un Seat 127 que es mucho mas divertido de conducir y mucho mas coche.\n Sus puntos fuertes son su excelente conduccion (te sorprendera lo bien que va, incluso comparado con utilitarios modernos), los costes de mantenimiento y uso (gasta poco) y que puedes hacer tu mismo casi todo el mantenimiento. \n\n");
							system("PAUSE()");
							break;
						default : 
								printf("NO HA SELECIONADO NINGUNA OPCION VALIDA, POR FAVOR, INTENTELO DE NUEVO"); 
								system("PAUSE()");
								system("CLS()");
					}
					
					printf("Esta seguro de hacer su reserva, si es asi pulse 1, en caso contrario pulse otro numero\n");
					scanf("%d", &aceptar);
					error++;
					
					
				}while(aceptar!= 1);
				if (aceptar == 1){
							pCoches = fopen("coches.txt","w");
						if (pCoches == NULL){ 
							printf("No se encuentra fichero");
							return 0;
							}
						for(i=0;i<=ncoches;i++){
						if(i==coche-1){
								pReservas = fopen("reservas.txt", "w");
								if (pReservas == NULL){ 
									printf("No se encuentra fichero");
									return 0;
									}
								strcpy(coches[nreservas].reserva,coches[coche-1].stock); // el coche seleccionado es la ultima reserva que tiene que copiar
								strcpy(coches[nreservas].comprador,usuario[j].correo); // el usuario registrado es el ultimo en copiarse
							for (t=0;t<=nreservas;t++){
							fprintf(pReservas, "%s %s\n", coches[t].reserva, coches[t].comprador );	// TIENE QUE ESCRIBIR LAS RESERVAS en reservas.txt
							}
						fprintf(pCoches, "RESERVADO\n");
						}
						else
						fprintf(pCoches, "%s\n", coches[i].stock);
						}
						fclose(pCoches);
						fclose(pReservas);
					}	
				}
				
				system("PAUSE()");
				system("CLS()");
				
			break;


	    	
			break;

			case 3: system("CLS()");
				printf("Elige a que velocidad deseas volar... \n");

				printf ("\n");
				printf("ABARTH 124 SPIDER \n");
				printf("El Abarth 124 Spider es un modelo que comprarte numerosos elementos con el Mazda MX-5, aunque su enfoque resulta claramente mas deportivo: \n equipa una suspension mas dura, amortiguadores Bilstein, muelles y estabilizadoras de tarado mas exigente y un diferencial autoblocante.\n");
	
				printf ("\n");
				printf("ALPINE A110 \n");
				printf("Al volante se disfruta al maximo de una conduccion racing, gracias a la ligereza de su chasis de carbono, la resistencia de sus frenos Brembo, \n y el correcto reparto de pesos de su motor central trasero de gasolina 1.8 turbo de 252 CV y cambio automatico de doble embrague. \n");
	
				printf ("\n");
				printf("BMW SERIE 8 COUPE \n");
				printf("La llamativa carroceria cuenta con un practico porton trasero que da acceso a un maletero de 420 litros de capacidad, ampliable plegando los respaldos de los dos asientos traseros. \n En cuanto a prestaciones, la velocidad maxima esta autolimitada a 250 km/h, pero la aceleracion de 0 a 100 km/h es uno de sus mejores argumentos: 4,9 segundos en el diesel y solo 3,7 segundos en el gasolina. \n");
				
				printf("Si ya te has decidido, puedes reservar marcando una de las siguientes opciones:\n\n");
				if(permiso!=2) printf("DEBE INICIAR SESION PARA HACER UNA RESERVA\n");
				else{
				printf("PULSA 1 para reservar:ABARTH 124 SPIDER\n\n");
				printf("PULSA 2 para reservar: ALPINE A110\n\n");
				printf("PULSA 3 para reservar: BMW SERIE 8 COUPE \n\n");
				error=0;
				do{
					if(error!=0) {
						printf("Vuelve a seleccionar el coche deseado\n");
					}
					scanf("%d", &coche);
					printf("Ha seleccionado el %s\n\n", coches[coche-1].stock); //SI PONE RESERVADO HAY QUE IMPEDIR LA RESERVA
					switch (coche){
						case 1: 
							printf("El Abarth 124 Spider es un modelo que comprarte numerosos elementos con el Mazda MX-5, aunque su enfoque resulta claramente mas deportivo: \n equipa una suspension mas dura, amortiguadores Bilstein, muelles y estabilizadoras de tarado mas exigente y un diferencial autoblocante.\n");
							system("PAUSE()");
							break;
							
						case 2:
							printf("Al volante se disfruta al maximo de una conduccion racing, gracias a la ligereza de su chasis de carbono, la resistencia de sus frenos Brembo, \n y el correcto reparto de pesos de su motor central trasero de gasolina 1.8 turbo de 252 CV y cambio automatico de doble embrague.\n");
							system("PAUSE()");
							break;
							
						case 3: 
							printf("La llamativa carroceria cuenta con un practico porton trasero que da acceso a un maletero de 420 litros de capacidad, ampliable plegando los respaldos de los dos asientos traseros. \n En cuanto a prestaciones, la velocidad maxima esta autolimitada a 250 km/h, pero la aceleracion de 0 a 100 km/h es uno de sus mejores argumentos: 4,9 segundos en el diesel y solo 3,7 segundos en el gasolina.\n");
							system("PAUSE()");
							break;
						
						default : 
								printf("NO HA SELECIONADO NINGUNA OPCION VALIDA, POR FAVOR, INTENTELO DE NUEVO"); 
								system("PAUSE()");
								system("CLS()");
					}
					
					printf("Esta seguro de hacer su reserva, si es asi pulse 1, en caso contrario pulse otro numero\n");
					scanf("%d", &aceptar);
					error++;
					
					
				}while(aceptar!= 1);
				if (aceptar == 1){
							pCoches = fopen("coches.txt","w");
						if (pCoches == NULL){ 
							printf("No se encuentra fichero");
							return 0;
							}
						for(i=0;i<=ncoches;i++){
						if(i==coche-1){
								pReservas = fopen("reservas.txt", "w");
								if (pReservas == NULL){ 
									printf("No se encuentra fichero");
									return 0;
									}
								strcpy(coches[nreservas].reserva,coches[coche-1].stock); // el coche seleccionado es la ultima reserva que tiene que copiar
								strcpy(coches[nreservas].comprador,usuario[j].correo); // el usuario registrado es el ultimo en copiarse
							for (t=0;t<=nreservas;t++){
							fprintf(pReservas, "%s %s\n", coches[t].reserva, coches[t].comprador );	// TIENE QUE ESCRIBIR LAS RESERVAS en reservas.txt
							}
						fprintf(pCoches, "RESERVADO\n");
						}
						else
						fprintf(pCoches, "%s\n", coches[i].stock);
						}
						fclose(pCoches);
						fclose(pReservas);
					}	
				}
				
				
				
				system("PAUSE()");
				system("CLS()");

			
			break;

			case 4: system("CLS()");
				printf("Para las personas que se conforman con un volante y cuatro ruedas, ¡tenemos lo que buscas! \n");

				printf("\n");
				printf ("NISSAN MICRA 1.0 \n");
				printf("Es uno de nuestros coches mas alquilados, facil de matener y fiable. Tambien duro como piedra y perfecto para ciudad. \n Es un cinco plazas con traccion delantera y motor delantero transversal de cuatro cilindros en linea.\n");
	
				printf("\n");
				printf("SEAT IBIZA \n");
				printf("El Seat Ibiza actual dispone de 5 puertas, 3 cilindros y consigue llegar a los 100 km/h en 14,7 segundos. \n El aspecto mas destacado del Seat Ibiza sobre sus competidores es su mayor capacidad del maletero. \n");
	
				printf("\n");
				printf("RENAULT MEGANE \n");
				printf("El Renault Megane tiene seis o siete marchas y un consumo muy equilibrado. Es un coche muy dinamico y con diseno deportivo. \n Ademas del volumen de carga de su maletero, el reposabrazos central tiene un hueco con capacidad de 3 litros y una amplia guantera con un volumen de 7,4 litros. \n");
	
				printf("\n");
				printf("KIA PICANTO \n");
				printf("El Kia Picanto es un urbano de cinco puertas. Esta disponible con un motor de gasolina de un litro y 66 CV, y un equilibrado 1.2 CVVT con 85 CV\n");
				
				printf("Si ya te has decidido, puedes reservar marcando una de las siguientes opciones:\n\n");
				if(permiso!=2) printf("DEBE INICIAR SESION PARA HACER UNA RESERVA\n");
				else{
				printf("PULSA 1 para reservar: NISSAN MICRA 1.0 \n\n");
				printf("PULSA 2 para reservar: SEAT IBIZA\n\n");
				printf("PULSA 3 para reservar: RENAULT MEGANE\n\n");
				printf("PULSA 4 para reservar: KIA PICANTO\n\n");
				error=0;
				do{
					if(error!=0) {
						printf("Vuelve a seleccionar el coche deseado\n");
					}
					scanf("%d", &coche);
					printf("Ha seleccionado el %s\n\n", coches[coche-1].stock); //SI PONE RESERVADO HAY QUE IMPEDIR LA RESERVA
					switch (coche){
						case 1: 
							printf("Es uno de nuestros coches mas alquilados, facil de matener y fiable. Tambien duro como piedra y perfecto para ciudad. \n Es un cinco plazas con traccion delantera y motor delantero transversal de cuatro cilindros en linea.\n");
							system("PAUSE()");
							break;
							
						case 2:
							printf("El Seat Ibiza actual dispone de 5 puertas, 3 cilindros y consigue llegar a los 100 km/h en 14,7 segundos. \n El aspecto mas destacado del Seat Ibiza sobre sus competidores es su mayor capacidad del maletero.\n");
							system("PAUSE()");
							break;
							
						case 3: 
							printf("El Renault Megane tiene seis o siete marchas y un consumo muy equilibrado. Es un coche muy dinamico y con diseno deportivo. \n Ademas del volumen de carga de su maletero, el reposabrazos central tiene un hueco con capacidad de 3 litros y una amplia guantera con un volumen de 7,4 litros. \n");
							system("PAUSE()");
							break;
							
						case 4: 
							printf("El Kia Picanto es un urbano de cinco puertas. Esta disponible con un motor de gasolina de un litro y 66 CV, y un equilibrado 1.2 CVVT con 85 CV \n\n");
							system("PAUSE()");
							break;
						default : 
								printf("NO HA SELECIONADO NINGUNA OPCION VALIDA, POR FAVOR, INTENTELO DE NUEVO"); 
								system("PAUSE()");
								system("CLS()");
					}
					
					printf("Esta seguro de hacer su reserva, si es asi pulse 1, en caso contrario pulse otro numero\n");
					scanf("%d", &aceptar);
					error++;
					
					
				}while(aceptar!= 1);
				if (aceptar == 1){
							pCoches = fopen("coches.txt","w");
						if (pCoches == NULL){ 
							printf("No se encuentra fichero");
							return 0;
							}
						for(i=0;i<=ncoches;i++){
						if(i==coche-1){
								pReservas = fopen("reservas.txt", "w");
								if (pReservas == NULL){ 
									printf("No se encuentra fichero");
									return 0;
									}
								strcpy(coches[nreservas].reserva,coches[coche-1].stock); // el coche seleccionado es la ultima reserva que tiene que copiar
								strcpy(coches[nreservas].comprador,usuario[j].correo); // el usuario registrado es el ultimo en copiarse
							for (t=0;t<=nreservas;t++){
							fprintf(pReservas, "%s %s\n", coches[t].reserva, coches[t].comprador );	// TIENE QUE ESCRIBIR LAS RESERVAS en reservas.txt
							}
						fprintf(pCoches, "RESERVADO\n");
						}
						else
						fprintf(pCoches, "%s\n", coches[i].stock);
						}
						fclose(pCoches);
						fclose(pReservas);
					}	
				}
	
	    		system("PAUSE()");
				system("CLS()");
	    	
	    	
	    	break;
	    	
	    	
			case 5: system("CLS()");
				printf("Ser cero, ahora, suma mas que nunca. Con la etiqueta de 0 emisiones de la DGT, podras conducir por el centro de la ciudad siempre que quieras, ademas de disfrutar de muchos otros beneficios, descuentos y ayudas dependiendo de la comunidad autonoma en la que te encuentres.\n");
			
				printf("\n");
				printf("PEUGEOT E-208 \n");
				printf("El nuevo coche urbano PEUGEOT e-208 ofrece una vivacidad y un placer de conduccion estimulante gracias a su motorizacion 100% electrica y da claramente acceso a una nueva movilidad. \n Carga tu e-208 mas rapido y con total seguridad gracias a nuestra oferta en punto de carga: la carga completa puede reducirse a siete horas y media en un punto de carga de 7,4 kW.\n");
				
				printf("\n");
				printf("CITROEN E-BERLINGO MULTISPACE \n");
				printf("El Nuevo E-Berlingo Multispace ofrece toda la polivalencia del Berlingo en el dia a dia, con las ventajas de los coches electricos. \n El Nuevo E-Berlingo Multispace incorpora un motor electrico de altas prestaciones de tipo sincrono con imanes permanentes de 49 kW (67 CV).\n");
				
				printf("\n");
				printf("BMW i3 \n ");
				printf("Subete a este vehiculo de 7 plazas y descubre el futuro muy de cerca. \n El BMW i3 esta lleno de tecnologias innovadoras que le permiten dominar la vida diaria.  \n Te conecta con el mundo exterior, te informa, te ayuda a organizarte y te lleva hasta tu destino. \n Siempre listo para la carretera con 6 marchas o automatico y ademas, con un maletero que se puede convertir en dos plazas mas.\n");
				
				printf("\n");
				printf("VOLKSWAGEN ID.3 \n");
				printf("Directo, potente y sin cambios. \n El ID.3 emociona con su traccion trasera y la potencia de su aceleracion. Vive la emocion de la movilidad electrica desde la salida.\n");
				
				printf("\n");
				printf("BMW X3 xDrive30e");
				printf("El BMW X3 xDrive30e acelera en 6,5 segundos de 0 a 100 km/h y alcanza los 135 km/h en modo electrico (210 km/h con el motor gasolina). \n La energia electrica se acumula en una bateria de iones de litio de 12 kWh, capacidad suficiente para recorrer entre 41 y 46 km en modo 100PORCIEN electrico.\n");
				
				printf("Si ya te has decidido, puedes reservar marcando una de las siguientes opciones:\n\n");
				if(permiso!=2) printf("DEBE INICIAR SESION PARA HACER UNA RESERVA\n");
				else{
				printf("PULSA 1 para reservar: PEUGEOT E-208 \n\n");
				printf("PULSA 2 para reservar: CITROEN E-BERLINGO MULTISPACE\n\n");
				printf("PULSA 3 para reservar: BMW i3\n\n");
				printf("PULSA 4 para reservar: VOLKSWAGEN ID.3\n\n");
				printf("PULSA 5 para reservar: BMW X3 xDrive30e\n\n");
				error=0;
				do{
					if(error!=0) {
						printf("Vuelve a seleccionar el coche deseado\n");
					}
					scanf("%d", &coche);
					printf("Ha seleccionado el %s\n\n", coches[coche-1].stock); //SI PONE RESERVADO HAY QUE IMPEDIR LA RESERVA
					switch (coche){
						case 1: 
							printf("El nuevo coche urbano PEUGEOT e-208 ofrece una vivacidad y un placer de conduccion estimulante gracias a su motorizacion 100% electrica y da claramente acceso a una nueva movilidad. \n Carga tu e-208 mas rapido y con total seguridad gracias a nuestra oferta en punto de carga: la carga completa puede reducirse a siete horas y media en un punto de carga de 7,4 kW.\n");
							system("PAUSE()");
							break;
							
						case 2:
							printf("El Nuevo E-Berlingo Multispace ofrece toda la polivalencia del Berlingo en el dia a dia, con las ventajas de los coches electricos. \n El Nuevo E-Berlingo Multispace incorpora un motor electrico de altas prestaciones de tipo sincrono con imanes permanentes de 49 kW (67 CV).\n");
							system("PAUSE()");
							break;
							
						case 3: 
							printf("Subete a este vehiculo de 7 plazas y descubre el futuro muy de cerca. \n El BMW i3 esta lleno de tecnologias innovadoras que le permiten dominar la vida diaria.  \n Te conecta con el mundo exterior, te informa, te ayuda a organizarte y te lleva hasta tu destino. \n Siempre listo para la carretera con 6 marchas o automatico y ademas, con un maletero que se puede convertir en dos plazas mas. \n");
							system("PAUSE()");
							break;
							
						case 4: 
							printf("Directo, potente y sin cambios. \n El ID.3 emociona con su traccion trasera y la potencia de su aceleracion. Vive la emocion de la movilidad electrica desde la salida. \n\n");
							system("PAUSE()");
							break;
							
						case 4: 
							printf("El BMW X3 xDrive30e acelera en 6,5 segundos de 0 a 100 km/h y alcanza los 135 km/h en modo electrico (210 km/h con el motor gasolina). \n La energia electrica se acumula en una bateria de iones de litio de 12 kWh, capacidad suficiente para recorrer entre 41 y 46 km en modo 100PORCIEN electrico. \n\n");
							system("PAUSE()");
							break;
						
						default : 
								printf("NO HA SELECIONADO NINGUNA OPCION VALIDA, POR FAVOR, INTENTELO DE NUEVO"); 
								system("PAUSE()");
								system("CLS()");
					}
					
					printf("Esta seguro de hacer su reserva, si es asi pulse 1, en caso contrario pulse otro numero\n");
					scanf("%d", &aceptar);
					error++;
					
					
				}while(aceptar!= 1);
				if (aceptar == 1){
							pCoches = fopen("coches.txt","w");
						if (pCoches == NULL){ 
							printf("No se encuentra fichero");
							return 0;
							}
						for(i=0;i<=ncoches;i++){
						if(i==coche-1){
								pReservas = fopen("reservas.txt", "w");
								if (pReservas == NULL){ 
									printf("No se encuentra fichero");
									return 0;
									}
								strcpy(coches[nreservas].reserva,coches[coche-1].stock); // el coche seleccionado es la ultima reserva que tiene que copiar
								strcpy(coches[nreservas].comprador,usuario[j].correo); // el usuario registrado es el ultimo en copiarse
							for (t=0;t<=nreservas;t++){
							fprintf(pReservas, "%s %s\n", coches[t].reserva, coches[t].comprador );	// TIENE QUE ESCRIBIR LAS RESERVAS en reservas.txt
							}
						fprintf(pCoches, "RESERVADO\n");
						}
						else
						fprintf(pCoches, "%s\n", coches[i].stock);
						}
						fclose(pCoches);
						fclose(pReservas);
					}	
				}
	
	    		system("PAUSE()");
				system("CLS()");
	    	
	    	
				system("PAUSE()");
				system("CLS()");
	    	
	    	
	    	
	    	break;
			
			case 6:system("CLS()");
			 printf("Tan sencillo como cargar tu telefono movil...\n");
			
				printf("\n");
				printf("FORD MONDEO HYBRID \n ");
				printf("El Mondeo es un modelo brillante desde el punto de vista dinamico y por habitabilidad en las plazas traseras, aunque en esta variante híbrida el maletero se reduce de 550 a 383 litros en la variante de cuatro puertas. Su propulsor gasolina-electrico de 187 CV, aparejado a una caja de cambios automatica, de seis velocidades, combina unos consumos muy ajustados.\n");
				
				printf("\n");
				printf("HYUNDAI IONIQ \n ");
				printf("El Hyundai y las versiones hibridas combinan un motor electrico con otro 1.6 de gasolina, para entregar un total de 141 CV.\n");
				
				printf("\n");
				printf("HONDA CR-V HYBRID \n ");
				printf("El Honda recurre a la tecnologia i-MMD, siglas de Intelligent Multi-Mode Drive-, que consta de cuatro partes esenciales:\n un motor de gasolina de 2.0 litros, un propulsor electrico, un generador; y una batería de iones de litio, con una capacidad aproximada de 1 kWh. \n Este sistema consta con tres modos de funcionamiento: 100 POR CIEN electrico, hibrido y solo con el motor de combustion.\n");
				
				printf("\n");
				printf("TOYOTA CAMRY \n");
				printf("Este Toyota comparte plataforma modular TNGA-K con el Lexus ES, mientras que el motor hibrido de 218 CV es idéntico al que monta el Toyota RAV4 hybrid. \n Este propulsor se asocia a un cambio automatico de tipo CVT y a la traccion delantera y, gracias a su condicion hibrida, permite al Camry homologar un consumo medio de 5,3 litros/100 km segun el ciclo WLTP. \n");
				
				printf("\n");
				printf("TOYOTA CH-R \n");
				printf("El Toyota C-HR se ha convertido en todo un Exito de ventas desde su lanzamiento.  \n ADEMAS, mantiene la version 1.8 Hybrid de 122 CV y anade la mas potente 2.0 Hybrid de 184 CV. \n ");
				
				system("PAUSE()");
				system("CLS()");
	    	break;
	    	
	    	case 7: system("CLS()");
			printf("¡Sobre dos ruedas y desarollando el olfato! \n ");
	    	
	    		printf("\n");
	    		printf("M MegaWheels S5");
	    		printf("Este es el patinete electrico tope de gama de la marca Megawheels. \n  Tiene una autonomia bastante correcta: 18-20km, con 2-3 horas de carga. \n Para esto incorpora un sistema de recuperacion de ahorro de energia: cuando conduces el patinete, al accionar los frenos y al soltar el acelerador, activan este sistema. \n A traves de este sistema la energia cinetica producida se convierte en energía electrica que se almacena de nuevo en la bateria. \n Se pliega en menos de 5 segundos y se lleva muy fácilmente en la mano (12,5 kg) gracias a un aluminio muy resistente.");
	    		
	    		printf("\n");
	    		printf("IWatRoad R9");
	    		printf("¡Para todos, incluso hasta los mas pequeños! Incorpora dos programas que limitan la velocidad máxima hasta 15 y 25 km/h. \n De esta forma, se lo puedes dejar a tu hijo sin problema o regular la velocidad si vas por una avenida peatonal. ");
	    		
	    		
	    		printf("\n");
	    		printf("Xiaomi Mi Scooter M365");
	    		printf("Este es el patinete más equilibrado de nuestra seleccion.\n Podras recorrer hasta 30 km, estando siempre al tanto de las cuatro luces de notificacion LED en el panel que te indican la bateria restante. \n Ademas de una bateria de gran capacidad, incorpora un sistema de frenada regenerativa, por el cual la bateria se va recargando segun circulas con tu patinete.");
	    		
	    		
	    		printf("\n");
	    		printf("Cecotec Outsider E-volution Phoenix 8.5");
	    		printf("Este modelo te interesara si mides mas de 1,85m, ya que su mastil es mas alto haciendo que la conduccion sea mucho mas natural y comoda.\n En cuanto a la autonomia, tiene 3 modos de conduccion acomodado a todo tipo de trayectos. \n");
	    		
	    		
	    		printf("\n");
	    		printf("Xiaomi Mi Electric Scooter Pro");
	    		printf("Olvidate de mirar cuanta bateria te queda. El fabricante asegura que en condiciones optimas se pueden alcanzar los 45 km de autonomia.\n Ademas cuenta con: Frenos de disco ABS antiderrapaje \n Freno delantero regenerativo\n Autonomia.");
	    	
	    		system("PAUSE()");
				system("CLS()");
				
			break;
		}

		break;
		case 4: 
			if(permiso==2){
				printf("Hay que trabajar en ello\n");
			}
			else{
			printf("DEBES INICIAR SESION PARA ENTRAR EN  ESTA CATEGORIA\n");	
			}
			
			system("PAUSE()");
			system("CLS()");
		
		break;

		case 5:
			printf("Somos una empresa especializada en el alquiler de automoviles a nivel nacional\n Nos preocupamos de proporcionar a nuestros clientes el mejor precio y la mejor opcion de alquiler para de su viaje. \n");
			system("PAUSE()");
			system("CLS()");
				
		break;
		
		case 6:
			printf("Salir del menu \n Su sesion se cerrara automaticamente \n");
			system("PAUSE()");
			system("CLS()");
		break;	

		default : 
			printf("NO HA SELECCIONADO NINGUNA OPCION VALIDA, POR FAVOR, INTENTELO DE NUEVO"); 
			system("PAUSE()");
			system("CLS()");
		} 
	} while (opcion!=6);
}
