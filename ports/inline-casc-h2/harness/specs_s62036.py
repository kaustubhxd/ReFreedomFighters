from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    get_count = r.choice([0, 0xffffffff, 1, 5, 0x100])
    existing_count = r.choice([0, 0, 0, 7])
    existing_buf = r.choice([0, 0, rnd(c, 0x100)])
    slot = pystub(c, 0, this=True, ret=get_count, side=lambda emu,k: emu.calllog.append(('count',)))
    setter = pystub(c, 2, this=True, side=lambda emu,k: emu.calllog.append(('set', emu.arg32(0), emu.arg32(1))))
    me = obj(c, 0xb00, {0x218: slot, 0x21c: setter}, nslots=0x21c//4+1)
    e.w32(me + 0xaf8, existing_count)
    e.w32(me + 0xafc, existing_buf)
    raw = rnd(c, 0x1000)
    hook_rec(c, 0x41e290, 1, pop=0, ret=raw, side=lambda emu,k: emu.calllog.append(('alloc', emu.arg32(0))))
    return [me]

S(0x492820, 'GUESS lazily allocate and initialize cached buffer', 'thiscall', None, ret=None, gen=gen, note='batch62036')
