from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    e = c.emu
    r = c.rng

    # The formatter fills the caller's local buffer. Keep its two input values
    # observable in the recorder while using identical deterministic text on
    # both sides of the differential run.
    def format_text(emu, call_no):
        emu.wbytes(emu.arg32(0), b"h2 formatted record\0")

    hook_rec(c, 0x42abee, 5, ret=0, pop=0, side=format_text, stackmark={0})
    slot68 = pystub(c, 3, ret=r.getrandbits(32), pop=12,
                    this=True, deref={1: 64})
    global_obj = obj(c, 0x80, {0x68: slot68})
    e.w32(0x700394, global_obj)
    e.w32(0x6fd440, r.choice([0, 0, 1, 1]))
    e.w32(0x6f5630, r.getrandbits(32))
    hook_rec(c, 0x633654, 0, pop=0, this=True,
             side=lambda em, k: em.calllog.append(('cookie-check', em.reg('ecx'))))
    return [r.getrandbits(32), r.getrandbits(32)]


S(0x421870, 'GUESS_format_record_and_log', 'cdecl', None, ret=None, gen=gen,
  note='batch102000')
