#include <stdio.h> // se for fazer modularizado, passar o conn e retornar o PGconn // 
#include <stdlib.h>
#include <libpq-fe.h>

int main() {
    // String de conexão — ajuste os dados conforme seu banco
    const char *conninfo = "host=localhost port=5432 dbname=Estoque user=postgres password=123456";

    // Conecta ao banco
    PGconn *conn = PQconnectdb(conninfo);

    // Verifica se a conexão deu certo
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erro de conexão: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    printf("Conectado ao banco com sucesso!\n");
	
    // Libera os resultados e encerra
    PQfinish(conn);
    return 0;
}	