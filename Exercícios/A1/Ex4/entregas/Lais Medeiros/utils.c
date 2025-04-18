#include "utils.h"

void listar_usuarios(const Usuario *usuarios, int num_usuarios) {
    printf("=== Lista de Usuários ===\n");
    for (int i = 0; i < num_usuarios; i++) {
        printf("ID: %d | Nome: %s | Saldo: R$ %.2f | Carros: %d\n",
               usuarios[i].id, usuarios[i].nome,
               usuarios[i].saldo, usuarios[i].num_carros);
    }
    printf("=========================\n");
}

void listar_carros(const Usuario *usuarios, int num_usuarios) {
    printf("=== Histórico de Carros ===\n");
    for (int i = 0; i < num_usuarios; i++) {
        printf("Usuário %s (ID: %d)\n", usuarios[i].nome, usuarios[i].id);
        for (int j = 0; j < usuarios[i].num_carros; j++) {
            Carro c = usuarios[i].historico_carros[j];
            printf("  Placa: %s | Horas: %d | Valor: R$%.2f | Aprovado: %s | Ativo: %s\n",
                   c.placa, c.horas, c.valor_total,
                   c.aprovado ? "Sim" : "Não",
                   c.ativo ? "Sim" : "Não");
        }
    }
}

Usuario *buscar_usuario_por_id(Usuario *usuarios, int num_usuarios, int id) {
    for (int i = 0; i < num_usuarios; i++) {
        if (usuarios[i].id == id)
            return &usuarios[i];
    }
    return NULL;
}

void adicionar_carro_historico(Usuario *usuario, Carro novo) {
    usuario->historico_carros = realocar_memoria_carro(usuario->historico_carros, usuario->num_carros + 1);
    usuario->historico_carros[usuario->num_carros] = novo;
    usuario->num_carros++;
}

Usuario *realocar_memoria_usuario(Usuario *usuarios, int novo_tamanho) {
    return realloc(usuarios, novo_tamanho * sizeof(Usuario));
    return NULL;
}

Carro *realocar_memoria_carro(Carro *carros, int novo_tamanho) {
    return realloc(carros, novo_tamanho * sizeof(Carro));
    return NULL;
}

void calcular_valor_total(Carro *carro) {
    carro->valor_total = carro->horas * TAXA_POR_HORA;
}

void aprovar_reprovar_carro(Usuario *usuario, Carro *carro) {
    calcular_valor_total(carro);

    if (carro->valor_total > usuario->saldo) {
        carro->aprovado = 0;
        carro->ativo = 0;
    } else {
        carro->aprovado = 1;
        carro->ativo = 1;
        usuario->saldo -= carro->valor_total;
}

int num_usuarios;

void solicitar_nova_entrada(Usuario *usuarios, int num_usuarios); {
    void solicitar_nova_entrada(Usuario *usuarios, int num_usuarios); {
        int id;
        printf("Digite o ID do usuário: ");
        scanf("%d", &id);
    
        Usuario *usuario = buscar_usuario_por_id(usuario, num_usuarios, id);
        if (usuario == NULL) {
            printf("Usuário não encontrado!\n");
            return;
        }
    
        if (usuario->num_carros > 0) {
            Carro ultimo = usuario->historico_carros[usuario->num_carros - 1];
            if (ultimo.ativo && ultimo.horas < LIMITE_HORAS_ATIVAS) {
                printf("Usuário já possui carro ativo no estacionamento!\n");
                return;
            }
        }
    
        char placa[MAX_PLACA];
        int horas;

        printf("Placa do carro: ");
        scanf("%s", placa);

        printf("Horas de permanência: ");
        scanf("%d", &horas);

        Carro novo = {usuario->id, "", horas, 0.0, 0, 0};
        strncpy(novo.placa, placa, MAX_PLACA);

    
        calcular_valor_total(&novo);
        aprovar_reprovar_carro(usuario, &novo);
        adicionar_carro_historico(usuario, novo);
    
        if (novo.aprovado)
            printf("Entrada aprovada! Valor debitado: R$ %.2f\n", novo.valor_total);
        else
            printf("Entrada reprovada por saldo insuficiente.\n");
    }
}