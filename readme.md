<p><strong><!-- #######  THIS IS A COMMENT - Visible only in the source editor #########--></strong></p>
<h2><strong>Run under Ubuntu. Be sure to install the library Xlib.h</strong></h2>
<h2><strong>$sudo apt install libx11-dev</strong></h2>
<p>&nbsp;</p>
<h2 id="tw-target-text" class="tw-data-text tw-text-large tw-ta" dir="ltr" data-placeholder="Translation"><strong><span class="Y2IQFc" lang="en">TODO:</span></strong></h2>
<table style="height: 374px; width: 819px;">
<tbody>
<tr>
<td style="width: 469.344px;">
<p class="p1"><strong>Системные требования</strong></p>
<p class="p1"><strong>Целевая ОС - на усмотрение (Windows, Linux)</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><strong><span style="color: #ff0000;">Linux</span></strong></td>
</tr>
<tr>
<td style="width: 469.344px;">
<p class="p2"><strong>Система сборки - CMake</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;">
<p class="p1"><strong><span style="color: #ff0000;">cmake_minimum_required</span></strong></p>
<p class="p1"><strong><span style="color: #ff0000;">(<span class="s1">VERSION 3.23</span>)</span></strong></p>
<strong><span style="color: #ff0000;">&nbsp;</span></strong></td>
</tr>
<tr>
<td style="width: 469.344px;">
<p class="p2"><strong>Использование сторонних библиотек запрещено - только стандартная библиотека C++/STL. Разрешается использовать библиотеки платформы</strong></p>
<p class="p2"><strong>для отрисовки содержимого, а так же тестирования</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;">
<p><strong><span style="color: #ff0000;">&nbsp;Использовалась библиотека Xlib.h</span></strong></p>
<p><strong><span style="color: #ff0000;">для устанвки на Ubuntu</span></strong></p>
<p><strong><span style="color: #ff0000;">sudo apt install libx11-dev</span></strong></p>
</td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p1"><strong>Требования к коду</strong></p>
<p class="p2"><strong>Обязательно соблюдение <span class="s1">coding-style</span></strong></p>
<p class="p2"><strong>Использование системы контроля версий обязательно (предпочтительно - Git)</strong></p>
<p class="p2"><strong>Публикация кода должна происходить на <span class="s1">GitHub </span>репозиторий. В случае использования приватного репозитория, необходимо дополнительно</strong></p>
<p class="p2"><strong>сообщить об этом - будут выданны аккаунты, которым нужно открыть доступ на просмотр кода.</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;">
<p><strong>&nbsp;</strong></p>
<p><strong>&nbsp;</strong></p>
</td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p1"><strong>Требования к тестированию</strong></p>
<p class="p2"><strong>Код должен быть покрыт юнит-тестами. Фреймворк для тестирования - на усмотрение, рекомендуется использовать Google Test/Mock</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;">
<h1><span style="color: #ff00ff;"><strong>В процессе&nbsp;</strong></span></h1>
</td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p1"><strong>Функциональные требования</strong></p>
<p class="p2"><strong>При запуске приложения необходимо показывать меню с возможностью выбора действий</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;" colspan="2">
<pre class="chroma" tabindex="0"><code class="language-html" data-lang="html"><span class="p">&lt;</span><span class="nt">div</span> <span class="na">style</span><span class="o">=</span><span class="s">"width:160px ; height:160px"</span><span class="p">&gt;</span>
![Main Menu](/img/1.png?raw=true "Main Menu")
<span class="p">&lt;</span><span class="nt">div</span><span class="p">&gt;</span></code></pre>
</td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Элементы - Новая игра, Выйти из игры (обязательно), прочие элементы меню (могут добавляться по ходу реализации нового функционала)</strong></p>
<p class="p2"><strong>Управление в игре реализовать способом ввода данных через нажатие клавиш - стрелками или клавишами WASD (W - вверх, S - вниз, A - влево, D -</strong></p>
<p class="p2"><strong>вправо)</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>При выборе опции "Выйти из игры" приложение завершает работу</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>Выполнено&nbsp;</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>При выборе "Новая игра", отрисовывается игровое поле с игровыми элементами, но игра не начинается сразу, а через 3 секунды, чтобы дать</strong></p>
<p class="p2"><strong>игроку приготовиться</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено(старт после нажатия...)</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Необходимо показывать таймер с оставшимся временем до начала игры</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;">
<h2><strong><span style="color: #ff00ff;">Отсутствует</span>&nbsp;</strong></h2>
</td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>На игровом поле должны присутсвовать блоки, стены поля, шарик, и платформа, а также кол-во оставшихся жизней, время с начала игры, и</strong></p>
<p class="p2"><strong>счётчик очков</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Расположение элементов на поле: блоки в верхней части, платформа в нижней части, стены ограничивают поле в форме прямоугольника (или</strong></p>
<p class="p2"><strong>квадрата)</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;" colspan="2">
<p>&nbsp;![alt text](https://github.com/C0nstanta/Breakout_game/blob/master/img/2.png?raw=true)</p>
</td>
</tr>
<tr>
<td style="width: 469.344px;">
<p class="p2"><strong>Должно присутсвовать 3 разновидности блоков - разрущающиеся при 1, 2 и 3 попаданиями по блоку соответсвенно</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
<strong>&nbsp;</strong></td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>За разрушение разных видов блоков начисляется разное количество очков (конкретные значения на усмотрение)</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Разновидности блоков должны отображаться на поле по-разному</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>При старте игры мячик начинает движение от середины поля вниз на платформу</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Платформа может перемещаться только вправо и влево (при нажатии соответсвующих клавиш)</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>Выполнено&nbsp;</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;">
<p class="p2"><strong>При попадании в блок мячик должен отлетать от него</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>При попадании в платформу мячик должен отлетать от неё</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>В начале игры у игрока должно быть 3 жизни</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>Выполнено&nbsp;</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Если мячик не был отражён платформой, игрок лишается 1 жизни. При потери всех жизней, игра заканчивается поражением (показывается</strong></p>
<p class="p2"><strong>соответсвующее сообщение с количеством набраных очков)</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>Выполнено&nbsp;</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;" colspan="2">&nbsp;
<pre>![alt text](https://github.com/C0nstanta/Breakout_game/blob/master/img/3.png?raw=true)<code></code></pre>
</td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Если были сбиты все блоки, игра заканчивается победой (показывается соответсвующее сообщение с количеством набраных очков)</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>При окончании игры игроку показывается стартовое меню</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><span style="color: #ff0000;"><strong>&nbsp;Выполнено</strong></span></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p1"><strong>Необязательные функциональные требования</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><strong>&nbsp;Отсутствует</strong></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Вести статистику игр - добавить пункт меню "Статистика", в котором будут отображаться дата и время игры, статус (победа или поражение) и кол-</strong></p>
<p class="p2"><strong>во набраных очков</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><strong>&nbsp;Отсутствует&nbsp;</strong></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Каждая рановидность блоков отражает мяч при попадании на него по-разному</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><strong>&nbsp;&nbsp;Отсутствует</strong></td>
</tr>
<tr>
<td style="width: 469.344px;"><strong>&nbsp;</strong>
<p class="p2"><strong>Игра должна состоять из нескольких уровней, на которых случайным или специальным образом расположены блоки (количество и</strong></p>
<p class="p2"><strong>разновидность блоков также разная). При завершении уровня победой происходит переход на следующий уровень с восстановлением</strong></p>
<p class="p2"><strong>количества жизней. При поражении игра заканчивается. Количество уровней не регламентировано</strong></p>
<p class="p2"><strong>&nbsp;</strong></p>
</td>
<td style="width: 10px;"><strong>&nbsp;&nbsp;Отсутствует</strong></td>
</tr>
<tr>
<td style="width: 469.344px;">&nbsp;</td>
<td style="width: 10px;">&nbsp;</td>
</tr>
</tbody>
</table>
