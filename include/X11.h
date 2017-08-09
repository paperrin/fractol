/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X11.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:24:03 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/09 16:48:12 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X11_H
# define X11_H

# define X11_KEY_PRESS 2
# define X11_KEY_RELEASE 3
# define X11_BUTTON_PRESS 4
# define X11_BUTTON_RELEASE 5
# define X11_MOTION_NOTIFY 6
# define X11_DESTROY_NOTIFY 17

# define X11_NO_EVENT_MASK (0L)
# define X11_POINTER_MOTION_MASK (1L<<6)
# define X11_BUTTON_PRESS_MASK (1L<<2)
# define X11_BUTTON_RELEASE_MASK (1L<<3)
# define X11_KEY_PRESS_MASK (1L<<0)
# define X11_KEY_RELEASE_MASK (1L<<1)

# define KC_ESCAPE 53

# define KC_1 18
# define KC_2 19
# define KC_3 20
# define KC_4 21
# define KC_5 23
# define KC_6 22
# define KC_7 26
# define KC_8 28
# define KC_9 25
# define KC_0 29
# define KC_ADD 24
# define KC_SUBTRACT 27

# define KC_W 13
# define KC_S 1
# define KC_A 0
# define KC_D 2
# define KC_R 15
# define KC_L 37

# define KC_KP_0 82
# define KC_KP_1 83
# define KC_KP_2 84
# define KC_KP_3 85
# define KC_KP_4 86
# define KC_KP_5 87
# define KC_KP_6 88
# define KC_KP_7 89
# define KC_KP_8 91
# define KC_KP_9 92
# define KC_KP_ADD 69
# define KC_KP_SUBTRACT 78
# define KC_KP_MULTIPLY 67
# define KC_KP_DIVIDE 75

# define BC_LEFT 1
# define BC_RIGHT 2
# define BC_WHEEL_DOWN 4
# define BC_WHEEL_UP 5

#endif
