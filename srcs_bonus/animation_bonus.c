#include "../include/so_long_bonus.h"

int	ft_anim_collectable(t_game_instance *game_init)
{
    // verifica se a animação ja passou por todas as 3 imagens
    if (game_init->game_data.anim_collectible >= 3)
        game_init->game_data.anim_collectible = 0;
    
    // atualiza a imagem do coletavel
    mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.collectible);
    if (game_init->game_data.anim_collectible == 0)
        game_init->game_objs.collectible = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Collectibles/star_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
    else if (game_init->game_data.anim_collectible == 1)
        game_init->game_objs.collectible = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Collectibles/star_01.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
    else if (game_init->game_data.anim_collectible == 2)
        game_init->game_objs.collectible = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Collectibles/star_02.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
    
    // atualiza o estado da animação
    game_init->game_data.anim_collectible++;
    // redesenha o mapa com a nova imagem do coletavel
    ft_map_draw(game_init);
    return (0);
}
