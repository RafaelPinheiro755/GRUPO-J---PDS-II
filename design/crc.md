# Cartões CRC

## Usuario

### Responsabilidades
- Armazenar dados de perfil (nome, e-mail, foto)
- Manter a lista de grupos dos quais participa
- Manter a lista de convites recebidos
- Entrar em um grupo
- Sair de um grupo

### Colaboradores
- Grupo
- Membresia

---

## Grupo

### Responsabilidades
- Armazenar nome, descrição e tipo (público/privado)
- Manter a lista de membros
- Manter a lista de posts do grupo
- Adicionar um membro
- Gerar um relatório de atividade (total de posts, membro mais ativo)

### Colaboradores
- Usuario
- Post
- Membresia

---

## Post

### Responsabilidades
- Armazenar autor, grupo e texto (até 280 caracteres)
- Armazenar a data e hora de criação
- Manter a lista de curtidas
- Manter a lista de comentários
- Adicionar uma curtida

### Colaboradores
- Usuario
- Grupo
- Comentario

---

## Comentario

### Responsabilidades
- Armazenar o autor do comentário
- Armazenar o texto do comentário
- Armazenar a data e hora do comentário
- Validar o tamanho máximo do texto

### Colaboradores
- Usuario
- Post

---

## Feed

### Responsabilidades
- Reunir os posts de todos os grupos de um usuário
- Ordenar os posts por data (mais recente primeiro)
- Filtrar posts por grupo específico
- Exibir a lista de posts formatada

### Colaboradores
- Usuario
- Grupo
- Post

---

## Membresia

### Responsabilidades
- Armazenar qual usuário pertence a qual grupo
- Armazenar o papel do usuário no grupo (membro ou administrador)
- Armazenar a data de entrada no grupo
- Verificar se um usuário tem permissão de administrador

### Colaboradores
- Usuario
- Grupo
