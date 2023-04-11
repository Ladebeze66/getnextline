/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:51:15 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/04/05 16:52:50 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)/*Cette fonction prend deux chaines en parametre et les concatene elle libere ensuite la memoire allouee pour la premiere chaine et retourne la nouelle chaine concatenee*/
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}
/*efface la ligne trouvee*/
char	*ft_next(char *buffer)/*Cette fonction prend une chaîne de caractères en paramètre (le buffer contenant les caractères lus) et cherche la position du premier caractère de fin de ligne (\n). Si le caractère de fin de ligne n'est pas trouvé, elle libère la mémoire allouée pour le buffer et retourne NULL. Sinon, elle alloue de la mémoire pour une nouvelle chaîne de caractères contenant tout ce qui suit le caractère de fin de ligne, copie cette partie de la chaîne de caractères dans la nouvelle chaîne et libère la mémoire allouée pour le buffer.*/
{
	int		i;
	int		j;
	char	*line;

	i = 0;/*cherche la longueur de la premiere ligne*/
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}/*alloue la memmoire pour les lignes suivantes en soustrayant la taille de la premiere ligne*/
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));/*calloc va nous permettre d'allouer la memoire necessaire et de l'initialiser a zero*/
	i++;
	j = 0;
	while (buffer[i])/*on copie dans line le texte restant a partir de i*/
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)/*Cette fonction prend une chaîne de caractères en paramètre (le buffer contenant les caractères lus) et cherche la position du premier caractère de fin de ligne (\n). Si la chaîne est vide ou ne contient pas de caractère de fin de ligne, elle retourne NULL. Sinon, elle alloue de la mémoire pour une nouvelle chaîne de caractères contenant tout ce qui précède le caractère de fin de ligne, copie cette partie de la chaîne de caractères dans la nouvelle chaîne et ajoute le caractère de fin de ligne s'il est présent.*/
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')/*on compte la ligne*/
		i++;/*allocation de la memoire pour la ligne avec le retour a la ligne et le \0 de fin de chaine*/
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];/*on copie buffer dans line jusqu'a \n*/
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';/*si \n ou \0 on rajoute \n et on incremente i*/
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)/*si res n'existe pas malloc*/
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));/*n alloue de la mémoire pour le buffer qui va contenir les données lues*/
	byte_read = 1;/*initialisé à 1 pour que la boucle while commence à s'exécuter au moins une fois*/
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);/*On lit les données depuis le fichier, en utilisant la fonction read()*/
		if (byte_read == -1)/*si la lecture echoue on libere la memoire*/
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';/*on ajoute un caractere nul a la fin du buffer*/
		res = ft_free(res, buffer);/*on concatene le resultat existant avec le buffer*/
		if (ft_strchr(buffer, '\n'))/*si on atteint un caractere de fin de chaine on arrete la lecture*/
			break ;
	}
	free(buffer);/*on libere la memoire pour buffer et on renvoie le resultat*/
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;/*la variable buffer est ddeclarer en statiaue pour conserver les donnees entre les apels de fonction*/
	char		*line;/*stocke la ligne a renvoyer*/

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)/*gestion des erreurs on verifie si fd est valide si read renvoie -1*/
		return (NULL);
	buffer = read_file(fd, buffer);/*reqd_file est appelle pour lire le fichier et stocke le contenu dans buffer*/
	if (!buffer)/*si read_file echoue renvoie NULL*/
		return (NULL);
	line = ft_line(buffer);/*extraction de lq premiere ligne et stocke dans line*/
	buffer = ft_next(buffer);/*appel ft_next pour mettre a jour buffer et supprimer la ligne extraite*/
	return (line);/*renvoie line et NULL une fois toutes les lignes lues*/
}
