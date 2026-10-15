from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    slot64 = pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True)
    slot68 = pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True)
    slot3c = pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True)
    state = obj(c, 0x100, {0x64: slot64, 0x68: slot68, 0x3c: slot3c})
    e.w8(state + 0x5e, r.choice([0, 0, 1]))
    e.wf32(state + 0x4a, c.fv(-5, 5, edge=0.01))
    match_code = r.getrandbits(16)
    e.w16(state + 0x48, match_code)
    e.w32(state + 0x56, r.getrandbits(32))
    payload_call = pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True)
    payload = obj(c, 0x40, {0x2c: payload_call})
    e.w32(state + 0x44, payload)

    d8 = pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True)
    target = obj(c, 0x200, {0xd8: d8})
    factory = rnd(c, 0x40)
    e.w32(factory + 0x18, target)
    so = sysobj(c)
    e.w32(so + 0x1aa3, factory)
    e.w32(so + 0x40, r.getrandbits(32))

    special = r.choice([0x401, 0x400, 0x222, 0x333, 0x444])
    global_code = r.choice([0x333, 0x888])
    e.w16(0x7002f8, global_code)
    code = special
    if special == 0x222:
        code = match_code
    elif special == 0x333 and r.randrange(2):
        code = global_code
    return [state, code, r.getrandbits(32)]


S(0x4a48e0, 'GUESS_handle_state_code_and_global_object', 'thiscall', None,
  ret='eax', gen=gen, note='batch102003')
