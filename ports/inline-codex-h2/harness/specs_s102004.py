from pilot import S
from recruits_util import obj, sysobj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    slot250 = pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True)
    slotbc = pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True)
    channel = obj(c, 0x300, {0x250: slot250, 0xbc: slotbc})
    state_obj = obj(c, 0x100, {})
    e.w32(state_obj + 0x44, channel)
    mode = r.choice([0, 1, 2, 3])
    start = r.randint(5, 10000)
    progress = start + r.randint(1, 5000)
    above = r.choice([False, True])
    current = progress + r.randint(1, 5000) if above else start + r.randint(0, progress - start)
    e.w32(state_obj + 0x54, progress)
    e.w32(state_obj + 0x58, start)
    e.w32(state_obj + 0x5c, mode)
    so = sysobj(c)
    e.w32(so + 0x40, current)
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0))
    return [state_obj]


S(0x5d6e90, 'GUESS_update_timed_channel_progress', 'thiscall', None,
  ret=None, gen=gen, note='batch102004')
