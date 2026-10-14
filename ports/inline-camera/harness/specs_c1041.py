"""specs_c1041.py - camera batch 1041: ZCAMERA::FindCurrentRoom."""
from pilot import S
from camgen import rnd, Log


def _find_room(c):
    log = Log(c)
    r = c.rng
    rooms = rnd(c, 0x40)
    count = r.choice([0, 1, 1, 2, 3, 4])
    ids = [0x1000 + k * 0x11 for k in range(5)]
    for i in range(count):
        c.emu.w32(rooms + 4 * i, r.choice(ids))
    cur = r.choice(ids + [0])

    def room_now(e, res):
        log.put(0x288)
        e.ret(eax=cur, argbytes=0)

    cam = rnd(c, 0x200)
    c.emu.w32(cam, c.emu.fake_vtable('cam', 0x290 // 4, {0x288: room_now}))
    c.emu.w32(cam + 0x18, r.choice(ids + [0, 0]))
    return [cam, rooms, count]


S(0x445d50, 'ZCAMERA::FindCurrentRoom', 'thiscall', gen=_find_room)
